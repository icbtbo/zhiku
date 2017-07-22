# include <iostream> 
# include <stdio.h>
using namespace std;

class sqstack{
	private:
		int *elem;
		int top;
		int maxsize;
	public:
		sqstack(int sz):top(-1),maxsize(sz){
			elem= new int[maxsize];
		}
		bool isempty(){
			return (top==-1?true:false);
		}
		void push(int& x){
			elem[++top]=x;
		}
		bool pop(int& x){
			if(isempty()==true){
				return false;
			}
			x = elem[top--];
			return true;
		}
};
void conv(int num){
	int e;
	sqstack s(200);
	while(num){
		int temp=num%8;
		s.push(temp);
		num=num/8;
	}
	while(!s.isempty()){
		s.pop(e);
		printf("%d",e);
	}
	printf("\n");
}

int main(){
	int x;
	while(cin>>x){
		conv(x);
	}
	return 0;
}
