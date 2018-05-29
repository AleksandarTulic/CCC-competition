#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool swapp(string g, int start, int curr)
{
    for (int i=start;i<curr;i++)
        if (g[i]==g[curr]) return false;
    return true;
}

void permutations(string g, int index, int n)
{
    if (index>=n)
    {
        printf("%s\n",g.c_str());
        return;
    }

    for (int i=index;i<n;i++)
    {
        if (swapp(g,index,i))
        {
            swap(g[index],g[i]);
            permutations(g,index+1,n);
            swap(g[index],g[i]);
        }
    }
}

int main()
{
    int tests;
    scanf("%d",&tests);

    while (tests--)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        printf("The bit patterns are\n");

        if (n==k)
        {
            for (int i=0;i<n;i++) printf("1");
            printf("\n");
        }
        else if (n==1)
        {
            if (k==1) printf("1\n");
            else printf("0\n");
        }
        else
        {
            string g="";
            for (int i=0;i<k;i++) g+='1';
            for (int i=k+1;i<=n;i++) g+='0';

            permutations(g,0,g.size());
            printf("\n");
        }
    }
    return 0;
}
