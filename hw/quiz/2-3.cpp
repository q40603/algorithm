#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;
typedef long long LL;
typedef pair<int, int> P;

struct Edge {
 	int to, cap, rev;
};

int n, m, V;
int bx[100], by[100], bz[100];
int tx[100], ty[100], tz[100];
vector<Edge> G[150];
int level[150];
int iter[150];

void add_edge(int from, int to, int cap) {
 	int s1 = G[to].size();
 	int s2 = G[from].size();
 	Edge e1 = Edge{to, cap, s1};
 	Edge e2 = Edge{from, 0, s2};
 	G[from].push_back(e1);
 	G[to].push_back(e2);
}

void bfs(int s) {
 	memset(level, -1, sizeof(level));
 	queue<int> que;
 	que.push(s);
 	level[s] = 0;
 	while(!que.empty()) {
 		int v = que.front(); que.pop();
  		int size = G[v].size();
  		for(int i=0; i<size; i++) {
   			Edge &e = G[v][i];
   			if(e.cap>0 && level[e.to]<0) {
   				level[e.to] = level[v] + 1;
    			que.push(e.to);
   			}
  		}
	}
}

int dfs(int v, int t, int f) {
 	if(v == t) return f;
 	int size = G[v].size();
 	for(int &i=iter[v]; i<size; i++) {
 		Edge &e = G[v][i];
  		if(e.cap>0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.cap));
  			if(d > 0) {
   				e.cap -= d;
   				G[e.to][e.rev].cap += d;
    			return d;
   			}
  		}
 	}
 return 0;
}

int max_flow(int s, int t) {
 	int flow = 0, f;
 	while(1) {
  		bfs(s);
  		memset(iter, 0, sizeof(iter));
  		int f = dfs(s, t, INF);
  		if(f == 0) return flow;
  		flow += f;
 	}
}

void solve() {
 	V = n+m+1;
 	LL l = -1, r = INF;
 	while(l+1 < r) {
  		LL mid = (l+r) / 2;
  		int sum = 0;

  		for(int i=0; i<=V; i++) G[i].clear();
  		for(int i=1; i<=n; i++) {
   			add_edge(0, i, bz[i]);
   				for(int j=1; j<=m; j++) {
    				if(abs(bx[i]-tx[j]) + abs(by[i]-ty[j]) <= mid) {
     					add_edge(i, n+j, INF);
    				}
   				}
  		}
  		for(int j=1; j<=m; j++) {
   			add_edge(n+j, V, tz[j]);
   			sum += tz[j];
  		}
  //cout << mid << endl;
  		if(max_flow(0, V) == sum) r = mid;
  			else l = mid;
	}
 	if(r == INF) printf("-1\n");
 	else   printf("%d\n", r);
}

int main() {
 	int T; scanf("%d", &T);
 	while(T--) {  
 	 	scanf("%d%d", &n, &m);
  		for(int i=1; i<=n; i++) scanf("%d%d%d", &bx[i], &by[i], &bz[i]);
  		for(int i=1; i<=m; i++) scanf("%d%d%d", &tx[i], &ty[i], &tz[i]);
  		solve();
 	}
 return 0;
}
