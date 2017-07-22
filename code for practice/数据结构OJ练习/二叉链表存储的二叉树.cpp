#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
  
char array[101];  
  
//���������  
typedef struct BiTNode{  
    char data;  
    struct BiTNode *lchild,*rchild;  
}BiTNode,*BiTree;  
  
//���������д���������  
int CreateBiTree(BiTree &T,int &index,int &n){  
    if(index >= n){  
        return 0;  
    }  
    //�������������������н���ֵ��һ���ַ������ո��ʾ����  
    if(array[index] == ' '){  
        T = NULL;  
        index++;  
    }  
    else{  
        //T = (BiTree)malloc(sizeof(BiTNode));  
        T = new BiTNode;
        //���ɸ����  
        T->data = array[index];  
        index++;  
        //����������  
        CreateBiTree(T->lchild,index,n);  
        //����������  
        CreateBiTree(T->rchild,index,n);  
    }  
    return 0;  
}  
//���  
void Visit(BiTree T){  
    printf("%c ",T->data);  
}  
//�������  
void PreOrder(BiTree T){  
    if(T != NULL){  
        //���ʸ��ڵ�  
        Visit(T);  
        //�������ӽ��  
        PreOrder(T->lchild);  
        //�������ӽ��  
        PreOrder(T->rchild);  
    }  
}  
//�������  
void InOrder(BiTree T){  
    if(T != NULL){  
        //�������ӽ��  
        InOrder(T->lchild);  
        //���ʸ��ڵ�  
        Visit(T);  
        //�������ӽ��  
        InOrder(T->rchild);  
    }  
}  
//�������  
void PostOrder(BiTree T){  
    if(T != NULL){  
        //�������ӽ��  
        PostOrder(T->lchild);  
        //�������ӽ��  
        PostOrder(T->rchild);  
        //���ʸ��ڵ�  
        Visit(T);  
    }  
}  
int main()  
{  
    int len,index;  
    while(gets(array)){  
        BiTree T;  
        len = strlen(array);  
        index = 0;  
        //����������  
        CreateBiTree(T,index,len);  
        //�������  
        PreOrder(T);  
        printf("\n");  
        //�������  
        index = 0;  
        InOrder(T);  
        printf("\n");  
        //�������  
        index = 0;  
        InOrder(T);  
        printf("\n");  
    }  
    return 0;  
}  
