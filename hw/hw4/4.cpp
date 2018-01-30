#include<iostream>
#include<stdio.h>
#define max 10007
using namespace std;
struct node{
	long long int value;
	node *next;		
	int times=1;	
};
class hashtable{
	private:
		node* hash[max];
	public:
		long long int b=0;
		hashtable(){
			for(int i=0;i<max;i++){
				hash[i]=NULL;
			}
		};
		~hashtable(){};
	 	void add(long long int n,long long int k);
	 	int checknode(long long int n,long long int k);
		void print();
		void pair(long long int n,long long int k);	
		int search(long long int n,long long int p);
	 	//bool isEmpty(int k) const { return root==NULL; }
};
int main(){
	int T;
	cin>>T;
	while(T--){
		int i;
		long long int n,k;
		cin>>n>>k;
		hashtable a;
		for(i=0;i<n;i++){
			long long int n;
			scanf("%lld",&n);
			a.add(n,k);
		}
		cout<<a.b<<endl;
		/*node* tr= new node;
		tr=a.hash[0];
		cout<<tr->value<<endl;
		tr=tr->next;
		cout<<tr->value;*/
		//a.print();
	}
	
	return 0;
} 
void hashtable::add(long long int k,long long int sum){
	b+=checknode(k,sum);
	long long int pos=0;
	if(k<0){
		pos=k%max*-1;
	}
	else{
		pos=k%max;
	}

	if(hash[pos]==NULL){
		hash[pos]= new node;
		hash[pos]->value=k;
		//cout<<"("<<k%max<<")"<<hash[k%max]->value<<"--";
		hash[pos]->next=NULL;
	}
	else{
		int ans=search(k,pos);
		if(ans==0){
			node* tmp= hash[pos];
			hash[pos]=new node;
			hash[pos]->value=k;
			hash[pos]->next=tmp;				
		}
		//cout<<"("<<k%max<<")"<<hash[k%max]->value<<"--";
	}
}
int hashtable::search(long long int n,long long int p){
	node* se=hash[p];
	int a=0;
	while(se!=NULL){
		if(se->value==n){
			se->times++;
			a=1;
			break;
		}
		else{
			se=se->next;
		}
	}
	return a;
}
void hashtable::print(){
	int i;
	for(i=0;i<max;i++){
		if(hash[i]!=NULL){
			node* tr=hash[i];
			while(tr!=NULL){
				//cout<<tr->value<<" ";
				tr=tr->next;
			}
			cout<<"haha";
			cout<<endl;
		}
	}
}
int hashtable::checknode(long long int n,long long int k){
	int count=0;
	long long int pair=0;
	if(k-n<0){
		pair=(k-n)%max*-1;
	}
	else{
		pair=(k-n)%max;
	}
	
	//cout<<"   "<<pair<<endl;
	
	node* tr= hash[pair];
	while(tr!=NULL){
		if(tr->value+n==k){
			count+=tr->times;
			//cout<<tr->value<<"  checked"<<endl;
			tr=tr->next;
		}
		else{
			tr=tr->next;
		}
	}
	return count;
}
/*void hashtable::pair(int n,long long int k){
	int i,c=0;
	for(i=0;i<max;i++){
		
	}
}*/
