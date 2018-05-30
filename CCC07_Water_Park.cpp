#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <utility>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct graf{ int a, b; };

int main()
{
    int n;
    cin>>n;

    vector <vector<int> > lis;

    vector <graf> gr;

    int x,y;
    cin>>x>>y;
    while (x!=0)
    {
        gr.push_back({x,y});

        cin>>x>>y;
    }

    for (int i=1;i<=n;i++)
    {
        vector <int> ele;
        for (int j=0;j<gr.size();j++)
            if ( i == gr[j].a ) ele.push_back(gr[j].b);

        lis.push_back(ele);
    }

    int uda[n+1] = {0};
    uda[n]=1;

    for (int i=n-1;i>=0;i--)
        for (int j=0;j<lis[i].size();j++)
            uda[i+1]+=uda[lis[i][j]];

    cout<<uda[1]<<endl;
    return 0;
}
