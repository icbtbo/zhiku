# include <iostream>
# include <stdio.h>
# include <string>
# include <string.h>
using namespace std;
struct node{
	int data;
	node* next;
}; 
class list{
	private:
		node *first;
	public:
		list(){//初始化 
			first = new node;
			first->next = NULL;
		}
		void input(int x){//输入 
			for(int i=x;i>0;i--){
				node *p=new node;
				scanf("%d",&p->data);
				p->next=first->next;
				first->next=p;
			}
		}
		node* locate(int n){//定位 
			if(n<0) return NULL;
			node *cur=first;
			int k=0;
			while(cur!=NULL&&k<n){
				cur=cur->next;
				k++;
			}
			return cur;
		}
		void insert(int n,int x){//插入（前插） 
			node *cur=locate(n-1);
			if(cur==NULL) printf("insert fail\n");
			else{
			node *newnode=new node;
			newnode->data=x;
			newnode->next=cur->next;
			cur->next=newnode;
			printf("insert OK\n");
		    }
		}
		void Delete(int n){//删除 
			node* cur=locate(n-1);
			if(cur==NULL||cur->next==NULL) printf("delete fail\n");
			else{
			node *del=cur->next;
			cur->next=del->next;
			delete del;
			printf("delete OK\n");
		    }
		}
		void get(int x){//输出第x个数 
			node* cur=locate(x);
			if(cur==NULL) printf("get fail\n");
			else
			printf("%d\n",cur->data);
		}
		void show(){//输出链表中所有数 
			node* cur=first->next;
			if(cur==NULL) printf("Link list is empty\n");
			else{
			while(cur->next!=NULL){
				printf("%d ",cur->data);
				cur=cur->next;
			}
			printf("%d\n",cur->data);
		    }
		}
};
int main(){
	int x,m=0,num;
	scanf("%d",&x);
	char option[10];
	list l1;
	l1.input(x);
	scanf("%d",&num);
	while(m<num){
		scanf("%s",&option);
		if(strcmp(option,"show")==0){
			l1.show();
		}
		else if(strcmp(option,"get")==0){
			int x;
			scanf("%d",&x);
			l1.get(x);
		}
		else if(strcmp(option,"insert")==0){
			int a,b;
			scanf("%d %d",&a,&b);
			l1.insert(a,b);
		}
		else if(strcmp(option,"delete")==0){
			int x;
			scanf("%d",&x);
			l1.Delete(x);
		}
		m++;
	}
	return 0;
}

