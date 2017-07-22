# include <iostream>
using namespace std;
int main(){
	int a[10],h;
	while(cin>>a[0]){
	int	sum=0;
	for(int i=1;i<10;i++)
	cin>>a[i];
	cin>>h;
	for(int i=0;i<10;i++){
		if(h+30>=a[i])
		sum++;
	}
	cout<<sum<<endl;
    }
    return 0;
} 
