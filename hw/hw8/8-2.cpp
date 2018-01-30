#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int i,j;
		int n;
		cin>>n;
		bool xr[n][1024];
		int in[3*n];
		for(i=0;i<n;i++){
			for(j=0;j<1024;j++){
				xr[i][j]=false;
			}
		}		
		for(i=0;i<3*n;i++)cin>>in[i];
		//for(i=0;i<3*n;i++)cout<<in[i]<<" ";
		for(i=0;i<3;i++)xr[0][in[i]]=true;
		int ans=0;
		
		for(i=3;i<3*n;i++){
			for(j=0;j<1024;j++){
				if(xr[i/3-1][j]==true){
					xr[i/3][j xor in[i]]=true;
					if(i/3==n-1){
						ans=max(ans,j xor in[i]);
					}
				}
			}
		}
		cout<<ans<<endl;				
		//cout<<endl;
	}
	return 0;
}
