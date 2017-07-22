# include <iostream>
using namespace std;

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
void DFS(graph &G,int v,bool visited[]){
	cout<<v<<" ";
	visited[v]=true;
	int w = G.getFirstNeighbor(v);
	while(w!=-1){
		if(visited[w]==false) DFS(G,w,visited);
		w = G.getNextNeighbor(v,w);
	}
} 
void DFS(graph &G){
	int i,n=G.NumberOfVertices();
	bool *visited = new bool[n];
	for(i=0;i<n;i++) visited[i]=false;
	DFS(G,0,visited);
}
int main(){
	int n;
	cin>>n;
	graph G(100);
	G.creatEdges(n);
	DFS(G);
	return 0;
}
