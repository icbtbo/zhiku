
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
//每个节点的编码
//code存储编码
//start存储编码是从code数组的第几个开始
//在编码过程中从叶子节点向根节点逆推
struct HFMcode
{
char code[MAX];
int start;
};
//建立哈夫曼树
void createHFMtree(HFMnode *node,int n)
{
int i;
//m1,m2为当前还没用到的节点中权值最小和次小的权值
int m1,m2;
//l,r为每次构建一个父节点其左右儿子节点的序号
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
//求每个节点的哈夫曼编码
void createHFMcode(HFMnode *node, HFMcode *hcode,int n)
{
int i;
for(i=1;i<=n;i++)
{
HFMcode d;
//哈夫曼树最大层数就是元素的个数
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
//打印每个节点的编码
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
//建立哈夫曼树
createHFMtree(node,n);
//求每个节点的哈夫曼编码
createHFMcode(node,hcd,n);
//打印每个节点的编码
printHFMcode(node,hcd,n);
return 0;
} 
