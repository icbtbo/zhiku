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
void print(HString *T,int next[])  
{  
    int i;  
    for(i=1;i<=T->ch[0];i++)  
    {  
        printf("%d ",next[i]);  
    }   
}  
int main()  
{  
    int Next[MAXSTRLEN];  
    char chara[MAXSTRLEN];  
    scanf("%s",chara);  
    HString S;  
    InitString(&S);  
    StrAssign(&S,chara);  
    Get_next(&S,Next);  
    print(&S,Next);  
    return 0;  
  
}  
