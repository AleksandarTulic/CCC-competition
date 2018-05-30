#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> a;
bool flag=true;

void put(vector <bool> prov, char poc)
{
    if (flag == false) return;
    if ( poc == 'B' )
    {
        flag=false;
        return;
    }

    for (int i=0;i<a.size();i++)
    {
        if ( poc == a[i][0] && prov[i] )
        {
            prov[i]=false;
            put(prov,a[i][1]);
        }
    }
    return;
}

int main()
{
    char a1,a2;
    cin>>a1>>a2;

    vector <string> ispis;

    while (a1!='*')
    {
        string t="";
        t+=a1;t+=a2;
        ispis.push_back(t);
        a.push_back(t);t="";
        t+=a2;t+=a1;
        a.push_back(t);

        cin>>a1>>a2;
    }

    vector <int> rj;

    for (int i=0;i<a.size();i++)
    {
        vector <bool> pr(a.size(),true);
        pr[i]=false;
        put(pr,'A');

        if (flag) rj.push_back(i);
        else flag=true;
    }

    for (int i=0;i<rj.size();i++)
    {
        char a1=a[rj[i]][0];
        char a2=a[rj[i]][1];

        bool pro=true;
        for (int j=0;j<ispis.size();j++)
        if ( ispis[j][0] == a1 && ispis[j][1] == a2 ) { pro=false;break; }

        if ( pro ) cout<<a2<<a1<<endl;
        else cout<<a1<<a2<<endl;
    }
    cout<<"There are "<<rj.size()<<" disconnecting roads."<<endl;
    return 0;
}
