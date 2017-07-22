#include<stdio.h>  
#include <iostream>
using namespace std;
#include<stdlib.h>  
#include<string.h>  
#define MAXSTRLEN 100  
typedef struct  
{  
    char *ch;  
}HString;  
  
void InitString(HString *T);  
void StrAssign(HString *T,char charb[]);  
void Get_next(HString *T,int next[]);  
void print(HString *T,int next[]);  
  
void InitString(HString *T)  
{  
    T->ch='\0';  
    return ;  
}  
void StrAssign(HString *T,char charb[])  
{  
    int i,len;  
    if(T->ch)  
        free(T->ch);  
    len=strlen(charb);  
    if(!charb)  
    {  
        T->ch='\0';  
    }  
    else  
    {  
        T->ch=(char *)malloc((len+1)*sizeof(char));  
            for(i=0;i<len;i++)  
            {  
                T->ch[i+1]=charb[i];  
            }  
            T->ch[0]=len;  
    }  
}  
void Get_next(HString *T,int next[])  
{  
    int i=1;  
    next[1]=0;  
    int j=0;  
    while(i<T->ch[0])  
    {  
        if(j==0||T->ch[i]==T->ch[j])  
        {  
            ++i;  
            ++j;  
            next[i]=j;  
        }  
        else  
            j=next[j];  
    }    
}  
/*void print(HString *T,int next[])  
{  
    int i;  
    for(i=1;i<=T->ch[0];i++)  
    {  
        printf("%d ",next[i]);  
    }   
}  */
int Index_KMP(HString *S,HString *T,int next[])  
{  
    int i=1,j=1;  
    while(i<=S->ch[0]&&j<=T->ch[0])  
    {  
        if(S->ch[i]==T->ch[j])  
        {  
            ++i;  
            ++j;  
        }  
        else  
        {  
            j=next[j];  
            if(j==0)  
            {  
                i++;  
                j=1;  
            }  
        }  
    }  
    if(j==T->ch[0]+1)  
        return i-T->ch[0];  
    else  
        return 0;  
}  
int main()  
{  
    int i,pos;  
    int  Next[100];  
    char chara[101];  
    char charb[101];  
    HString S,T;  
    for(i=0;i<3;i++)  
    {  
        InitString(&S);  
        InitString(&T);  
        scanf("%s%s",chara,charb);  
        StrAssign(&S,chara);  
        StrAssign(&T,charb);  
        Get_next(&T,Next);  
        pos=Index_KMP(&S,&T,Next);  
        printf("%d\n",pos);  
    }
    return 0;  
  
}  
