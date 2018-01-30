#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int data=0;
	node *next=NULL;
};
class BFS{
	private:
		node *town[30010];
		bool visit[30010];
		int people=0;
	public:
		BFS(int n){
			for(int i=0;i<30010;i++){
				town[i]=NULL;
				visit[i]=false;
			}
			people=n;
		}
		~BFS(){};
		void add(int first,int last);
		void print();
		int check(int first,int last);
		int traverse_bfs(int v);
		int traverse_dfs(int v);
		int traverseall();
};
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int people,pair,first,last;
	//cin>>people>>pair;
	scanf("%d",&people);
	scanf("%d",&pair);
	BFS n(people);
	while(pair--){
		scanf("%d",&first);
		scanf("%d",&last);
		n.add(first,last);
		n.add(last,first);
	}
	cout<<n.traverseall()+1<<endl;
	//n.print();
	return 0;
}
int BFS::traverse_bfs(int v){
	visit[v]=true;
	queue<int> q;
	int count=0;
	node *tmp=town[v];
	while(tmp){
		q.push(tmp->data);
		visit[tmp->data]=true;
		tmp=tmp->next;
		count++;
	}
	while(!q.empty()){
		int i=q.front();
		q.pop();
		node *t=town[i];
		while(t){
			if(!visit[t->data]){
				q.push(t->data);
				visit[t->data]=true;
				count++;
				t=t->next;
			}
			else{
				t=t->next;
			}
		}
	}
	return count;
}
int BFS::traverseall(){
	int ans=0;
	for(int i=1;i<=people;i++){
		if(town[i]!=NULL&&visit[i]==false){
			int tmp=traverse_bfs(i);
			ans=max(ans,tmp);
		}
	}
	return ans;
}
int BFS::check(int first,int last){
	node* tmp=town[first];
	while(tmp){
		if(tmp->data==last){
			return 1;
		}
		else{
			tmp=tmp->next;
		}
	}
	return 0;
} 
void BFS::add(int first,int last){
	if(town[first]==NULL){
		town[first]= new node;
		town[first]->data=last;
		town[first]->next=NULL;
	}
	else{
		
			node* tmp= town[first];
			town[first]=new node;
			town[first]->data=last;
			town[first]->next=tmp;	
			
	}
}
void BFS::print(){
	for(int i=0;i<=people;i++){
		if(town[i]!=NULL){
			cout<<i<<"--";
			node *tmp=town[i];
			while(tmp){
				cout<<tmp->data<<" ";
				tmp=tmp->next;
			}
			cout<<endl;
		}
	}
}
