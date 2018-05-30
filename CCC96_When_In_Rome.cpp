#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string>
using namespace std;

int broj(string a)
{
    if (a.size()==1)
        if (a[0]=='I') return 1;
        else if (a[0]=='V') return 5;
        else if (a[0]=='X') return 10;
        else if (a[0]=='L') return 50;
        else if (a[0]=='C') return 100;
        else if (a[0]=='D') return 500;
        else if (a[0]=='M') return 1000;

    int suma=0;
    int poz=1;
    for (int i=0;i<a.size();i+=poz)
    {
        if (a[i]=='I')
        {
            if (a[i+1]=='V') {suma+=4;poz=2;}
            else if (a[i+1]=='X') {suma+=9;poz=2;}
            else
            {
                int br=1;
                for (int j=i+1;j<a.size();j++)
                    if (a[j]=='I') br++;
                    else break;
                for (int j=0;j<br;j++) suma+=1;
                poz=br;
            }
        }
        else if (a[i]=='X')
        {
            if (a[i+1]=='L') {suma+=40;poz=2;}
            else if (a[i+1]=='C') {suma+=90;poz=2;}
            else
            {
                int br=1;
                for (int j=i+1;j<a.size();j++)
                    if (a[j]=='X') br++;
                    else break;
                for (int j=0;j<br;j++) suma+=10;
                poz=br;
            }
        }
        else if (a[i]=='C')
        {
            if (a[i+1]=='D') {suma+=400;poz=2;}
            else if (a[i+1]=='M') {suma+=900;poz=2;}
            else
            {
                int br=1;
                for (int j=i+1;j<a.size();j++)
                    if (a[j]=='C') br++;
                    else break;
                for (int j=0;j<br;j++) suma+=100;
                poz=br;
            }
        }
        else if (a[i]=='V') {suma+=5;poz=1;}
        else if (a[i]=='L') {suma+=50;poz=1;}
        else if (a[i]=='D') {suma+=500;poz=1;}
        else if (a[i]=='M') {suma+=1000;poz=1;}
    }

    return suma;
}

string roman(int w, int nivo)
{
    string rez="";
    if (nivo==1)
    {
        if (w==1) rez+="I";
        else if (w==2) rez+="II";
        else if (w==3) rez+="III";
        else if (w==4) rez+="IV";
        else if (w==5) rez+="V";
        else if (w==6) rez+="VI";
        else if (w==7) rez+="VII";
        else if (w==8) rez+="VIII";
        else if (w==9) rez+="IX";
    }
    else if (nivo==2)
    {
        int w1=w/10;
        int w2=w%10;

        if (w1==1) rez+="X";
        else if (w1==2) rez+="XX";
        else if (w1==3) rez+="XXX";
        else if (w1==4) rez+="XL";
        else if (w1==5) rez+="L";
        else if (w1==6) rez+="LX";
        else if (w1==7) rez+="LXX";
        else if (w1==8) rez+="LXXX";
        else if (w1==9) rez+="XC";

        if (w2==1) rez+="I";
        else if (w2==2) rez+="II";
        else if (w2==3) rez+="III";
        else if (w2==4) rez+="IV";
        else if (w2==5) rez+="V";
        else if (w2==6) rez+="VI";
        else if (w2==7) rez+="VII";
        else if (w2==8) rez+="VIII";
        else if (w2==9) rez+="IX";
    }
    else
    {
        int w1=w/100;
        int w2=(w%100)/10;
        int w3=w%10;

        if (w1==1) rez+="C";
        else if (w1==2) rez+="CC";
        else if (w1==3) rez+="CCC";
        else if (w1==4) rez+="CD";
        else if (w1==5) rez+="D";
        else if (w1==6) rez+="DC";
        else if (w1==7) rez+="DCC";
        else if (w1==8) rez+="DCCC";
        else if (w1==9) rez+="CM";

        if (w2==1) rez+="X";
        else if (w2==2) rez+="XX";
        else if (w2==3) rez+="XXX";
        else if (w2==4) rez+="XL";
        else if (w2==5) rez+="L";
        else if (w2==6) rez+="LX";
        else if (w2==7) rez+="LXX";
        else if (w2==8) rez+="LXXX";
        else if (w2==9) rez+="XC";

        if (w3==1) rez+="I";
        else if (w3==2) rez+="II";
        else if (w3==3) rez+="III";
        else if (w3==4) rez+="IV";
        else if (w3==5) rez+="V";
        else if (w3==6) rez+="VI";
        else if (w3==7) rez+="VII";
        else if (w3==8) rez+="VIII";
        else if (w3==9) rez+="IX";
    }

    return rez;
}

int main()
{
    int tests;
    scanf("%d",&tests);

    while (tests--)
    {
        string x;
        cin>>x;
        string a="",b="";
        for (int i=0;i<x.size();i++)
        {
            if (x[i]=='+')
            {
                for (int j=i+1;j<x.size();j++)
                    if (x[j]!='=') b+=x[j];

                break;
            }
            else a+=x[i];
        }
        int c=broj(a);
        int d=broj(b);

        if ((c+d)>=1000) cout<<a<<"+"<<b<<"="<<"CONCORDIA CUM VERITATE"<<endl;
        else
        {
            if ((c+d)<=9) cout<<a<<"+"<<b<<"="<<roman(c+d,1)<<endl;
            else if ((c+d)<=99) cout<<a<<"+"<<b<<"="<<roman(c+d,2)<<endl;
            else cout<<a<<"+"<<b<<"="<<roman(c+d,3)<<endl;
        }
    }
    return 0;
}
