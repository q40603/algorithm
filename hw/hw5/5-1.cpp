#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,i,j,k;
		scanf("%d",&n);
		int cr[n][3];
		int cou[n];
		for(i=0;i<n;i++){
			cou[i]=1;
			scanf("%d",&cr[i][0]);
			char b;
			scanf("%c",&b);
			switch(b){
				case 'H':{
					cr[i][1]=0;
					break;
				}
				case 'D':{
					cr[i][1]=1;
					break;
				}
				case 'C':{
					cr[i][1]=2;
					break;
				}
				case 'S':{
					cr[i][1]=3;
					break;
				}												
			}
			cr[i][2]=1;
		}
		int tmp=0,fin=0;
			for(i=1;i<n;i++){
				for(j=i-1;j>=0;j--){
					if(cr[i][0]==cr[j][0] || cr[i][1]==cr[j][1] ||
					cr[i][0]==8 || cr[j][0]==8 )
					{
						tmp=max(tmp,cou[j]);
					}
				}
				cou[i]+=tmp;
				fin=max(fin,cou[i]);
				tmp=0;
				//cout<<endl;
			}		
	
		cout<<fin<<endl;
		/*for(i=0;i<n;i++){
			cout<<cou[i]<<" ";
		}*/
	}
	
	
	return 0;
}
