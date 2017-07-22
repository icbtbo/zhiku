# include <iostream>
#include <stdio.h>  
#include <string.h>  
using namespace std;
const int maxlen=100;  
int Index(char S[],char T[]);  
int main()  
{  
   char pattern[maxlen];  
   char source[maxlen];  
   while(scanf("%s  %s",source,pattern)!=EOF)  
   {  
       printf("%d\n",Index(source,pattern));  
   }  
   return 0;  
}  
int Index(char S[],char T[])  
{  
    int i=1,j=1;  
    while(i<=strlen(S)&&j<=strlen(T))  
    {  
       if(S[i-1]==T[j-1])  
       {  
          ++i;++j;  
       }  
       else  
       {  
          i=i-j+2;  
          j=1;  
       }  
    }  
    if(j==(strlen(T)+1)) return i-strlen(T);  
    else return 0;  
}  
