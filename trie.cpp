#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

double Fib(double x,double z);
string BinDec(ull x);
string StringInt(ll x);
ull StringInt(string x);
ull BinDec (string x);
ull POWMOD (ull x,ull y,ull mod);
ull POWE(long long , long long);

const int ss=2;

struct trie
{
    trie *child[ss];
    int one,zero,is;
    trie()
    {
        memset(child,0,sizeof(child));
        one=zero=is=0;
    }
    void insert (char *str)
    {
        if(*str==0)is=1 ;
        else{
               // cout<<*str;
        int in=(*str)-'0';
        if(in==0)zero++;
        else if(in==1)one++;
        if(child[in]==0)
            child[in]=new trie();
        child[in]->insert(str+1);
        }
    }
    void remove(char *str)
    {
        if(*str==0)is=0;
        else{
        int in=*str-'0';
        if(in==0)zero--;
        if(in==1)one--;
        if(child[in]==0)
            child[in]=new trie();
        child[in]->remove(str+1);

        }
    }
    void get(char *str,ll & a,ll b)
    {
      //  cout<<a<<' '<<b<<endl;
        if(*str==0);
        else{
        int in=*str-'0';
        if(in==0&&one>=1)
        {
            a+=b;
            child[1]->get(str+1,a,b/2);
        }
        else if(in==1&&zero>=1)
        {
            a+=b;
            child[0]->get(str+1,a,b/2);
        }
        else
        child[in]->get(str+1,a,b/2);
        }
    }

};


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x,z;
    trie aa;
    ll b;
    char a,q[40]={};b=0;
    for(int i=31;i>=0;i--)
        {
            if((b&POWE(2,i))==0)
            {
                q[31-i]='0';
            }
            else q[31-i]='1';
        }
        aa.insert(q);
    cin>>x;
    for(int j=0;j<x;j++)
    {
        cin>>a>>b;
        char y[40]={};
        for(int i=31;i>=0;i--)
        {
            if((b&POWE(2,i))==0)
            {
                y[31-i]='0';
            }
            else y[31-i]='1';
        }
       // cout<<y<<endl;
        if(a=='+')
            aa.insert(y);
        else if(a=='-')
            aa.remove(y);
        else
        {
            z=0;
            aa.get(y,z,POWE(2,31));
            cout<<z<<'\n';
        }
    }



    return 0;
}
