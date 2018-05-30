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
    int n;
    cin>>n;

    int trosak = 0;
    while (n>1)
    {
        int p = 1;
        for (int i=2;i<=sqrt(n);i++)
            if ( n % i == 0 ) { p = n / i; break; }

        trosak+=(n-p)/p;
        n-=p;
    }

    cout<<trosak<<endl;
    return 0;
}
