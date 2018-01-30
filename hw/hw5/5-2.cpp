#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;

int larg(int a,int b){
	return (a>b)? a:b;
}
int maxcost(int **max,int x,int y){
	/*if(x<0||y<0){
		return INT_MAX;
	}*/
	if(x==0 &&y==0){
		return max[0][0];
	}
	else if(x>=0 && y>=0){
		//cout<<"   "<<x<<"   "<<y<<endl;
		//cout<<max[x][y]<<endl;
		return max[x][y]+larg(maxcost(max,x-1,y),maxcost(max,x,y-1));
	}
}
int maxcost2(int **cost,int size)
{
     int i, j;
 
     // Instead of following line, we can use int tc[m+1][n+1] or 
     // dynamically allocate memoery to save space. The following line is
     // used to keep te program simple and make it working on all compilers.
     int tc[size][size]={0};  
 
     tc[0][0] = cost[0][0];
 
     /* Initialize first column of total cost(tc) array */
     for (i = 1; i < size; i++){
     	tc[i][0] = tc[i-1][0] + cost[i][0];
     	//cout<<tc[i][0]<<" ";
	 }
        
 
     /* Initialize first row of tc array */
     for (j = 1; j < size; j++){
     	tc[0][j] = tc[0][j-1] + cost[0][j];
     	//cout<<tc[0][j]<<endl;
	 }
        
 
     /* Construct rest of the tc array */
     for (i = 1; i <size; i++){
     	for (j = 1; j < size; j++){
     		tc[i][j] = larg(tc[i-1][j],tc[i][j-1]) + cost[i][j];
			//cout<<tc[i][j]<<" ";
		 }
		 //cout<<endl;
	 }
        
            
            
     return tc[size-1][size-1];
}
int main(){
	int size,i,j;
	scanf("%d",&size);
	int **max;
	max=new int *[size];
	//cout<<INT_MAX<<endl; 
	for(i=0;i<size;i++){
		max[i]=new int[size];
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%d",&max[i][j]);
		}
	}
	//maxcost2(max,size);
	//printf("%d",maxcost(max,size-1,size-1));
	printf("%d",maxcost2(max,size));
	
	/*for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%d ",max[i][j]);
		}
		printf("\n");
	}*/
		
	
	
	
	return 0;
}
