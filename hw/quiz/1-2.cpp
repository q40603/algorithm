#include<iostream>
#include<cstring>
#include<queue>
#include<bits/stdc++.h> 
using namespace std;
typedef struct con{
	int first=0;
	int last=0;
	int weight=0;
	int abw=0;
	int ith=0;
}con;
bool cmp1(con e1, con e2){ 
	return e1.weight<e2.weight;
}
class mst{
	private:
		int ver_num,edg_num;
	public:
		con *increase;
		int *br;
		int *ans;
		mst(int a,int b){
			increase=new con[b+1];
			ans=new int[b+1];
			ver_num=a;
			edg_num=b;
			br=new int[a];
			for(int i=0;i<b+1;i++){
				ans[i]=0;
			}
		};
		int Kruskal();
		void uni(int x, int y) {br[find(x)] = find(y);}
		int find(int x) {return x == br[x] ? x : (br[x] = find(br[x]));}
		void readin_increase(int,int,int,int);
		void print_incr();
		void rewrite();
		int ab(int a);
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
	/*for(int i=0;i<edg_num;i++){
		cout<<i<<"."<<g.increase[i].weight<<" ";
	}
	cout<<endl;	
	sort(g.increase, g.increase+edg_num, cmp1);
	for(int i=0;i<edg_num;i++){
		cout<<g.increase[i].first<<" "<<g.increase[i].last<<"¡@"<<g.increase[i].weight<<endl;
	}*/
	g.rewrite();
	cout<<g.Kruskal();
	//g.print_incr();
	return 0;
}
int mst::ab(int a){
	if(a>=0)return a;
	else{
		return -a;
	}
}
void mst::rewrite(){
	sort(increase, increase+edg_num, cmp1);
	int me=increase[edg_num/2].weight;
	//cout<<" **** "<<me<<endl;
	for(int i=0;i<edg_num;i++){
		increase[i].weight-=me;
		increase[i].weight=ab(increase[i].weight);
	}
}
int mst::Kruskal(){
	sort(increase, increase+edg_num, cmp1);
	int total=0;
	int i, j, k;
	for(int i=0;i<ver_num;i++)br[i]=i;
	for (int j =0 ; j < edg_num;)
	{	
		if (find(increase[j].first) != find(increase[j].last)) {
			uni(increase[j].first, increase[j].last);
			total=max(total,ab(increase[j].weight));
			ans[increase[j].ith] = 1;
			//cout<<increase[j].first<<" "<<increase[j].last<<"¡@"<<increase[j].weight<<endl;
		}	
		j++;
	}	
	return total;
}
void mst::readin_increase(int i,int fir,int la,int wei){
	increase[i].first=fir-1;
	increase[i].last=la-1;
	increase[i].weight=wei;
	increase[i].ith=i;
}
void mst::print_incr(){
	int a=0;
	for(int i=0;i<edg_num;i++){
		if(ans[i]==true){
			a+=increase[i].weight;
			cout<<i<<". "<<increase[i].weight;
		}
	}
	cout<<endl<<a<<endl;
}
/*
4 5
1 2 -1
1 3 2
2 3 -2
3 4 1
2 4 0
*/
