
#include<iostream>
#define MAX 200
using namespace std;
typedef char valType;
typedef double wghType;
struct HFMnode
{
valType data;
wghType weight;
int parent;
int lchild;
int rchild;
};
//ÿ���ڵ�ı���
//code�洢����
//start�洢�����Ǵ�code����ĵڼ�����ʼ
//�ڱ�������д�Ҷ�ӽڵ�����ڵ�����
struct HFMcode
{
char code[MAX];
int start;
};
//������������
void createHFMtree(HFMnode *node,int n)
{
int i;
//m1,m2Ϊ��ǰ��û�õ��Ľڵ���Ȩֵ��С�ʹ�С��Ȩֵ
int m1,m2;
//l,rΪÿ�ι���һ�����ڵ������Ҷ��ӽڵ�����
int l,r;
for(i=n+1;i<=2*n-1;i++)
{
m1=m2=32767;
l=r=0;
int k;
for(k=1;k<=i-1;k++)
if(node[k].parent==0)
{
if(node[k].weight<m1)
{
//m2 =m1;
//r = l;
m1 = node[k].weight;
l = k;
}
//else if(node[k].weight<m2)
//{
//m2 = node[k].weight;
//r = k;
//}
}
for(k=1;k<=i-1;k++)
if(node[k].parent==0)
{
if(node[k].weight<m2)
{
	if(k==l) continue;
	m2 = node[k].weight;
	r = k; 
}
} 
for(k=1;k<=i-1;k++){
	if(k == l) break;
	else if(k == r){
		int t=r;
		r=l;
		l=t;
		break;
		
	}
}
node[i].weight = node[l].weight + node[r].weight;
node[i].lchild = l;
node[i].rchild = r;
node[l].parent = i;
node[r].parent = i;
}
}
//��ÿ���ڵ�Ĺ���������
void createHFMcode(HFMnode *node, HFMcode *hcode,int n)
{
int i;
for(i=1;i<=n;i++)
{
HFMcode d;
//������������������Ԫ�صĸ���
d.start = n;
int num=i;
int father = node[num].parent;
while(father!=0)
{
if(node[father].lchild==num)
d.code[d.start--]='0';
else
d.code[d.start--]='1';
num = father;
father = node[num].parent;
}
hcode[i]=d;
}
}
//��ӡÿ���ڵ�ı���
void printHFMcode(HFMnode * node,HFMcode * hcode,int n)
{
int i;
for(i=1;i<=n;i++)
{
for(int k = hcode[i].start+1; k<=n;k++)
cout<<hcode[i].code[k];
cout<<endl;
}
}
int main(){
	HFMnode node[500];
    HFMcode hcd[250];
int n;
cin>>n;
int i;
for(i=1;i<=n;i++)
{
cin>>node[i].weight;
}
for(i=1;i<=2*n-1;i++)
{
node[i].parent=node[i].lchild=node[i].rchild=0;
}
//������������
createHFMtree(node,n);
//��ÿ���ڵ�Ĺ���������
createHFMcode(node,hcd,n);
//��ӡÿ���ڵ�ı���
printHFMcode(node,hcd,n);
return 0;
} 
