#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stdio.h>

using namespace std;

int n,m;
vector <int> flag(100001,false);
vector <vector<int> > graf(100001);
vector <int> uda(100001,0);
int rez = 0;
int put = 0;

bool dfs(int node, int par)
{
    bool curr = flag[node];

    for (int i=0;i<graf[node].size();i++)
    {
        if ( par != graf[node][i] && dfs(graf[node][i],node) )
        {
            curr = true;

            if ( flag[graf[node][i]] )
            {
                flag[node]=true;
                put+=2;
            }
        }
    }

    return curr;
}

void bfs(int node)
{
    queue <pair<pair<int, int>, int> > q;
    q.push({{node,-1},0});

    while (!q.empty())
    {
        int a,b,c;
        a = q.front().first.first;
        b = q.front().first.second;
        c = q.front().second;

        q.pop();
        uda[a]=c;
        for (int i=0;i<graf[a].size();i++)
            if ( graf[a][i] != b && flag[graf[a][i]] )
                q.push({{graf[a][i],a},c+1});
    }
}

int main()
{
    cin>>n>>m;

    int b;
    for (int i=0;i<m;i++)
    {
        cin>>b;

        flag[b]=true;
    }

    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    dfs(b,-1);
    bfs(b);

    int poz = -1;
    for (int i=0;i<n;i++)
        if ( flag[i] ) { poz = i; break; }

    for (int i=poz;i<n;i++)
        if ( flag[i] && uda[poz] < uda[i] ) poz=i;

    for (int i=0;i<n;i++) uda[i]=0;
    bfs(poz);

    int naj = 0;
    for (int i=0;i<n;i++)
        if ( flag[i] && naj < uda[i] ) naj=uda[i];

    cout<<put-naj<<endl;
    return 0;
}
