#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <utility>

using namespace std;

struct graf{ int x,y; };

int n;
vector <graf> g;
int broj=200000000;

void toreach(int poc, int kraj, int br, int nrad)
{
    if ( nrad == poc && br != 0 ) return;
    if ( poc == kraj ) {broj=min(broj,br); return;}

    for (int i=0;i<g.size();i++)
       if ( g[i].x == poc ) toreach(g[i].y,kraj,br+1,nrad);
    return;
}

int main()
{
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        g.push_back({a,b});
    }

    int a,b;
    cin>>a>>b;

    while (a!=0 && b!=0)
    {
        broj=200000000;
        toreach(a,b,0,a);

        if ( broj == 200000000 ) cout<<"No"<<endl;
        else
        {
            int d=broj;
            broj=200000000;
            toreach(b,a,0,b);

            if (broj == 200000000) cout<<"No"<<endl;
            else cout<<"Yes "<<d-1<<endl;
        }

        cin>>a>>b;
    }
    return 0;
}
