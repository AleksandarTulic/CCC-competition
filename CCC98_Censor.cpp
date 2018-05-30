#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin>>n;

    string g;
    getline(cin,g,'\n');
    while (n--)
    {
        getline(cin,g,'\n');
        string t="";
        for (int i=0;i<g.size();i++)
        {
            if (g[i]==' ')
            {
                if (t.size()==4) cout<<"**** ";
                else cout<<t<<" ";
                t="";
            }
            else t+=g[i];
        }
        if (t.size()==4) cout<<"****"<<endl;
        else cout<<t<<endl;
    }
    return 0;
}
