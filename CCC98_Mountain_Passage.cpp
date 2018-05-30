#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
int m[26][26];
int korak[26][26];
int p=-1;

void pocetak()
{
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        korak[i][j]=20000;
}

void flood(int x1, int y1, int x2, int y2, int t)
{
    if ( x1>=n || x1<0 || y1>=n || y1<0 ) return;
    if ( abs(m[x1][y1]-m[x2][y2]) > 2 ) return;
    if ( t >= korak[x1][y1]) return;

    korak[x1][y1]=t;

    if ( m[x1][y1] > p || m[x2][y2] > p ) t+=1;

    flood(x1+1,y1,x1,y1,t);
    flood(x1-1,y1,x1,y1,t);
    flood(x1,y1+1,x1,y1,t);
    flood(x1,y1-1,x1,y1,t);
}

int main()
{
    int tests;
    cin>>tests;

    while (tests--)
    {
        cin>>n;

        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            cin>>m[i][j];

        pocetak();

        p=m[0][0];

        flood(0,0,0,0,0);

        if ( korak[n-1][n-1] == 20000 ) cout<<"CANNOT MAKE THE TRIP"<<endl;
        else cout<<korak[n-1][n-1]+1<<endl;
    }
    return 0;
}
