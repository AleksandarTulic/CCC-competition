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
    int n;
    cin>>n;

    while (n!=0)
    {
        int a[n];
        for (int i=0;i<n;i++) cin>>a[i];

        if ( n == 1 ) cout<<0<<endl;
        else if ( n == 2 ) cout<<1<<endl;
        else
        {
            vector <int> raz;
            raz.push_back(a[1]-a[0]);
            for (int i=1;i<n-1;i++) raz.push_back(a[i + 1] - a[i]);

            for (int i=1;i<=raz.size();i++)
            {
                vector <int> prov;
                for (int j=0;j<i;j++) prov.push_back(raz[j]);

                int poz = 0;
                bool flag = true;
                for (int j=i;j<raz.size();j++)
                {
                    if ( prov[poz] != raz[j] ) { flag = false; break; }
                    poz++;
                    if (poz == prov.size()) poz = 0;
                }
                if ( flag ) {cout<<i<<endl; break; }
            }
        }

        cin>>n;
    }
    return 0;
}
