#include<iostream>
using namespace std;
struct node{
	int fir=0;
	int data;
	node *next;
};
class coin{
	private:
		node *park[10010];
		int vernum[10010];
		int visit[10010];
		int num=0;
	public:
		coin(int n){
			for(int i=0;i<10010;i++){
				park[i]=NULL;
				vernum[i]=0;
				visit[i]=0;
			}
			num=n;
		}
		void readin();
		void add(int first,int last);
		int DFS(int pos,int & ans,int &to);
		void print();
};
int main(){
	int ver;
	scanf("%d",&ver);
	coin n(ver);
	n.readin();
	int ans=0,to=0;
	cout<<n.DFS(1,ans,to);
	//n.print();
	
	return 0;
}
void coin::readin(){
	int i;
	for(i=1;i<=num;i++){
		scanf("%d",&vernum[i]);
	}
	int first,last;
	for(i=0;i<num-1;i++){
		scanf("%d%d",&first,&last);
		add(first,last);
		add(last,first);
	}
}
void coin::add(int first,int last){
	if(park[first]==NULL){
		park[first]= new node;
		park[first]->data=last;
		park[first]->next=NULL;
	}
	else{
		node* tmp= park[first];
		park[first]=new node;
		park[first]->data=last;
		park[first]->next=tmp;		
	}	
}
int coin::DFS(int pos,int & ans,int &to){
	if(park[1]==NULL)return vernum[1];
	to+=vernum[pos];
	visit[pos]=1;
	node* tmp=park[pos];
	while(tmp){
		if(visit[tmp->data]==0){
			DFS(tmp->data,ans,to);
			tmp=tmp->next;
		}
		else{
			tmp=tmp->next;
		}	
	}
	visit[pos]=2;
	ans=max(to,ans);
	to-=vernum[pos];	
	return ans;	
}


void coin::print(){
	for(int i=0;i<=num;i++){
		if(park[i]!=NULL){
			cout<<i<<"--";
			node *tmp=park[i];
			while(tmp){
				cout<<tmp->data<<" ";
				tmp=tmp->next;
			}
			cout<<endl;
		}
	}
}
