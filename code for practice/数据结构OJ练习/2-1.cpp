# include <iostream>
# include <string.h>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		int b[1000];
		char a[1000][15],temp[1000][15];
		if(n== 0)
	    break;
	    for(int i=0;i<n;i++){
	    	    b[i]=0;
			    cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(strcmp(a[i],a[j])==0)
				b[i]++;
			}
		}
		int max=b[0],k=0;
		for(int i=1;i<n;i++){
			if(b[i]>max){
				max = b[i];
				k=i;
			}
		}
		int t=1;
		strcpy(temp[0],a[k]);
		int p=0;
		for(int i=0;i<n;i++){
			p=0;
			if(b[i]==b[k]){
				for(int j=0;j<i;j++){	
				    if(strcmp(a[i],a[k])==0||strcmp(a[i],a[j])==0)
				    p=1;
				}
				if(p==1||strcmp(a[i],a[k])==0) continue;
				strcpy(temp[t],a[i]);
				t++;
			}
		}
		//cout<<temp[1]<<111<<temp[0]<<endl;
		for(int i=0;i<t-1;i++){
			for(int j=0;j<t-i-1;j++){
				if(strcmp(temp[j],temp[j+1])>0){
					char c[15];
					strcpy(c,temp[j]);
					strcpy(temp[j],temp[j+1]);
					strcpy(temp[j+1],c);
				}
			}
		}
		for(int i=0;i<t;i++){
			cout<<temp[i]<<endl;
		}
	} 
	return 0;
} 
