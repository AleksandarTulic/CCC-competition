#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

string substring(string g, int d)
{
    string s="";
    for (int i=d;i<g.size();i++) s+=g[i];
    return s;
}

int main()
{
    int tests;
    cin>>tests;

    while (tests--)
    {
        string g;
        cin>>g;

        vector <string> sufiks;

        string s=g;
        for (int i=0;i<g.size();i++)
        {
            sufiks.push_back(s);

            s=substring(g,i+1);
        }

        sort(sufiks.begin(),sufiks.end());

        int broj=sufiks[0].size();

        for (int i=0;i<sufiks.size()-1;i++)
        {
            int br=0;

            for (int j=0;j<min(sufiks[i].size(),sufiks[i+1].size());j++)
                if ( sufiks[i][j] == sufiks[i+1][j] ) br++;
                else break;

            broj+=sufiks[i+1].size() - br;
        }

        cout<<broj+1<<endl;
    }
    return 0;
}
