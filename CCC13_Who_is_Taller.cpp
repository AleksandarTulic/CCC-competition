#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int n,m;
int p,q;
vector <vector<int> > graf(1000001);

bool bfs(int a, int b)
{
    queue <int> q;
    vector <bool> po(m,false);

    q.push(a);
    po[a]=true;
    int sad;

    while (q.empty() == false )
    {
        sad = q.front();
        q.pop();

        if ( sad == b ) return true;

        for (int i=0;i<graf[sad].size();i++)
            if ( po[graf[sad][i]] == false ) q.push(graf[sad][i]),po[graf[sad][i]] = true;
    }

    return false;
}

int main()
{
    cin>>n>>m;

    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
    }

    cin>>p>>q;

    for (int i=0;i<graf[p].size();i++)
        if ( graf[p][i] == q ) { cout<<"yes"<<endl; return 0; }
    for (int i=0;i<graf[q].size();i++)
        if ( graf[q][i] == p ) { cout<<"no"<<endl; return 0; }

    if ( bfs(p,q) ) cout<<"yes"<<endl;
    else if ( bfs(q,p) ) cout<<"no"<<endl;
    else cout<<"unknown"<<endl;
    return 0;
}
