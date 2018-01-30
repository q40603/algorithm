#include<iostream>
#include<stdio.h>
using namespace std;
struct tf{
	unsigned long long int two=0;
	unsigned long long int five=0;
};

int main(){
	unsigned long long int size,i,j;
	scanf("%d",&size);
	tf **lc=new tf*[size];
	tf **co=new tf*[size];
	for(i=0;i<size;i++)lc[i]=new tf[size];
	for(i=0;i<size;i++)co[i]=new tf[size]; 
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			unsigned long long int a;
			scanf("%ulld",&a);
			while(a%2==0){
				a/=2;
				lc[i][j].two++;	
			}
			while(a%5==0){
				a/=5;
				lc[i][j].five++;
			}
		}
	}
	
	/*for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<"("<<lc[i][j].five<<","<<lc[i][j].two<<") ";
		}
		cout<<endl;
	}*/
	co[0][0].five=lc[0][0].five;
	co[0][0].two=lc[0][0].two;
	//cout<<"("<<co[0][0].five<<","<<co[0][0].two<<") ";
	for(i=1;i<size;i++){
		co[i][0].five=co[i-1][0].five+lc[i][0].five;
		co[i][0].two=co[i-1][0].two+lc[i][0].two;
		co[0][i].five=co[0][i-1].five+lc[0][i].five;
		co[0][i].two=co[0][i-1].two+lc[0][i].two;
	}
	for(i=1;i<size;i++){
		for(j=1;j<size;j++){
			/*if(min(co[i-1][j].five+lc[i][j].five,co[i-1][j].two+lc[i][j].two)<
			min(co[i][j-1].five+lc[i][j].five,co[i][j-1].two+lc[i][j].two)){
				co[i][j].five=co[i-1][j].five+lc[i][j].five;
				co[i][j].two=co[i-1][j].two+lc[i][j].two;
			}
			else if(min(co[i-1][j].five+lc[i][j].five,co[i-1][j].two+lc[i][j].two)==
			min(co[i][j-1].five+lc[i][j].five,co[i][j-1].two+lc[i][j].two)){
				if(co[i-1][j].five<=co[i][j-1].five&&co[i-1][j].two<=co[i][j-1].two){
					co[i][j].five=co[i-1][j].five+lc[i][j].five;
					co[i][j].two=co[i-1][j].two+lc[i][j].two;
				}
				else{
					co[i][j].five=co[i][j-1].five+lc[i][j].five;
					co[i][j].two=co[i][j-1].two+lc[i][j].two;
				}
			}
			else{
				co[i][j].five=co[i][j-1].five+lc[i][j].five;
				co[i][j].two=co[i][j-1].two+lc[i][j].two;
			}	*/
			co[i][j].five=lc[i][j].five+min(co[i-1][j].five,co[i][j-1].five);	
			co[i][j].two=lc[i][j].two+min(co[i-1][j].two,co[i][j-1].two);	
		}
	}
	cout<<min(co[size-1][size-1].five,co[size-1][size-1].two)<<endl;
	/*for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<"("<<co[i][j].five<<","<<co[i][j].two<<") ";
		}
		cout<<endl;
	}*/
	return 0;
}
