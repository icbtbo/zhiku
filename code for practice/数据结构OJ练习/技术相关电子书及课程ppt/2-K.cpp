# include <iostream>
# include <string.h>

using namespace std;

int main(){
	char a[300],t[200];
	memset(a,0,300);
	memset(t,0,200);
    int i;
	cin>>a>>t>>i;
	int lena=strlen(a),lent=strlen(t);
	if(i>=1&&i<=lena+1){
	for(int j=lena-1;j>=i-1;j--){
		a[j+lent]=a[j];
	}
	int m=0;
	for(int k=i-1;k<i-1+lent;k++){
	    a[k]=t[m];
		m++;
		if(m+1>lent) break;	
	}
        cout<<a;
    } 
	return 0;
} 
