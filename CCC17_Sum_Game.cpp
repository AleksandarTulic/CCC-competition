#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int n;

    cin>>n;

    pair <int, int> a[n];

    for (int i=0;i<n;i++) cin>>a[i].first;
    for (int i=0;i<n;i++) cin>>a[i].second;

    int sum1=0,sum2=0;

    int pozicija=-10;

    for (int i=0;i<n;i++)
    {
        sum1+=a[i].first;
        sum2+=a[i].second;

        if (sum1==sum2) pozicija=i;
    }

    if (pozicija==-10) cout<<0<<endl;
    else if (pozicija==n-1) cout<<n<<endl;
    else cout<<pozicija+1<<endl;
    return 0;
}
