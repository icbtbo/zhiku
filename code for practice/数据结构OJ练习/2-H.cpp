#include <iostream>
#include <stdio.h> 
#include <string.h>
using namespace std;
int i=0;
void Hanoi(int n,char A,char B,char C)
{
    if(n==1)
    {
        printf("%2d. Move disk %d from %c to %c\n",++i,n,A,C); 
    }
    else
    {
        Hanoi(n-1,A,C,B);
        printf("%2d. Move disk %d from %c to %c\n",++i,n,A,C);
        Hanoi(n-1,B,A,C);
    }
}
int main()
{
    int n;
    char A,B,C;
    A='X';B='Y';C='Z'; 
    while(cin>>n)
    {
        Hanoi(n,A,B,C);
        cout<<endl;
        i=0;
    }
    return 0;
}

