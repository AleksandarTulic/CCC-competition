#include <iostream>

using namespace std;

int main()
{
    int a,b,d=0;
    cin>>a>>b;
    for (long long j=1;j<=b;j++)
        if ( j*j*j*j*j*j <= b && j*j*j*j*j*j >= a ) d++;
    cout<<d<<endl;
    return 0;
}
