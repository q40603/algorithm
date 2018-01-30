#include <bits/stdc++.h>
using namespace std;

int n, m, z;
bool visit[101][101];
int num[101][101];

int bfs(int startx, int starty) {
 queue<int> qx, qy;
 qx.push(startx);
 qy.push(starty);
 num[startx][starty] = 0;
 while(!qx.empty()) {
  int x = qx.front(); qx.pop();
  int y = qy.front(); qy.pop();
  if(visit[x][y]) continue;
  visit[x][y] = true;
  if(x==z || y==z) return num[x][y];

  if(!visit[x][0] && (num[x][y]+1<num[x][0] || num[x][0]==-1)) {
   qx.push(x); qy.push(0);
   num[x][0] = num[x][y] + 1;
  }
  if(!visit[0][y] && (num[x][y]+1<num[0][y] || num[0][y]==-1)) {
   qx.push(0); qy.push(y);
   num[0][y] = num[x][y] + 1;
  }
  if(!visit[x][m] && (num[x][y]+1<num[x][m] || num[x][m]==-1)) {
   qx.push(x); qy.push(m);
   num[x][m] = num[x][y] + 1;
  }
  if(!visit[n][y] && (num[x][y]+1<num[n][y] || num[n][y]==-1)) {
   qx.push(n); qy.push(y);
   num[n][y] = num[x][y] + 1;
  }
  int mini = min(x, m-y);
  if(!visit[x-mini][y+mini] && (num[x][y]+1<num[x-mini][y+mini] || num[x-mini][y+mini]==-1)) {
   qx.push(x-mini); qy.push(y+mini);
   num[x-mini][y+mini] = num[x][y] + 1;
  }
  mini = min(n-x, y);
  if(!visit[x+mini][y-mini] && (num[x][y]+1<num[x+mini][y-mini] || num[x+mini][y-mini]==-1)) {
   qx.push(x+mini); qy.push(y-mini);
   num[x+mini][y-mini] = num[x][y] + 1;
  }
 }
 return -1;
}

int main() {
 int T; scanf("%d", &T);
 while(T--) {
  int x, y;
  scanf("%d%d%d%d%d", &n, &m, &x, &y, &z);
  memset(num, -1, sizeof(num));
  memset(visit, false, sizeof(visit));
  if(z>n && z>m) printf("-1\n");
  else   printf("%d\n", bfs(x, y));
 }
}
