#include <iostream>
#include <queue>
#include <cstring>
#define _ ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int** graph;
int parent[300]={0};
int n,v;
bool visit[300]={false};
bool inline min(int &a,int &b){
    return a<b;
}
bool bfs(int r[300][300]){
	
    memset(visit,0,sizeof(visit));
    queue<int>q;
    q.push(0);
    visit[0] = true;
    parent[0] = -1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(!visit[i] && r[a][i]==1){
                q.push(i);
                visit[i]=true;
                parent[i] = a;
            }
        }
    }
    return visit[v-1];
}

int ford(){
	//cout<<"hahahah";
    int r[300][300];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            r[i][j]=graph[i][j];
        }
    }
    int max = 0;
    while (bfs(r)){
        int flow = 1e9;
        for(int i=v-1;i>0;i=parent[i]){
            if(flow > r[parent[i]][i])
                flow = r[parent[i]][i];
        }
        for(int i=v-1;i>0;i=parent[i]){
            r[parent[i]][i] -= flow;
            r[i][parent[i]] += flow;
        }
        max += flow;
    }
    return max;
}

int main() {
	int pr[]={0,2, 3, 5, 7, 11, 
			13, 17, 19, 23, 29, 
			31, 37, 41, 43, 47, 
			53, 59, 61, 67, 71, 
			73, 79, 83, 89, 97, 
			101, 103, 107, 109, 
			113, 127, 131, 137, 
			139, 149, 151, 157, 
			163, 167, 173, 179, 
			181, 191, 193, 197, 199};
	int num,ver;
	cin>>num;
	v=202;
	graph = new int*[v]();
	for(int i=0;i<v;i++)graph[i]=new int[v]();
	for(int i=0;i<num;i++){
		cin>>ver;
		graph[ver][v-1]=1;
		for(int j=1;j<47;j++){
			if(ver%pr[j]==0){
				graph[pr[j]][ver]=1;
				graph[0][pr[j]]=1;
			}
			//cout<<pr[j]<<" "<<ver<<endl;
		}
	}
	//for(int i=1;i<202;i++)cout<<graph[0][i]<<" ";
	cout<<ford();
	/*for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}*/	
    return 0;
}
