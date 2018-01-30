#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,divisor,i;
		cin>>n>>divisor;
		//cout<<n<<" "<<divisor<<endl;
		int str[n];
		string num;
		cin>>num;
		for(i=0;i<n;i++)str[i]=num[i]-'0';
		//for(i=0;i<n;i++)cout<<str[i];
		//cout<<endl;
		int tmp=0,count=0;
		for(i=0;i<n;i++){
			tmp=(tmp*10+str[i])%divisor;
				//cout<<"     "<<tmp<<endl;
			if(tmp==0 ){
				count++;
				tmp=0;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
