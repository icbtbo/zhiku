# include <iostream>
# include <string.h> 
#include <cstdio>    
#include <cstring>    
#include <cstdlib>
using namespace std;

int main(){
    int a,b;    
    char c[5],op,e;    
    int cnt=0;    
    while(cin>>a>>op>>b>>e>>c)    
    {     
        int ans;    
        if(c[0]!='?')    
            ans=atoi(c);    
        else   
            continue;    
        if(op=='+')    
        {    
            if(a+b==ans)    
                cnt++;    
        }    
        else if(op=='-')    
        {    
            if(a-b==ans)    
                cnt++;    
        }    
    }    
    cout<<cnt<<endl;    
    return 0;    
}
