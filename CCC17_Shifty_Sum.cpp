#include <iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int k;

    cin>>k;

    if (k==0) cout<<n<<endl;
    else
    {
        int a1=0,a2=0,a3=0,a4=0,a5=0;

        a1=n*10;
        if (k>=2) a2=n*100;
        if (k>=3) a3=n*1000;
        if (k>=4) a4=n*10000;
        if (k==5) a5=n*100000;

        cout<<n+a1+a2+a3+a4+a5<<endl;
    }
    return 0;
}
