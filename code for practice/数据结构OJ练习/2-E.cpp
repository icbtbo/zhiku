# include <iostream>
# include <string.h>
using namespace std;

struct tree{
	int lchild,rchild;
};

struct linknode{
	int data;
	linknode* link;
};

class queue{//定义队列类 
	protected:
		linknode *front, *rear;
	public:
		queue(){
			front=rear= NULL;
		}
		bool isempty(){
			return (front==NULL)?true:false;
		}
		bool enqueue(int x){
			if(isempty()==true){
				front = rear = new linknode;
				front->data = x;
				front->link = NULL;
			}
			else{
				rear->link = new linknode;
				rear = rear->link;
				rear->data = x;
				rear->link = NULL;
			}
			return true;
		}
		bool dequeue(int &x){
			if(front==NULL) return false;
			linknode *p = front;
			x = front->data;
			front = front->link;
			delete p;
			return true;
		}
};
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,root;
		cin>>n;
		tree t[30];
		int temp[30]={0};
		for(int i=0;i<n;i++){
			int l,r;
			cin>>l;
			t[i].lchild=l-1;
			cin>>r;
			t[i].rchild=r-1;
			if(t[i].lchild!=-2){
				temp[t[i].lchild]=1;
			}
			if(t[i].rchild!=-2){
				temp[t[i].rchild]=1;
			}
		}
		for(int i=0;i<n;i++){//获得根结点的下标 
			if(temp[i]==0)
			root = i;    
		}
		//判断是否为完全二叉树
		queue q;
		int e;
		bool p=true;
		q.enqueue(root);
		q.dequeue(e);
		while(e!=-2){
			q.enqueue(t[e].lchild);
			q.enqueue(t[e].rchild);
			q.dequeue(e);
		} 
		while(!q.isempty()){
			q.dequeue(e);
			if(e!=-2){
			    p=false;
			    break;
		    }
		}
		if(p==true)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
} 
