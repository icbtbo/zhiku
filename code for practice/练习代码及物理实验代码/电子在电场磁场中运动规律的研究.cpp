#include <iostream>
using namespace std;

int main() {
	cout<<"请按实验书上从左至右，从上到下的顺序输入数据"<<endl; 
	//第一个表格
	float a[5];
	for(int i=0;i<5;i++){
		cin>>a[i];
	} 
	float t=600.00;
	for(int i=0;i<5;i++){
		cout<<t/a[i]<<" ";
		t+=100;
	} 
	//第二至 第四个表格输入输出方式都一样 
	//第二个表格
	float vl[10],vr[10],temp[10],s=5.00;  //vl 表示偏转位移为左的电压，vr相反 
	for(int i=0;i<10;i++){
		cin>>vl[i]>>vr[i];
		temp[i]=s/((vl[i]+vr[i])/2);
		s+=5;
	} 
	 for(int i=0;i<10;i++){
	 	cout<<"灵敏度分别为："<<endl; //顺序从左至右从上至下 
		cout<<temp[i]<<endl;
	} 
	float sum6=0,sum8=0;
	for(int i=0;i<10;i++){
		if(i<5)
		sum6+=temp[i];
		else
		sum8+=temp[i];
	}
	cout<<"v2为600和800时的平均灵敏度分别为："<<sum6/5<<" "<<sum8/5<<endl;
	//第三个表格
	s=5.00;
	for(int i=0;i<10;i++){
		cin>>vl[i]>>vr[i];
		temp[i]=s/((vl[i]+vr[i])/2);
		s+=5;
	} 
	 for(int i=0;i<10;i++){
	 	cout<<"灵敏度分别为："<<endl; 
		cout<<temp[i]<<endl;
	} 
	sum6=0,sum8=0;
	for(int i=0;i<10;i++){
		if(i<5)
		sum6+=temp[i];
		else
		sum8+=temp[i];
	}
	cout<<"v2为600和800时的平均灵敏度分别为："<<sum6/5<<" "<<sum8/5<<endl;
	//第四个表格 
	s=5.00;
	for(int i=0;i<10;i++){
		cin>>vl[i]>>vr[i];
		temp[i]=s/((vl[i]+vr[i])/2);
		s+=5;
	} 
	 for(int i=0;i<10;i++){
	 	cout<<"灵敏度分别为："<<endl; 
		cout<<temp[i]<<endl;
	} 
	sum6=0,sum8=0;
	for(int i=0;i<10;i++){
		if(i<5)
		sum6+=temp[i];
		else
		sum8+=temp[i];
	}
	cout<<"v2为600和800时的平均灵敏度分别为："<<sum6/5<<" "<<sum8/5<<endl;
	return 0;
}
