#include<iostream>
#include<cstring>
#include<queue>
#include<bits/stdc++.h> 
using namespace std;
typedef struct con{
	int first=0;
	int last=0;
	long double weight=0;
	int ith=0;
}con;
bool cmp(con e1, con e2)	{ return e1.weight < e2.weight; }
int partion(int *a,int p,int r){
	int x=a[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(a[j]<=x){
			i++;
			if(i!=j){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;			
			}	
		}
	}
	int tp=a[i+1];
	a[i+1]=a[r];
	a[r]=tp;

	return i+1;
	
}
void quicksort(int * a,int p,int r){
	if(p<r){
		//cout<<"ggg";
		int q=partion(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r); 
	}
}
class mst{
	private:
		int ver_num,edg_num;
	public:
		con increase[1000005];
		int *br;
		int ans[1000005];
		vector<int> ppp[10001];
		mst(int a,int b){
			ver_num=a;
			edg_num=b;
			br=new int[a];
			for(int i=0;i<1000005;i++){
				ans[i]=0;
			}
		};
		void Kruskal();
		void uni(int x, int y) {br[find(x)] = find(y);}
		int find(int x) {return x == br[x] ? x : (br[x] = find(br[x]));}
		void readin_increase(int,int,int,int);
		void print_incr();
};

int main(){
	int ver_num,edg_num,first,last,weight;
	scanf("%d %d", &ver_num, &edg_num);
	int test_case = edg_num;
	mst g(ver_num,edg_num);
	for(int i=0;i<edg_num;i++){
		scanf("%d%d%d",&first,&last,&weight);
		g.readin_increase(i,first,last,weight);
	}
	sort(g.increase, g.increase+edg_num, cmp);
	g.Kruskal();
	g.print_incr();
	return 0;
}
void mst::Kruskal(){
	int i, j, k;
	int trace[edg_num];
	for(int i=0;i<ver_num;i++)br[i]=i;
	for (int l = 0; l < edg_num; l ++)	trace[l] = 1;
	for (j = 0 ; j < edg_num;)
	{	
		queue<int> n;
		if (find(increase[j].first) != find(increase[j].last)) {
			n.push(j);
		}
		while (1)
		{
			if (increase[j].weight == increase[j+1].weight)
			{  
				if (find(increase[j+1].first) != find(increase[j+1].last)) 
					n.push(j+1);
				j ++;
			}
			else break;	
		}
		while(!n.empty()){
			int o=n.front();
			n.pop();
			uni(increase[o].first, increase[o].last);
			ans[increase[o].ith] = 1;
			ppp[increase[o].first+1].push_back(increase[o].last+1);
		}
		j++;
	}	
}
void mst::readin_increase(int i,int fir,int la,int wei){
	increase[i].first=fir-1;
	increase[i].last=la-1;
	increase[i].weight=log2(wei+100000);
	increase[i].ith=i;
}
void mst::print_incr(){
	for(int i=1;i<=ver_num;i++){
		int l=ppp[i].size();
		int cc[l];
		for(int j=0;j<l;j++){
			//cout<<i<<" "<<ppp[i][j]<<endl;
			cc[j]=ppp[i][j];
		}
		quicksort(cc,0,l-1);
		for(int j=0;j<l;j++){
			cout<<i<<" "<<cc[j]<<endl;
		}
	}
}
/*
4 6
1 2 6
1 3 3
1 4 5
2 3 2
2 4 4
3 4 1
*/
