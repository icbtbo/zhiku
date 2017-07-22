# include <iostream>
# include <string.h>
using namespace std;

int Index(char S[],char T[]){  
    int i=1,j=1;  
    while(i<=strlen(S)&&j<=strlen(T))  
    {  
       cout<<S[i-1];
       if(S[i-1]==T[j-1])  
       {  
          ++i;++j;  
       }  
       else  
       {  
          i=i-j+2;  
          j=1;  
       }  
    }
    cout<<endl;
    if(j==(strlen(T)+1)) return i-strlen(T);  
    else return 0;  
}  
int main(){
	char a[200],b[200];
	char t[200];
	int n=3;
	memset(a,0,200);
	memset(b,0,200);
	memset(t,0,200);
	while(n--){
		cin>>a>>b;
		cout<<Index(a,b)<<endl;
	}
	return 0;
} 
       
