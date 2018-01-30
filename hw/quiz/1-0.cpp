#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(){
	int len,i,j,a,d1=0,d2=0;
	bool d_1=false,d_2=false,yes=false;
	cin>>len;
	int n[len+2][len+2],ans[len+2][len+2];
	for(i=0;i<len+2;i++){
		for(j=0;j<len+2;j++){
			if(i==0||i==len+1||j==0||j==len+1){
				n[i][j]=-1;
			}
			else{
				cin>>n[i][j];
			}
			ans[i][j]=0;
		}
	}
	if(n[len][len]==n[1][1]+(2*len-2)*(n[len][len]-n[len-1][len])){
		d_1=true;
		d1=n[len][len]-n[len-1][len];
	}
	if(n[len][len]==n[1][1]+(2*len-2)*(n[len][len]-n[len][len-1])){
		d_2=true;
		d1=n[len][len]-n[len][len-1];
	}
	if(d_1==false&&d_2==false){
		cout<<"No";
		return 0;
	}
	//cout<<d1<<" "<<d2<<endl;
	if(d_1==true){
		ans[1][1]=1;
		for(i=1;i<=len;i++){
			if(n[i][1]+d1==n[i+1][1]&&ans[i][j]==1){
				ans[i+1][1]=1;
			}
			if(n[1][i]+d1==n[1][i+1]&&ans[i][j]==1){
				ans[1][i+1]=1;
			}			
		}
		for(i=1;i<=len;i++){
			for(j=1;j<=len;j++){
				if(n[i][j]+d1==n[i][j+1]&&ans[i][j]==1){
					ans[i][j+1]=1;
				}
				if(n[i][j]+d1==n[i+1][j]&&ans[i][j]==1){
					ans[i+1][j]=1;
				}				
			}
		}
	}
	if(ans[len][len]==1){
		cout<<"Yes";
		return 0;
	}
	memset(ans,0,sizeof(ans));
	if(d_2==true){
		ans[1][1]=1;
		for(i=1;i<=len;i++){
			if(n[i][1]+d2==n[i+1][1]&&ans[i][j]==1){
				ans[i+1][1]=1;
			}
			if(n[1][i]+d2==n[1][i+1]&&ans[i][j]==1){
				ans[1][i+1]=1;
			}			
		}
		for(i=1;i<=len;i++){
			for(j=1;j<=len;j++){
				if(n[i][j]+d2==n[i][j+1]&&ans[i][j]==1){
					ans[i][j+1]=1;
				}
				if(n[i][j]+d2==n[i+1][j]&&ans[i][j]==1){
					ans[i+1][j]=1;
				}				
			}
		}
	}
	if(ans[len][len]==1){
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0;
}
