#include<iostream>
#include<string.h>
using namespace std;
int partion(long long int *a,int p,int &r,int &b){
	long long int x=a[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(a[j]<=x){
			i++;
			if(i!=j){
				long long int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;			
			}	
		}
	}
	long long int tp=a[i+1];
	a[i+1]=a[r];
	a[r]=tp;
	//cout<<i+1<<"--";
	b++;
	return i+1;
	
}
void quicksort(long long int *a,int p,int r,int &b){
	if(p<r){
		int q=partion(a,p,r,b);
		quicksort(a,p,q-1,b);
		quicksort(a,q+1,r,b); 
	}
}
int main(){
	int times;
	cin>>times;
	while(times--){
		int num,i,b=0;
		cin>>num;
		//cout<<num<<endl;
		long long int qs[num]; 
		for(i=0;i<num;i++){
			cin>>qs[i];
		}
		quicksort(qs,0,num-1,b);
		//cout<<endl;
		//cout<<"        "<<b<<endl; 
		if(b==num-1)cout<<"Yes"<<endl;
		else{
			cout<<"No"<<endl;
		}
		for(i=0;i<num;i++){
			cout<<qs[i]<<" ";
		}		
		cout<<endl;
		
		
	}
	return 0;
}
