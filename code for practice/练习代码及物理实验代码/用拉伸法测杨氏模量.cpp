#include <iostream>
#include <math.h>
using namespace std;
int main(){
	long double a[8],b[8],e[5],g[5];//��������������ʵ������ 
	long double L,D,b1;   
	cout<<"��������������ʱ��߶���ri/cm:"<<endl;
	for(int i=0;i<8;i++){
		cin>>a[i];
	} 
	cout<<"�������������ʱ��߶���ri'/cm(������7kg��ʼ)"<<endl;
	for(int i=7;i>=0;i--){
		cin>>b[i];
	}
	cout<<"������������β�õĸ�˿ֱ��/cm"<<endl;
	for(int i=0;i<5;i++){
		cin>>e[i];
	} 
	long double d_=(e[0]+e[1]+e[2]+e[3]+e[4])/5;//��������˿ֱ��ƽ��ֵ
	 for(int i=0;i<5;i++){//��ø�˿ֱ����� 
		g[i]=abs(e[i]-d_);
	} 
  double d1=(g[0]+g[1]+g[2]+g[3]+g[4])/5;//���ƽ���������
	cout<<"��������������õ�L,D��b:"<<endl;
	cin>>L>>D>>b1; 
	 double c[8];//��������ƽ��ֵ 
	 double d[4];//��������li 
	 double f[4]; //��������������
	double sumd=0,sumf=0;
	for(int i=0;i<8;i++){
		c[i]=(a[i]+b[i])/2;
	} 
	for(int i=0;i<4;i++){
		d[i]=c[i+4]-c[i];
		sumd+=d[i];
	}
	double l_=sumd/4.0;//���ƽ��������
	for(int i=0;i<4;i++){
		f[i]=abs(d[i]-l_);
		sumf+=f[i];
	}
	double l=sumf/4.0;
	cout<<"ri��ƽ��ֵ����Ϊ��"<<endl;
	for(int i=0;i<8;i++){
		cout<<c[i]<<endl;
	} 
	cout<<"�������ƽ��ֵ����Ϊ:"<<endl;
	for(int i=0;i<4;i++){
		cout<<d[i]<<endl;
	}
	cout<<l_<<endl; 
	cout<<"��������ƽ��ֵ����Ϊ��"<<endl;
	for(int i=0;i<4;i++){
		cout<<f[i]<<endl;;
	} 
	cout<<l<<endl;
	system("pause");
	cout<<"��˿ֱ��ƽ��ֵΪ��"<<d_<<endl;
	cout<<"��˿ֱ������ƽ��ֵ����Ϊ��"<<endl;
	for(int i=0;i<5;i++){
		cout<<g[i]<<endl;
	} 
	cout<<d1<<endl;
	long double  t1=0.3/L,t2=0.5/D,t3=0.05/b1,t4=l/l_;
	cout<<"L�������L�ı�ֵΪ��+-"<<t1<<endl;
	cout<<"D������D�ı�ֵΪ��+-"<<t2<<endl;
	cout<<"b������b�ı�ֵΪ��+-"<<t3<<endl;
	cout<<"������ƽ�����������ƽ��������ı�ֵ��"<<t4<<endl;
	long double temp1=8*4*9.8*l*D;
	long double temp2=3.14*pow(d_,2)*b1*l_;
	long double E_=temp1/temp2;
	cout<<"��������ģ����"<<E_<<"*10^(-4)"<<endl;
	return 0; 
} 
