#include<cstdio>
#include<algorithm>
using namespace std;
 
const int maxn = 200000 + 10;
int par[maxn];
int rank[maxn];
 
struct node
{
    int x,y;
    int val;
    bool operator <(const node&other)const
    {
        return val<other.val;
    }
}a[maxn];
 
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rank[i]=0;
    }
}
 
int find(int n)
{
    if(par[n]==n) return n;
    return par[n]=find(par[n]);
}
 
void unit(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rank[x]<rank[y])
    {
        par[x]=y;
    }
    else
    {
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
 
bool same(int x,int y)
{
    return find(x)==find(y);
}
 
int main()
{
    int n,i,j,temp;
    scanf("%d",&n);
        int k=0;
        int cost=0;
        init(n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&temp);
                if(temp&&i>j)
                {
                    a[k].x=i;
                    a[k].y=j;
                    a[k].val=temp;
                    k++;
                }
            }
        }
        sort(a,a+k);
        for(i=0;i<k;i++)
        {
            if(!same(a[i].x,a[i].y))
            {
                unit(a[i].x,a[i].y);
                cost+=a[i].val;
            }
        }
        printf("%d\n",cost);
    return 0;
}

