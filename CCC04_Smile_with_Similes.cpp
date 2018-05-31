#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string h[6],h1[6];
    for (int i=0;i<n;i++) cin>>h[i];
    for (int i=0;i<k;i++) cin>>h1[i];
    
    for (int i=0;i<n;i++)
        for (int j=0;j<k;j++)
            cout<<h[i]<<" as "<<h1[j]<<endl;
    return 0;
}
