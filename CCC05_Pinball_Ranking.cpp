#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;

int n;
vector <int> fenwick(1e5+1,0);
vector <int> a,b;

int upit(int x)
{
    int res = 0;
    for (;x>0;x-=x&-x)
        res+=fenwick[x];
    return res;
}

void ubaci(int x)
{
    for (;x<=100000;x+=x&-x)
        fenwick[x]++;
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int q; cin>>q;
        a.push_back(q);
        b.push_back(q);
    }

    sort(b.begin(),b.end());
    map <int, int> pos;

    int poz = 1;
    for (int i=0;i<n;i++)
    {
        int it = -1;
        it=pos.count(b[i]);

        if ( it != -1 ) pos[b[i]]=poz;
        poz++;
    }

    double rez = 0.0;
    int br = 1;
    for (int i=0;i<n;i++)
    {
        ubaci(pos[a[i]]);
        rez+=(br-upit(pos[a[i]])+1);
        br++;
    }

    cout<<setprecision(2)<<fixed<<rez/n<<endl;
    return 0;
}
