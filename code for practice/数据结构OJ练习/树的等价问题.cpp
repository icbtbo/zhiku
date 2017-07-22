#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<malloc.h>  
#include<math.h>  
typedef struct{  
    int data;  
    int parent;  
    int lchild;  
    int rchild;  
}tree;  
int n,k;  
tree tr[101];  
int find(tree tr[],int i){  
    int j;  
    if(i<1||i>n) return -1;  
    for(j=i;tr[j].parent>0;j=tr[j].parent);  
    return j;  
}  
int main(){  
    while(~scanf("%d %d",&n,&k)){  
        int i,j;  
        for(i=1;i<=n;i++){  
                tr[i].data=i;  
            tr[i].parent=-1;  
        }  
        int x,y;  
        int root1,root2;  
        for(i=0;i<k;i++){  
            scanf("%d %d",&x,&y);  
            for(j=0;j<101;j++){  
                if(tr[j].data==x){  
                    root1=find(tr,j);  
                    //printf("%d\n",root1);  
                }  
                if(tr[j].data==y){  
                    root2=find(tr,j);  
                    //printf("%d\n",root2);  
                }  
            }  
            tr[root2].parent=root1;  
        }  
        int num1,num2;  
        scanf("%d %d",&num1,&num2);  
        root1=find (tr,num1);  
        root2=find(tr,num2);  
        if(root1==root2)  
            printf("YES\n");  
        else  
            printf("NO\n");  
    }  
    return 0;  
} 
