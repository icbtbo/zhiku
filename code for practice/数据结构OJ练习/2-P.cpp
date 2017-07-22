# include <iostream>
# include <stdio.h>
 
using namespace std;
#define MAXSIZE 12500
int num[MAXSIZE+1],cpot[MAXSIZE+1];
struct Triple{
	int i,j;//非零元素得行号，列号
	int e;//非零元素的值 
}; 
struct TSMatrix
{  
    Triple data[MAXSIZE+1];//非零元素三元组，data[0]未用  
    int mu,nu,tu;//矩阵的行数，列数，非零元素的个数  
};  

TSMatrix CreatSMatrix(TSMatrix M)  
{  
    int p,q,k,a;  
    M.tu=0,k=1;  
    for( p=1;p<=M.mu;p++)  
        for( q=1;q<=M.nu;q++)  
        {  
            scanf("%d",&a);  
            if(a!=0)  
            {  
                M.data[k].i=p;  
                M.data[k].j=q;  
                M.data[k].e=a;  
                k++;  
                M.tu++;  
            }  
         }  
         return M;  
} 
TSMatrix TransposeSMatrix(TSMatrix M,TSMatrix T)  
{  
    int col,t,p,q;  
    T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;  
    if(T.tu)  
    {  
        for(col=1;col<=M.nu;++col) num[col]=0;  
        for(t=1;t<=M.tu;t++)  ++num[M.data[t].j];  
        cpot[1]=1;  
        for(col=2;col<=M.tu;col++)  cpot[col]=cpot[col-1]+num[col-1];  
        for(p=1;p<=M.tu;p++)  
        {  
            col=M.data[p].j;  
            q=cpot[col];  
            T.data[q].i=M.data[p].j;  
            T.data[q].j=M.data[p].i;  
            T.data[q].e=M.data[p].e;  
            ++cpot[col];  
        }  
  
    }  
    return T;  
}
int main()  
{  
    int k=1,p,q;  
    TSMatrix M,T;  
    scanf("%d%d",&M.mu,&M.nu);  
    M=CreatSMatrix(M);  
    T=TransposeSMatrix(M,T);  
    for(p=1;p<=T.mu;p++)  
    {  
        for(q=1;q<=T.nu;q++)  
        {  
           if(T.data[k].i==p&&T.data[k].j==q)  
           {  
                printf("%d ",T.data[k].e);  
                k++;  
           }  
           else  
                printf("0 ");  
        }  
        printf("\n");  
    }  
    return 0;  
}  
