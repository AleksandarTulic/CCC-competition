#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int row,col;
pair <int, char> m[21][21];

void koliko(int x, int y, int korak)
{
    if (x >= 0 || x < row || y >= 0 || y < col)
    {
        if (korak < m[x][y].first && m[x][y].first > 0)
        {
            if (m[x][y].second=='*') m[x][y].first=-10;
            else if (m[x][y].second=='+')
            {
                m[x][y].first=korak;
                koliko(x+1,y,korak+1);
                koliko(x-1,y,korak+1);
                koliko(x,y+1,korak+1);
                koliko(x,y-1,korak+1);
            }
            else if (m[x][y].second=='|')
            {
                m[x][y].first=korak;
                koliko(x+1,y,korak+1);
                koliko(x-1,y,korak+1);
            }
            else if (m[x][y].second=='-')
            {
                m[x][y].first=korak;
                koliko(x,y+1,korak+1);
                koliko(x,y-1,korak+1);
            }
        }
    }
}

int main()
{
    int tests;

    cin>>tests;

    while (tests--)
    {
        cin>>row>>col;

        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                cin>>m[i][j].second;
                m[i][j].first=1000000000;
            }
        }

        koliko(0,0,1);

        if (m[row-1][col-1].first==-10 || m[row-1][col-1].first==1000000000) cout<<-1<<endl;
        else cout<<m[row-1][col-1].first<<endl;
    }
    return 0;
}
