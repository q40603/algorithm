#include<iostream>
#include<cstring>
using namespace std;
void max_heapify(int *a,int i,int n){
	int larg=0;
	int left=2*i;
	int right=2*i+1;
	if(left<=n && a[left]>a[i]){
		larg = left;
	}
	else{
		larg = i;
	}
	if(right<=n && a[right]> a[larg] ){
		larg = right;
	}
	if( larg!=i){
		int tmp=a[larg];
		a[larg]=a[i];
		a[i]=tmp;
		max_heapify(a,larg,n);
	}
	
}
void buildmaxheap(int *a,int n){
	int i=0;
	for(i=n/2;i>=1;i--){
		max_heapify(a,i,n);
	}
}
void heapsort(int *a,int n){
	buildmaxheap(a,n);
	int i;
	for(i=n;i>=2;i--){
		int tmp=a[1];
		a[1]=a[i];
		a[i]=tmp;	
		n-=1;
		max_heapify(a,1,n);
	}
}
int main(){
	int num;
	cin>>num;
	int heap[num+1];	
	memset(heap,0,num+1);
	int i;
	for(i=1;i<num+1;i++){
		cin>>heap[i];
	}
	buildmaxheap(heap,num);	
	for(i=1;i<num+1;i++){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
    heapsort(heap,num);
   	for(i=1;i<num+1;i++){
		cout<<heap[i]<<" ";
	} 

		
	return 0;
}
