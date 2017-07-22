# include <iostream>
using namespace std;

class graph{
	private:
		int maxVertices;
		int numVertices;
		int numEdges;
		int *VerticesList;
		int **Edge;
		const int maxWeight=9999;
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
			for(int i=0;i<maxVertices;i++){
				for(int j=0;j<maxVertices;j++)
				Edge[i][j]=(i==j)?0:maxWeight;
			}
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
			if(v!=-1){
				for(int col=0;col<numVertices;col++)
				if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;
			}
			return -1;
		}
		int getNextNeighbor(int v,int w){
			if(v!=-1&&w!=-1){
				for(int col=w+1;col<numVertices;col++)
				if(Edge[v][col]>0&&Edge[v][col]<maxWeight) return col;
			}
			return -1;
		}
		bool insertVertes(int &v){
			if(numVertices==maxVertices) return false;
			VerticesList[numVertices++]=v;
			return true;
		}
		bool insetEdge(int v1,int v2,int cost){
			if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]==maxWeight){
				Edge[v1][v2]=Edge[v2][v1]=cost;
				numEdges++;
				return true;
			}
			else return false;
		}
		int NumberOfVertices(){
			return numVertices;
		} 
		int NumberOfEdges(){
			return numEdges;
		}
		void creatEdges(int n){
			//numVertices=n;
		    for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
				cin>>Edge[i][j];
			}	
		}
}; 
void shortestPath(graph &G,int v,int dist[],int path[]){
	int n=G.NumberOfVertices();
	bool *S=new bool[n];
	int i,j,k;
	int w,min;
	for(i=0;i<n;i++){
		dist[i]=G.getWeight(v,i);
		S[i]=false;
		if(i!=v&&dist[i]>0) path[i]=v;
		else path[i]=-1;
	}
	S[v]=true; dist[v]=0;
	for(i=0;i<n-1;i++){
		min=9999; int u=v;
		for(j=0;j<n;j++){
			if(S[j]==false&&dist[j]<min){
				u=j;
				min=dist[j];
			}
		}
		S[u]=true;
		for(k=0;k<n;k++){
			w = G.getWeight(u,k);
			if(S[k]==false&&w>0&&dist[u]+w<dist[k]){
				dist[k]=dist[u]+w;
				path[i]=u;
			}
		}
	}
}
int main(){
	int n,v;
	cin>>n>>v;
	graph G(100);
	int dist[100],path[100];
	G.creatEdges(n);
	shortestPath(G,v,dist,path);
	for(int i=0;i<n;i++)
	if(i!=v)
	cout<<dist[i]<<" ";
	return 0;
}
