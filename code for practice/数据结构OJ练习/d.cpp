# include <iostream>
using namespace std;
int num(int x);
int order(int y,int n);
int main(){
	int n,t[100],sum[100],ordert[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i];
		sum[i]=num(t[i]);
		ordert[i]=order(t[i],sum[i]);
    }
    for(int j=0;j<n;j++){
    	cout<<sum[j]<<" "<<ordert[j]<<endl;
	}
	return 0;
} 
int num(int x){
	int sum=0;
	while(x!=0){
		x=x/10;
		sum++;
	}
	return sum;
}
int order(int y,int n){
	int a[100],temp=0;
	for(int i=0;i<n;i++){
		a[i]=y%10;
		y=y/10;
	}
	for(int i=0;i<n;i++){
		temp=a[i]+temp*10;
	}
	return temp;
}
