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
		bool pop(int& x){
			if(top == NULL) return false;
			linknode* ptr = top->next;
			x= top->data;
			delete top;
			top = ptr;
			return true;
		}
		linknode* stacktop(){
			return top;
		}
};

int main(){
	int n;
	cin>>n;
	while(n--){
		stack sr,sg,sb;
		char a[1000];
		int b[1000]={0};
		cin>>a;
		int length = strlen(a);
		for(int i=0;i<length;i++){
			if(a[i]=='('){
			    sr.push(i+1);
		        b[i]=4;
		    }
			else if(a[i]=='<'){
				sg.push(i+1);
				b[i]=4;
			}
			else if(a[i]=='['){
				sb.push(i+1);
				b[i]=4;
			}
			else if(a[i]==')'){
				b[i]=4;
				int x;
				if(sr.pop(x)==true){
					for(int j=x;j<i;j++){
					    if(b[j]==0)
					    b[j]=1; 
					} 
				}
			}
			else if(a[i]=='>'){
				b[i]=4;
				int x;
				if(sg.pop(x)==true){
					for(int j=x;j<i;j++){
						if(b[j]==0)
						b[j]=2;
					}
				}
			}
			else if(a[i]==']'){
				b[i]=4;
				int x;
				if(sb.pop(x)==true){
					for(int j=x;j<i;j++){
						if(b[j]==0)
						b[j]=3;
					}
				}
			}
		}
		int re=0,gr=0,bl=0;
		for(int i=0;i<1000;i++){
			if(b[i]==1)
			re++;
			else if(b[i]==2)
			gr++;
			else if(b[i]==3)
			bl++;
		}
		cout<<re<<" "<<gr<<" "<<bl<<endl;
		//for(int i=0;i<14;i++)
		//cout<<b[i];
	}
	return 0;
}
