#include<iostream>
#include<stdlib.h>
#define ull unsigned long long int
using namespace std;
ull partition(ull  *a,int p,int r){
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
	return i+1;	
}
unsigned long long int quick_select(unsigned long long int* input, int p, int r, int k)
{
    if ( p == r ) return input[p];
    unsigned long long int j = partition(input, p, r);
    int length = j - p + 1;
    if ( length == k ) return input[j];
    else if ( k < length ) return quick_select(input, p, j - 1, k);
    else  return quick_select(input, j + 1, r, k - length);
}

int main(){
	int times;
	cin>>times;
	while(times--){
		unsigned long long int co[3],n,k;
		cin>>n>>k;
		for(int i=0;i<3;i++){
			cin>>co[i];
		}

		unsigned long long int se[n];
		//cout<<k<<endl;
		//n[0]=k;
		for(int i=1;i<=n;i++){
			unsigned long long int tmp=co[0]*i*i+co[1]*i+co[2];
			if(tmp>=1000000){
				tmp%=1000000;
				se[i-1]=tmp;
			}
			else{
				se[i-1]=tmp;
			}
		}
		//for(int i=0;i<n;i++)cout<<i+1<<". "<<se[i]<<endl;
		//cout<<endl;
		cout<<quick_select(se,0,n-1,k)<<endl;
	}
	
	return 0;
}
