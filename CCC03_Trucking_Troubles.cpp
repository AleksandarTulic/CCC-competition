#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <utility>

using namespace std;

int main()
{
    int c,r,d;
    cin>>c>>r>>d;

    vector <vector <pair<int, int> > > lis;
    const int inf = 2e9;

    pair <pair<int, int>, int> graf[r];
    for (int i=0;i<r;i++) cin>>graf[i].first.first>>graf[i].first.second>>graf[i].second;

    for (int i=1;i<=c;i++)
    {
        vector <pair<int, int> > ele;
        if ( i == 1 ) lis.push_back(ele);
        for (int j=0;j<r;j++)
            if ( graf[j].first.first == i || graf[j].first.second == i ) ele.push_back({i,graf[j].second});
        lis.push_back(ele);
    }

    vector <bool> bio(c+1,false);
    vector <int> uda(c+1,inf);
    uda[1]=0;

    for (int i=1;i<=c;i++)
    {
        int tko;
        for (int j=1;j<=c;j++)
            if ( bio[j] == false ) tko=j;
        bio[tko]=true;

        for (int j=0;j<lis[tko].size();j++)
            if ( uda[lis[tko][j].first] == inf && uda[lis[tko][j].first] > lis[tko][j].second ) uda[lis[tko][j].first] = lis[tko][j].second;
        for (int j=0;j<lis[tko].size();j++)
            if ( uda[lis[tko][j].first] < lis[tko][j].second ) uda[lis[tko][j].first] = lis[tko][j].second;
    }

    int minn = inf;
    while ( d-- )
    {
        int a;
        cin>>a;

        minn=min(minn,uda[a]);
    }

    cout<<minn<<endl;
    return 0;
}
