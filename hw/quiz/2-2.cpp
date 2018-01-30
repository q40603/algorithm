#include <bits/stdc++.h>
using namespace std;

vector<int> v[200001];
int p[200001];
bool in[200001];

bool dfs(int x) {
 	bool flag = false;
 	int size = v[x].size();
 	for(int i=0; i<size; i++) {
 	int y = v[x][i];
 		if(y != p[x]) {
 			p[y] = x;
  	 		if(!dfs(y)) flag = true;
  		}
 	}
	return in[x] = flag;
}

int main() {
 	int n; 
	scanf("%d", &n);
	for(int i=1; i<n; i++) {
  		int x, y;
  		scanf("%d%d", &x, &y);
  		v[x].push_back(y);
  		v[y].push_back(x);
	}
 	memset(p, -1, sizeof(p));
 	memset(in, false, sizeof(in));
 	p[1] = 1;
 	dfs(1);
 	int ans = 0;
 	for(int i=1; i<=n; i++) {
  		if(in[i]) ans++;
 	}
 	printf("%d\n", ans);

 	return 0;
}
