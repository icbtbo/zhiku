# include <iostream>
using namespace std;
int main(){
	int n,sum[10];
	char a[10][10];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int temp[6];
        temp[0]=a[i][0]-'0';
        temp[1]=a[i][1]-'0';
        temp[2]=a[i][3]-'0';
        temp[3]=a[i][4]-'0';
        temp[4]=a[i][6]-'0';
        temp[5]=a[i][7]-'0';
        sum[i]=temp[0]*36000+temp[1]*3600+temp[2]*600+temp[3]*60+temp[4]*10+temp[5]; 
	}
	for(int i=0;i<n;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
}
