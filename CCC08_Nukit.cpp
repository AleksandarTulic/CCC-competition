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

int m[5][4] = { {2,1,0,2}, {1,1,1,1}, {0,0,2,1}, {0,3,0,0}, {1,0,0,1} };
bool dp[31][31][31][31] = {false};

bool flag(int a, int b, int c, int d)
{
    if ( a < 0 || b < 0 || c < 0 || d < 0 ) return false;
    if ( dp[a][b][c][d] == true ) return false;
    return true;
}

int main()
{
    int n;
    cin>>n;

    for (int a=0;a<31;a++)
        for (int b=0;b<31;b++)
            for (int c=0;c<31;c++)
                for (int d=0;d<31;d++)
                    for (int i=0;i<5;i++)
                        if ( flag(a-m[i][0],b-m[i][1],c-m[i][2],d-m[i][3]) )dp[a][b][c][d] = true;

    while (n--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        if ( dp[a][b][c][d] ) cout<<"Patrick"<<endl;
        else cout<<"Roland"<<endl;
    }
    return 0;
}
