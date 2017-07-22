# include <iostream>
# include <string.h>
using namespace std;

struct linknode{
	int data;
	linknode *next;
};

class stack{
	private:
		linknode *top;
	public:
		stack(){
			top=NULL;
		}
		void push(int x){
			linknode *ptr = new linknode;
			ptr->data = x;
			ptr->next = top;
			top = ptr;
		}
		bool pop(){
			if(top == NULL) return false;
			linknode* ptr = top->next;
			delete top;
			top = ptr;
			return true;
		}
		linknode* stacktop(){
			return top;
		}
};

int main(){
	char a[2000];
	while(cin>>a){
		stack s;
		int length = strlen(a);
		for(int i=0;i<length-1;i++){
			if(a[i]=='(')
			s.push(i);
			else if(a[i]==')')
			s.pop();
			else if(a[i]=='G')
			break;
		}
		int i=0;
		while(s.stacktop()!=NULL){
			i++;
			s.pop();
		}
		cout<<i<<endl;
	}
	return 0;
} 
