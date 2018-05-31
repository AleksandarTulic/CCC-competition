#include <iostream>

using namespace std;

int main()
{
    int n,b=0;
    cin>>n;
    char m[n],p[n];
    for (int i=0;i<n;i++) cin>>m[i];
    for (int i=0;i<n;i++) cin>>p[i];
    
    for (int i=0;i<n;i++)
        if (m[i]==p[i])
            b++;
    cout<<b<<endl;
    return 0;
}
