#include<iostream>
#include<cstring>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
typedef struct con{
	int first=0;
	int last=0;
	int weight=0;
	int ith=0;
}con;
bool cmp(con e1, con e2)	{ return e1.weight < e2.weight; }
class mst{
	private:
		int ver_num,edg_num;
	public:
		con increase[100005];
		int *br;
		int ans[100005];
		mst(int a,int b){
			ver_num=a;
			edg_num=b;
			br=new int[a];
			//ans= new int[b];
			//increase = new con[b];
			for(int i=0;i<100005;i++){
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
	mst g(ver_num,edg_num);
	for(int i=0;i<edg_num;i++){
		scanf("%d%d%d",&first,&last,&weight);
		if (first > last)	swap(first,last);
		g.readin_increase(i,first,last,weight);
	}
	sort(g.increase, g.increase+edg_num, cmp);
	g.Kruskal();
	g.print_incr();
	return 0;
}
void mst::Kruskal(){
	int  j;

	for(int i=0;i<ver_num;i++)br[i]=i;
	for (j = 0 ; j < edg_num;)
	{	queue<int> n;
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
		}
		j++;
	}
}
void mst::readin_increase(int i,int fir,int la,int wei){
	increase[i].first=fir-1;
	increase[i].last=la-1;
	increase[i].weight=wei;
	increase[i].ith=i;
}
void mst::print_incr(){
	for(int i=0;i<edg_num;i++){
		if(ans[i]==true){
			cout<<"at least one"<<endl;
		}
		else{
			cout<<"none"<<endl;
		}
	}
}
