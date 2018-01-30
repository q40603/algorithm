#include<bits/stdc++.h> 
//belemford to recalculate
//Dijkstra's algorithm
#define max 2000001
using namespace std;
struct node{
	 int dest=0;
	 int weight=0;
	node *next;
};
struct vertex{
	int vertex;
	int dist;
};
class jon{
	private:
		node *adj[10005];
		node *ou[10005];
		 int ans[10005];
		 int *pred;
		 int *dist;
		 int ver,edge,output;
	public:
		jon( int a, int b, int c){
			ver=a;
			edge=b;
			output=c;
			pred=new  int[a+1];
			dist=new  int[a+1];
			for(int i=0;i<10005;i++){
				adj[i]=NULL;
				ou[i]=NULL;
				ans[i]=max;
				if(i<=a){
					dist[i]=max;
					pred[i]=-1;
				}
			}
		}
		void readin();
		void add( int, int, int,node **);
		void print();
		void rewrite();
		void relax(int,int,int);
		void dijkstra(int,int *,int *);
		void heapify( vertex *minHeap, int size, int i, int pos[]);
		void buildHeap( vertex *minHeap, int size, int pos[]);
		void decreaseKey(vertex *minHeap, vertex newNode, int pos[]);
		vertex extractMin(vertex *minHeap, int size, int pos[]);
		void dijkstra_ans();
};
int main(){
	 int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	jon p(n,m,q);
	p.readin();
	p.rewrite();
	p.dijkstra_ans();
	p.print();
	return 0;
}
void jon::readin(){
	 int i,j;
	 int first,last,we;
	for(i=0;i<edge;i++){
		scanf("%d%d%d",&first,&last,&we);
		add(first,last,we,adj);
	}
	for(i=1;i<=ver;i++)add(0,i,0,adj);
	for(i=1;i<=output;i++){
		scanf("%d%d",&first,&last);
		add(first,last,i,ou);
	}
}
void jon::add( int first, int last, int we,node *a[]){
	if(a[first]==NULL){
		a[first]= new node;
		a[first]->dest=last;
		a[first]->weight=we;
		a[first]->next=NULL;
	}
	else{
		node* tmp= a[first];
		a[first]=new node;
		a[first]->dest=last;
		a[first]->weight=we;
		a[first]->next=tmp;		
	}	
}
void jon::print(){
	 int i,j;
	for(i=1;i<=output;i++){
		if(ans[i]==max)cout<<"no path"<<endl;
		else{
			cout<<ans[i]<<endl;
		}
	}
}
void jon::rewrite(){
	int i,j;
	dist[0]=0;
	for(i=0;i<edge;i++){
		for(j=0;j<=edge;j++){
			if(adj[j]!=NULL){
				node *tmp=adj[j];
				while(tmp){
					relax(j,tmp->dest,tmp->weight);
					tmp=tmp->next;
				}
			}
		}	
	}
	for(i=1;i<=edge;i++){
		if(adj[i]!=NULL){
			node *tmp=adj[i];
			while(tmp){
				tmp->weight+=dist[i]-dist[tmp->dest];
				tmp=tmp->next;
			}
		}
	}	
}
void jon::relax(int from, int to, int weight){
    if (dist[to] > dist[from] + weight) {
        dist[to] = dist[from] + weight;
        pred[to] = from;
    }
}
void jon::heapify( vertex *minHeap, int size, int i, int *pos)
{
	vertex temp;
    while ((2 * i) <= size) {
        if ((2 * i) + 1 > size) {
			if (minHeap[i].dist > minHeap[2 * i].dist) {
				pos[minHeap[i].vertex] = 2 * i;
				pos[minHeap[2 * i].vertex] = i;
                temp = minHeap[i];
                minHeap[i] = minHeap[2 * i];
                minHeap[2 * i] = temp;
            }
            break;
        }
        if (minHeap[i].dist > minHeap[2 * i].dist || minHeap[i].dist > minHeap[2 * i + 1].dist) {
            if (minHeap[2 * i].dist <= minHeap[(2 * i) + 1].dist) {
                pos[minHeap[i].vertex] = 2 * i;
				pos[minHeap[2 * i].vertex] = i;
                temp = minHeap[2 * i];
                minHeap[2 * i] = minHeap[i];
                minHeap[i] = temp;
                i = 2 * i;
            } 
			else if (minHeap[2 * i].dist > minHeap[(2 * i) + 1].dist) {
                pos[minHeap[i].vertex] = 2 * i + 1;
				pos[minHeap[2 * i + 1].vertex] = i;

                temp = minHeap[(2 * i) + 1];
                minHeap[(2 * i) + 1] = minHeap[i];
                minHeap[i] = temp;
                i = (2 * i) + 1;
            }
        } 	
		else {
            	break;
       		}
    }
}

