# include <iostream>
using namespace std;

void shellsort(int *a,int n){
	int i,j;
	int dk=n/2;
	while(1<=dk){
	for(i=1+dk;i<=n;i++){
		if(a[i]<a[i-dk]){
			a[0]=a[i];
			for(j=i-dk;j>0&&a[0]<a[j];j-=dk)
			a[j+dk]=a[j];
			a[j+dk]=a[0];
		}
	}
	dk=dk/2;
    }
} 

int main(){
	int n,a[2000];
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	shellsort(a,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	return 0; 
}
