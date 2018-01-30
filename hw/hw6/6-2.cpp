#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long int t;
	scanf("%d",&t);
	//cin>>t;
	while(t--){
		long long int n,i,j;
		scanf("%d",&n);
		//cin>>n;
		long long int dr[n],co[n];
		for(i=0;i<n;i++){
			scanf("%lld",&dr[i]);
			//cin>>dr[i];
		}
		/*for(i=0;i<n;i++){
			printf("%lld ",dr[i]);
		}*/
		long long int count=0,tmp1=0,tmp2=0;
		co[0]=1;
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(dr[i]>=dr[j]){
					tmp1=max(tmp1,co[j]);
				}
			}
			co[i]=1+tmp1;
			tmp1=0;
			count=max(count,co[i]);
		}		
		cout<<count<<endl;
		
	}
	
	
	return 0;
}
