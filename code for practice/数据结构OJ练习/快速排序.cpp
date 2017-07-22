#include<iostream>
using namespace std;
void quickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // 递归调用  
        quickSort(s, i + 1, r);  
    }  
}  
int main()
{
	int n,L[200000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>L[i];
	quickSort(L,0,n-1);
	for(int i=0;i<n;i++)
		cout<<L[i]<<" ";
	cout<<endl;
	return 0;
}

