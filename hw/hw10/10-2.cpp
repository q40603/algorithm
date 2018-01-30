#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef struct node{
	int data=0;
	node *next;
	int finish=0;
}node;
typedef struct in{
	int in=0;
	int finish_time=0;
}in;
class origin{
	private:
		int visit[10010];
		int visit_t[10010];
		in finish[10010];
		in finish_t[10010];
		int dir_num=0;
		int vertices=0;
		int less=0;
		int grn[10010];
	public:
		node *group[10010];
		node *ver[10010];
		node *ver_t[10010];
		origin(int a,int b){
			for(int i=0;i<10010;i++){
				ver[i]=NULL;
				visit[i]=0;
				ver_t[i]=NULL;
				visit_t[i]=0;
				group[i]=NULL;
				grn[10010]=0;
			}
			dir_num=b;
			vertices=a;
		}
		~origin(){};
		void add(int first,int last,node *a[]);
		void traverseall();
		void DFS(int pos,int &ans);
		void quicksort(in *a,int p,int r);
		int partion(in *a,int p,int r);
		int traverseall_t();
		void DFS_t(int pos,int &ans,int);
		int traverse_gr(int gr);
		int bfs_gr(int pos,int gr);
		void print(node **a);
};
int main(){
	int time;
	scanf("%d",&time);
	while(time--){
		int vertices, dir_num;
		scanf("%d%d",&vertices,&dir_num);
		origin n(vertices,dir_num);
		for(int i=0;i<dir_num;i++){
			int first,last;
			scanf("%d%d",&first,&last);
			n.add(first,last,n.ver);
			n.add(last,first,n.ver_t);			
		}
		n.traverseall();
		//n.print(n.ver);
		//cout<<endl;
		//n.print(n.ver_t);
		
		
		cout<<n.traverse_gr(n.traverseall_t())<<endl;
		//cout<<"GROUP"<<endl;
		//n.print(n.group);
	}
	return 0;
}
void origin::add(int first,int last,node*a[]){
	if(a[first]==NULL){
		a[first]= new node;
		a[first]->data=last;
		a[first]->next=NULL;
	}
	else{
		node* tmp= a[first];
		a[first]=new node;
		a[first]->data=last;
		a[first]->next=tmp;		
	}	
}

void origin::traverseall(){
	int ans=0,i;
	for(i=1;i<=vertices;i++){
		if(ver[i]!=NULL&&visit[i]==0){
			int time=0;
			DFS(i,time);
		}
	}
	quicksort(finish,1,vertices);

}
int origin::traverseall_t(){
	int ans=0,i;
	for(i=vertices;i>0;i--){
		if(ver_t[i]==NULL&&ver[i]==NULL)less=-1;
		else if(visit_t[finish[i].in]==0) {
			ans++;
			int time=0;
			//cout<<"(";
			DFS_t(finish[i].in,time,ans);
			//cout<<")"<<endl;
		}
	}
	return ans;
}
void origin::DFS(int pos,int & time){
	visit[pos]=1;
	time++;
	node* tmp=ver[pos];
	while(tmp){
		if(visit[tmp->data]==0){
			DFS(tmp->data,time);
			tmp=tmp->next;
		}
		else{
			tmp=tmp->next;
		}	
	}	
	visit[pos]=2;
	finish[pos].finish_time=++time;
	finish[pos].in=pos;
}
void origin::DFS_t(int pos,int & time,int ans){
	visit_t[pos]=1;
	time++;
	node* tmp=ver_t[pos];
	while(tmp){
		if(visit_t[tmp->data]==0&&ver_t[tmp->data]!=NULL){
			DFS_t(tmp->data,time,ans);
			tmp=tmp->next;
		}
		else{
			tmp=tmp->next;
		}	
	}	
	visit_t[pos]=2;
	finish_t[pos].finish_time=++time;
	finish_t[pos].in=pos;
	add(ans,pos,group);
	grn[pos]=ans;
	//cout<<pos<<" ";
}
int origin::partion(in *a,int p,int r){
	int x=a[r].finish_time;
	int i=p-1;
	for(int j=p;j<r;j++){
		if(a[j].finish_time<=x){
			i++;
			if(i!=j){
				in tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;			
			}	
		}
	}
	in tp=a[i+1];
	a[i+1]=a[r];
	a[r]=tp;
	return i+1;
}
void origin::quicksort(in *a,int p,int r){
	if(p<r){
		int q=partion(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r); 
	}	
}
int origin::traverse_gr(int gr){
	int ans=0;
	if(less==-1)return 0;
	else{
		for(int i=1;i<=gr;i++){
			ans+=bfs_gr(i,gr);
		}
		return ans;		
	}
} 
int origin::bfs_gr(int pos,int gr){
	bool vs[vertices+1];
	bool vsgr[gr+1];
	memset(vs,false,vertices+1);
	memset(vsgr,false,gr+1);
	queue<int> q;
	int count=1,ans=0;
	node *tmp=group[pos];
	vsgr[grn[tmp->data]]=true;
	while(tmp){
		q.push(tmp->data);
		vs[tmp->data]=true;
		tmp=tmp->next;
		ans++;
	}
	while(!q.empty()){
		
		int i=q.front();
		q.pop();
		node *t=ver[i];
		while(t){
			if(!vs[t->data]){
				if(vsgr[grn[t->data]]==false)count++;
				q.push(t->data);
				vs[t->data]=true;
				vsgr[grn[t->data]]=true;
				t=t->next;
			}
			else{
				t=t->next;
			}
		}
	}
	if(count==gr)return ans;
	else{
		return 0;
	}
}
void origin::print(node **a){
	for(int i=1;i<=vertices;i++){
		if(a[i]!=NULL){
			node *tmp=a[i];
			cout<<i<<"-";
			while(tmp){
				cout<<tmp->data<<"¡@";
				tmp=tmp->next;
			}
			cout<<endl;
		}

	}
}
