# include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};
struct Edge{
	int dest;
	Edge *link;
}; 

struct Vertex{
	int data;
	Edge *adj;
};

class stack{
	private:
		node *top;
    public:
    	stack(){
    		top = NULL;
		}
		void push(int x){
			node *p = top;
			top = new node;
			top->data = x;
			top->next = p;
		}
		int pop(int &x){
			x = top->data;
			node *p = top;
			top = top->next;
			delete p;
		}
		bool isempty(){
			return (top == NULL)?true:false;
		}
};
class graph{
	private:
		Vertex *NodeTable;
		int *innode;
	public:
	    graph(int sz){
	    	innode = new int[sz];
	    	for(int i=0;i<sz;i++)
	    	innode[i]=0;
	    	NodeTable = new Vertex[sz];
	    	for(int i=0;i<sz;i++)
	    	NodeTable[i].adj = NULL;
		} 
		void createEdge(int n){
			int temp;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cin>>temp;
					if(temp){
						Edge *p = new Edge;
						p->dest = j;
						p->link = NodeTable[i].adj;
						NodeTable[i].adj = p;
						innode[j]++;
					}
				}
			}
		}
		void toposort(int n){
			stack s;
			int count,k,i,t=0,a[n];
			bool visited[n];
			for(int m=0;m<n;m++)
			visited[m]=false; 
			Edge *p;
			for(i=0;i<n;i++)
			if(!innode[i])
			s.push(i);
			count = 0;
			while(!s.isempty()){
				s.pop(i);
				visited[i]=true;
				a[t++]=i;
				count++;
				for(p=NodeTable[i].adj;p!=NULL;p=p->link){
				k = p->dest;
				if(!(--innode[k])&&visited[k]==false) s.push(k);
			    }
				
			}
			if(count<n) cout<<"ERROR"<<endl;
			else{
				for(int j=0;j<n;j++)
				cout<<a[j]<<" ";
				cout<<endl; 
			} 
		}
};
int main(){
	int n;
	cin>>n;
	graph G(n);
	G.createEdge(n);
	G.toposort(n);
	return 0;
}
