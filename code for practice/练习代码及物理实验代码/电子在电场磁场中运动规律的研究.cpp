#include <iostream>
using namespace std;

int main() {
	cout<<"�밴ʵ�����ϴ������ң����ϵ��µ�˳����������"<<endl; 
	//��һ�����
	float a[5];
	for(int i=0;i<5;i++){
		cin>>a[i];
	} 
	float t=600.00;
	for(int i=0;i<5;i++){
		cout<<t/a[i]<<" ";
		t+=100;
	} 
	//�ڶ��� ���ĸ�������������ʽ��һ�� 
	//�ڶ������
	float vl[10],vr[10],temp[10],s=5.00;  //vl ��ʾƫתλ��Ϊ��ĵ�ѹ��vr�෴ 
	for(int i=0;i<10;i++){
		cin>>vl[i]>>vr[i];
		temp[i]=s/((vl[i]+vr[i])/2);
		s+=5;
	} 
	 for(int i=0;i<10;i++){
	 	cout<<"�����ȷֱ�Ϊ��"<<endl; //˳��������Ҵ������� 
		cout<<temp[i]<<endl;
	} 
	float sum6=0,sum8=0;
	for(int i=0;i<10;i++){
		if(i<5)
		sum6+=temp[i];
		else
		sum8+=temp[i];
	}
	cout<<"v2Ϊ600��800ʱ��ƽ�������ȷֱ�Ϊ��"<<sum6/5<<" "<<sum8/5<<endl;
	//���������
	s=5.00;
	for(int i=0;i<10;i++){
		cin>>vl[i]>>vr[i];
		temp[i]=s/((vl[i]+vr[i])/2);
		s+=5;
	} 
	 for(int i=0;i<10;i++){
	 	cout<<"�����ȷֱ�Ϊ��"<<endl; 
		cout<<temp[i]<<endl;
	} 
	sum6=0,sum8=0;
	for(int i=0;i<10;i++){
		if(i<5)
		sum6+=temp[i];
		else
		sum8+=temp[i];
	}
	cout<<"v2Ϊ600��800ʱ��ƽ�������ȷֱ�Ϊ��"<<sum6/5<<" "<<sum8/5<<endl;
	//���ĸ���� 
	s=5.00;
	for(int i=0;i<10;i++){
		cin>>vl[i]>>vr[i];
		temp[i]=s/((vl[i]+vr[i])/2);
		s+=5;
	} 
	 for(int i=0;i<10;i++){
	 	cout<<"�����ȷֱ�Ϊ��"<<endl; 
		cout<<temp[i]<<endl;
	} 
	sum6=0,sum8=0;
	for(int i=0;i<10;i++){
		if(i<5)
		sum6+=temp[i];
		else
		sum8+=temp[i];
	}
	cout<<"v2Ϊ600��800ʱ��ƽ�������ȷֱ�Ϊ��"<<sum6/5<<" "<<sum8/5<<endl;
	return 0;
}
