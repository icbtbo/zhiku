# include <iostream>
using namespace std;
struct linknode{
	int data;
	linknode *link;
	linknode(int x):data(x),link(NULL){
	}
};
class queue{
	protected:
		linknode *rear,*front;
	public:
		queue(){
			rear = front = NULL;
		}
		bool isempty(){
			return (front == NULL)?true:false;
		}
		void Enqueue(int x){
			if(front == NULL){
				rear = front = new linknode(x);
			}
			else{
				rear->link = new linknode(x);
				rear = rear->link;
			}
		}
		bool Dequeue(int &x){
			if(front == NULL) return false;
			linknode *p = front;
			x = front->data;
			front = front->link;
			delete p;
			return true;
		}
};
class graph{
	private:
		int maxVertices;
		int numVertices;
		int numEdges;
		int *VerticesList;
		int **Edge;
	public:
		graph(int sz){
			maxVertices=sz;
			numVertices=0;
			numEdges=0;
			int i,j;
			VerticesList=new int[maxVertices];
			Edge=(int **) new int *[maxVertices];
			for(int i=0;i<maxVertices;i++)
			Edge[i]=new int[maxVertices]; 
		}
		int getWeight(int v1,int v2){
			return Edge[v1][v2];
		}
		int getVertexPos(int vertex){
			for(int i=0;i<numVertices;i++)
			if(VerticesList[i]==vertex) return i;
			return -1;
		}
		int getFirstNeighbor(int v){
				for(int col=0;col<numVertices;col++)
				if(Edge[v][col]==1) return col;
			return -1;
		}
		int getNextNeighbor(int v,int w){
				for(int col=w+1;col<numVertices;col++)
				if(Edge[v][col]==1) return col;
			return -1;
		}
		int NumberOfVertices(){
			return numVertices;
		} 
		int NumberOfEdges(){
			return numEdges;
		}
		void creatEdges(int n){
			numVertices=n;
		    for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
				cin>>Edge[i][j];
			}	
		}
}; 
void BFS(graph &G,int v){
	int i,w,n=G.NumberOfVertices(),loc=v;
	bool *visited = new bool[n];
	for(i=0;i<n;i++) visited[i]=false;
	cout<<v<<" ";
	visited[v]=true;
	queue Q; Q.Enqueue(v);
	while(!Q.isempty()){
		Q.Dequeue(loc);
		w = G.getFirstNeighbor(loc);
		while(w!=-1){
			if(visited[w]==false){
				cout<<w<<" ";
				visited[w] = true;
				Q.Enqueue(w);
			}
			w = G.getNextNeighbor(loc,w);
		}
	}
}
int main(){
	int n;
	cin>>n;
	graph G(100);
	G.creatEdges(n);
	BFS(G,0);
	return 0;
}