// Build Heap Procedure - O(N)
void jon::buildHeap(vertex *minHeap, int size, int *pos)
{
    int i;
    for (i = size / 2; i >= 1; --i) {
        heapify(minHeap, size, i, pos);
    }
}
void jon::dijkstra(int startVertex,int *distances,int *parent)
{
    int i;
    vertex minVertex;
    vertex priorityQueue[ver + 1]; 	// To use the array as 1-indexed
    int pos[ver + 1];	// Stores the position (index) of vertex
    // Initially no routes to vertices are know, so all are infinity
    for (i = 1; i <= ver; ++i) {
        distances[i] = max;
        parent[i] = 0;
        priorityQueue[i].dist = max;
        priorityQueue[i].vertex = i;
		pos[i] = priorityQueue[i].vertex;
    }
    // Setting distance to source to zero
    distances[startVertex] = 0;
    priorityQueue[startVertex].dist = 0;
    buildHeap(priorityQueue, ver, pos);
    for (i = 1; i <= ver; ++i) {     // Untill there are vertices to be processed
		minVertex = extractMin(priorityQueue, ver, pos);   // Greedily process the nearest vertex
		node * trav = adj[minVertex.vertex];    // Checking all the vertices adjacent to 'min'
        while (trav != NULL) {
        	int u = minVertex.vertex;
        	int v = trav->dest;
        	int w = trav->weight;
            if (distances[u] != max && distances[v] > distances[u] + w) {
                // We have discovered a new shortest route, make the neccesary adjustments in data
                distances[v] = distances[u] + w;
                parent[v] = u;
                // Making changes to the priority queue
                struct vertex changedVertex;
                changedVertex.vertex = v;
                changedVertex.dist = distances[v];	// new distance
                decreaseKey(priorityQueue, changedVertex, pos);
            }
            trav = trav->next;
        }
    }
}
void jon::decreaseKey(vertex *minHeap, struct vertex newNode, int pos[])
{
	minHeap[pos[newNode.vertex]].dist = newNode.dist;
	int i = pos[newNode.vertex];
	struct vertex temp;
    while (i > 1) {
        if (minHeap[i / 2].dist > minHeap[i].dist) {
            pos[minHeap[i].vertex] = i / 2;
			pos[minHeap[i / 2].vertex] = i;

            temp = minHeap[i / 2];
            minHeap[i / 2] = minHeap[i];
            minHeap[i] = temp;
            i = i / 2;
        } 
		else {
            break;
        }
    }
}

// Removes and Returns the topmost element - O (log N)
vertex jon:: extractMin(struct vertex minHeap[], int size, int pos[])
{
	pos[minHeap[1].vertex] = size;
	pos[minHeap[size].vertex] = 1;
	struct vertex min = minHeap[1];
	minHeap[1] = minHeap[size];
	--size;
	heapify(minHeap, size, 1, pos);
	return min;
}
void jon::dijkstra_ans(){
	int distances[ver+1];
    int parent[ver+1];
	for(int i=1;i<=ver;i++){
		if(ou[i]!=NULL){
			dijkstra(i,distances,parent);
			node *tmp=ou[i];
			while(tmp){
				if(distances[tmp->dest]!=max)
				ans[tmp->weight]=distances[tmp->dest]-(dist[i]-dist[tmp->dest]);
				tmp=tmp->next;
			}
		}
	}
}
