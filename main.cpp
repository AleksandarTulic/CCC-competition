#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

int n;
int bit[100001];
int a[100001];

int query(int x)
{
    int res = 0;
    for (int i=x;i>0;i-=(i&-i))
        res+=bit[i];
    return res;
}

void update(int x, int b)
{
    for (int i=x;i<=n;i+=(i&-i))
        bit[i]+=b;
        cout<<endl;
    for (int i=1;i<=n;i++) cout<<bit[i]<<" ";cout<<endl;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int d;
        scanf("%d",&d);

        a[d]=i;
        update(i,1);
    }

    int brl = 1;
    int brd = n;

    for (int i=1;i<=n;i++)
    {
        if ( i%2 == 1 )
        {
            update(a[brl],-1);
            cout<<query(a[brl])-query(0)<<endl;
            brl++;
        }
        else
        {
            update(a[brd],-1);
            cout<<query(n)-query(a[brd]-1)<<endl;
            brd--;
        }
    }
    return 0;
}
