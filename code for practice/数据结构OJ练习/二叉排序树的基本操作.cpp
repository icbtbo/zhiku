# include <iostream>
using namespace std;

struct BinTreeNode{
	int data;
	BinTreeNode *leftchild,*rightchild;
	BinTreeNode(int x,BinTreeNode *l = NULL,BinTreeNode *r = NULL):data(x),leftchild(l),rightchild(r){};
};

class BinaryTree{
	protected:
		BinTreeNode *root;
	public:
		BinTreeNode *&getroot(){
			return root;
		}
		bool insert(int x,BinTreeNode *&p){
			if(p == NULL){
				p = new BinTreeNode(x);
				return true;
			}
			else if(x<p->data) insert(x,p->leftchild);
			else if(x>p->data) insert(x,p->rightchild);
			else return false;
		}
		void BST(int n){
			int t,num=1;
			root = NULL;
			cin>>t;
			while(num<n){//99 是输入结束标志 
				insert(t,root);
				cin>>t;
				num++;
			}
		}
};
int  search(BinTreeNode *t,int x){
	if(t == NULL) return 0;
	else if(x == t->data) return 1;
	else if(x<t->data)
	return search(t->leftchild,x);
	else 
	return search(t->rightchild,x);
}

int main(){
	int x,m,n,k,temp;
	cin>>n>>k;
	BinaryTree t; 
	t.BST(n);
	for(int i=0;i<k;i++){
		cin>>temp;
		cout<<search(t.getroot(),temp)<<" ";
	}
	return 0;
}
