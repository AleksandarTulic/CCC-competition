#include <iostream>

using namespace std;

int main()
{
    char m[3][3]={{'*','x','*'},{' ','x','x'},{'*',' ','*'}};

    int n;

    cin>>n;

    char t[3*n][3*n];

    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int ii=i*n;ii<(i+1)*n;ii++)
                for (int jj=j*n;jj<(j+1)*n;jj++)
                    t[ii][jj]=m[i][j];

    for (int i=0;i<3*n;i++)
    {
        for (int j=0;j<3*n;j++) cout<<t[i][j];
        cout<<endl;
    }
}
