#include <iostream>
#include <math.h>
using namespace std;
int main(){
	long double a[8],b[8],e[5],g[5];//定义数组来存入实验数据 
	long double L,D,b1;   
	cout<<"请依次输入增重时标尺读数ri/cm:"<<endl;
	for(int i=0;i<8;i++){
		cin>>a[i];
	} 
	cout<<"请依次输入减重时标尺读数ri'/cm(从增重7kg开始)"<<endl;
	for(int i=7;i>=0;i--){
		cin>>b[i];
	}
	cout<<"请依次输入五次测得的钢丝直径/cm"<<endl;
	for(int i=0;i<5;i++){
		cin>>e[i];
	} 
	long double d_=(e[0]+e[1]+e[2]+e[3]+e[4])/5;//获得所测钢丝直径平均值
	 for(int i=0;i<5;i++){//获得钢丝直径误差 
		g[i]=abs(e[i]-d_);
	} 
  double d1=(g[0]+g[1]+g[2]+g[3]+g[4])/5;//获得平均绝对误差
	cout<<"请依次输入所测得的L,D，b:"<<endl;
	cin>>L>>D>>b1; 
	 double c[8];//用来存入平均值 
	 double d[4];//用来存入li 
	 double f[4]; //用来存入绝对误差
	double sumd=0,sumf=0;
	for(int i=0;i<8;i++){
		c[i]=(a[i]+b[i])/2;
	} 
	for(int i=0;i<4;i++){
		d[i]=c[i+4]-c[i];
		sumd+=d[i];
	}
	double l_=sumd/4.0;//获得平均读数差
	for(int i=0;i<4;i++){
		f[i]=abs(d[i]-l_);
		sumf+=f[i];
	}
	double l=sumf/4.0;
	cout<<"ri的平均值依次为："<<endl;
	for(int i=0;i<8;i++){
		cout<<c[i]<<endl;
	} 
	cout<<"读数差及其平均值依次为:"<<endl;
	for(int i=0;i<4;i++){
		cout<<d[i]<<endl;
	}
	cout<<l_<<endl; 
	cout<<"绝对误差及其平均值依次为："<<endl;
	for(int i=0;i<4;i++){
		cout<<f[i]<<endl;;
	} 
	cout<<l<<endl;
	system("pause");
	cout<<"钢丝直径平均值为："<<d_<<endl;
	cout<<"钢丝直径误差及其平均值依次为："<<endl;
	for(int i=0;i<5;i++){
		cout<<g[i]<<endl;
	} 
	cout<<d1<<endl;
	long double  t1=0.3/L,t2=0.5/D,t3=0.05/b1,t4=l/l_;
	cout<<"L的误差与L的比值为：+-"<<t1<<endl;
	cout<<"D的误差和D的比值为：+-"<<t2<<endl;
	cout<<"b的误差和b的比值为：+-"<<t3<<endl;
	cout<<"读数的平均绝对误差与平均读数差的比值："<<t4<<endl;
	long double temp1=8*4*9.8*l*D;
	long double temp2=3.14*pow(d_,2)*b1*l_;
	long double E_=temp1/temp2;
	cout<<"所求杨氏模量："<<E_<<"*10^(-4)"<<endl;
	return 0; 
} 
