#include<bits/stdc++.h>
using namespace std;
int partion(int *a,int p,int r){
	int x=a[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(a[j]>=x){
			i++;
			if(i!=j){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;			
			}	
		}
	}
	int tp=a[i+1];
	a[i+1]=a[r];
	a[r]=tp;
	return i+1;
	
}

void quicksort(int *a,int p,int r){
	if(p<r){
		int q=partion(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r); 
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,i,j,firc=0,to=0,y=0;
		cin>>n>>m;
		int fam[n],table[m];
		for(i=0;i<n;i++){
			cin>>fam[i];
			firc+=fam[i];
			to+=fam[i];
			if(fam[i]>m)y=1;
		}
		for(i=0;i<m;i++){
			cin>>table[i];
			firc-=table[i];
		}
		if(firc>0 || y==1){
			cout<<"No"<<endl;
		}
		else{
			int ch=0;
			quicksort(fam,0,n-1);
			for(i=0;i<n;i++){
				quicksort(table,0,m-1);
				for(j=0;j<fam[i];j++){
					if(table[j]==0){
						ch=1;
						break;
					}
					else{
						table[j]--;
					}
				}
				if(ch==1)break;
			}
			if(ch==1){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
			}
		}
		
	}
	return 0;
	
}
