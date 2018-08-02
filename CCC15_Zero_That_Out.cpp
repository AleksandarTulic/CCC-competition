#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;

    stack <int> s;
    while (n--)
    {
        int a;
        cin>>a;

        if ( a == 0 && !s.empty() ) s.pop();
        else s.push(a);
    }

    int suma = 0;
    while (!s.empty()) { suma+=s.top(); s.pop(); }

    cout<<suma<<endl;
    return 0;
}
