#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;

    int k;
    cin>>k;

    int dp[r][c];
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        dp[i][j]=0;

    bool d[r][c];
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        d[i][j]=true;

    while (k--)
    {
        int a,b;
        cin>>a>>b;

        d[a-1][b-1]=false;
    }

    for (int i=0;i<r;i++)
        if (d[i][0]) dp[i][0]=1;
        else break;
    for (int i=0;i<c;i++)
        if (d[0][i]) dp[0][i]=1;
        else break;

    for (int i=1;i<r;i++)
        for (int j=1;j<c;j++)
            if ( d[i][j] ) dp[i][j]=dp[i-1][j]+dp[i][j-1];

    cout<<dp[r-1][c-1]<<endl;
    return 0;
}
