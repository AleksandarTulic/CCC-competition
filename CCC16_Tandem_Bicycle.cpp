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
    int type;
    cin>>type;

    int n;
    cin>>n;
    vector <int> a(n),b(n);

    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];

    int rez = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if ( type == 1 )
        for (int i=0;i<n;i++)
            rez+=max(a[i],b[i]);
    else
        for (int i=0;i<n;i++)
            rez+=max(a[i],b[n-1-i]);
    cout<<rez<<endl;
    return 0;
}
