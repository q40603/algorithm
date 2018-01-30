#include<iostream>
#include<string.h>
#include<cstdlib>
#include <algorithm>
#include<deque>
using namespace std;


int main(){
		int num,i;
		cin>>num;
		int mn=1,mx=num;
		int qs[num];
		for(i=0;i<num;i++){
			cin>>qs[i];
		}
		int l=num,yes=0,ne=1;
		int med=(l-1)/2;
		if(l%2==1){
            for(int i=0;i<l;i++){
                //cout<<qs[med+ne*i]<<" "<<mx<<" "<<mn<<endl;
                if(med+ne*i>=l || med+ne*i<=0)break;
                if(qs[med+ne*i]==mn)mn++;
                else if(qs[med+ne*i]==mx)mx--;
                else{
                    yes=1;
                    break;
                }
                med+=ne*i;
                ne*=-1;
            }
		}
		else{
                ne=-1;
                for(int i=0;i<l;i++){
                //cout<<qs[med+ne*i]<<" "<<mx<<" "<<mn<<endl;
                if(med+ne*i>=l || med+ne*i<=0)break;
                if(qs[med+ne*i]==mn)mn++;
                else if(qs[med+ne*i]==mx)mx--;
                else{
                    yes=1;
                    break;
                }
                med+=ne*i;
                ne*=-1;
            }
		}


		if(yes==1)cout<<"No";
		else{
			cout<<"Yes";
		}
	return 0;
}
