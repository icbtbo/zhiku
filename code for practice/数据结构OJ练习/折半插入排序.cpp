# include <iostream>
using namespace std;

void search(int *a,int n){
	int i,j,low,high,mid;
	for(i=2;i<=n;i++){
		a[0]=a[i];
		low=1;
		high=i-1;
		while(low<=high){
			mid=(low+high)/2;
			if(a[0]<a[mid])
			high=mid-1;
			else
			low=mid+1;
		}
		for(j=i-1;j>=high+1;j--)
		a[j+1]=a[j];
		a[high+1]=a[0];
	}
} 

int main(){
	int n,a[2000];
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	search(a,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	return 0;
}
