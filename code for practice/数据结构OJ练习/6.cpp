# include <iostream>
# include <stdio.h>
using namespace std;

struct node{
	int data;
	node *llink;
	node *rlink;
}; 

class dblist{
	private:
		node *first;
	public:
		dblist(){
			first=new node;
			first->llink=first->rlink=first;
		}
		node* locate(int i){
			if(first->rlink==first||first==0) return first;
			node *cur=first->rlink;
			for(int j=1;j<i;j++){
				if(cur==first) break;
				else
				cur = cur->rlink;
			}
			if(cur !=first) return cur;
			else return NULL;
		}
		bool insert(int i,int x){
			node *cur = locate(i-1);
			node *temp = first->rlink;
			if(cur == NULL) return false;
			while(temp != first){
				if(temp->data==x) return false;
				temp=temp->rlink;
			}
			node *newnode = new node;
			newnode->data=x;
			newnode->rlink = cur->rlink;
			cur->rlink=newnode;
			newnode->rlink->llink = newnode;
			newnode->llink = cur;
			return true;
		} 
		bool remove(int i){
			node *cur= locate(i);
			if(cur == NULL) return false;
			cur->rlink->llink=cur->llink;
			cur->llink->rlink=cur->rlink;
			delete cur;
			return true; 
		}
		void show(){
			node *p=first->rlink;
			if(p==first) cout<<endl;
			else{
				while(p->rlink!= first){
					printf("%d ",p->data);
					p= p->rlink;
				}
				printf("%d\n",p->data);
			}
		}
};
int main(){
	int o;
	dblist l1;
	while(cin>>o){
		if(o==0){
			l1.show();
		}
		else if(o==1){
			int i,x;
			scanf("%d %d",&i,&x);
			l1.insert(i,x);
		}
		else if(o==2){
			int i;
			scanf("%d",&i);
			l1.remove(i);
		}
	}
	return 0;
}
