# include <iostream>
# include <string.h>
using namespace std;
int main(){
	char a[100];
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>'u'||(a[i]>85&&a[i]<91)){
			a[i]=a[i]-21;
		}
		else
		a[i]=a[i]+5;
	}
	cout<<a<<endl;
	return 0;
}
