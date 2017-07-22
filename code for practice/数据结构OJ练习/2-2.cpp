# include <iostream>
using namespace std;

int main(){
	int n,a,start,t;
	while(cin>>n){
		start=0;
		t=0;
		if(n==0) break;
	    while(n--){
	    	cin>>a;
	    	if(a>start)
	    	t=(a-start)*6+5+t;
	    	else if(a<start)
	    	t=(start-a)*4+5+t;
	    	start=a;
		}
		cout<<t<<endl;
	}
	return 0;
}
