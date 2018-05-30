#include <iostream>

using namespace std;

int t[8][8];

void Skok(int x1, int y, int potez)
{
    if (x1<0 or x1>7 or y<0 or y>7) return;
    if (potez>t[x1][y]) return;
    t[x1][y]=potez;
    Skok(x1-1,y-2,potez+1);
    Skok(x1-1,y+2,potez+1);
    Skok(x1+1,y-2,potez+1);
    Skok(x1+1,y+2,potez+1);
    Skok(x1-2,y-1,potez+1);
    Skok(x1-2,y+1,potez+1);
    Skok(x1+2,y-1,potez+1);
    Skok(x1+2,y+1,potez+1);
}

int main()
{
    for (int i=0;i<8;i++)
        for (int j=0;j<8;j++)
            t[i][j]=100;
            
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    a=a-1;b=b-1;c=c-1;d=d-1;
    t[a][b]=0;
    
    Skok(a,b,0);
    cout<<t[c][d]<<endl;
    return 0;
}
