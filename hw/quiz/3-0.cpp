#include<bits/stdc++.h>
using namespace std;
int mx='z';

int main(){
	int n;
	cin>>n;
	int mx='z';
	int check[mx+1],count=1,first,second;
	char cr[n+2][n+2],s;
	int mo[n+2][n+2];
	memset(cr,0,sizeof(cr));
	memset(mo,0,sizeof(mo));
	memset(check,0,sizeof(check));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>cr[i][j];
		}
	}
	mo[1][1]=1;
	check[cr[1][1]]=1;
	bool br=false;	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(check[cr[i][j]]==0){
				check[cr[i][j]]==1;
				first=cr[1][1];
				second =cr[i][j];
				s=cr[i][j];
				br=true;
				break;
			}
		}
		if(br==true)break;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mo[i][j]==1){
				if(cr[i+1][j]==second ||cr[i+1][j]==first){
					mo[i+1][j]=1;
				}
				if(cr[i][j+1]==second ||cr[i][j+1]==first){
					mo[i][j+1]=1;
				}				
			}
			
		}
	}		

	if(mo[n][n]==1)cout<<"Yes";
	else{
	memset(mo,0,sizeof(mo));
	memset(check,0,sizeof(check));
	mo[1][1]=1;
	check[cr[1][1]]=1;
	bool br=false;	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(check[cr[i][j]]==0){
				check[cr[i][j]]==1;
				first=cr[1][1];
				second =cr[i][j];
				s=cr[i][j];
				br=true;
				break;
			}
		}
		if(br==true)break;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mo[i][j]==1){
				if(cr[i+1][j]==second ||cr[i+1][j]==first){
					mo[i+1][j]=1;
				}
				if(cr[i][j+1]==second ||cr[i][j+1]==first){
					mo[i][j+1]=1;
				}				
			}
			
		}
	}
	if(mo[n][n]==1)cout<<"Yes";
	else{
		cout<<"No";
	}	
	}	
	
	return 0;
}
/*
3
b b c
g g x
x b b
*/
