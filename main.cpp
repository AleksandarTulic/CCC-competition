#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int tests;
    scanf("%d",&tests);

    while (tests--)
    {
        int n;
        scanf("%d",&n);

        int suma = 0;
        for (int i=1;i<=n/2;i++)
            if ( n % i == 0 ) suma+=i;

        if ( suma == n ) printf("%d is a perfect number.\n",n);
        else if (suma > n) printf("%d is an abundant number.\n",n);
        else printf("%d is a deficient number.\n",n);
    }
    return 0;
}
