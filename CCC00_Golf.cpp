#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sum,n;
    cin>>sum>>n;

    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    vector <int> DP(sum+1,20000000);
    DP[0]=0;

    for (int i=0;i<n;i++)
        for (int j=1;j<=sum;j++)
             if (j>=a[i]) DP[j]=min(DP[j],DP[j-a[i]]+1);
    
    if (DP[sum]==20000000) cout<<"Roberta acknowledges defeat."<<endl;
    else cout<<"Roberta wins in "<<DP[sum]<<" strokes."<<endl;
    return 0;
}
