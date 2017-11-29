#include <bits/stdc++.h>
#include <unordered_map>
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

ll fast_pow(ll a,ll b,ll mod)
{
	if(b==0)
		return 1ll;
	ll ans=1;
	if(b%2)
		return ans=(fast_pow(a,b-1,mod)*a)%mod;
	ans=(fast_pow(a,b/2,mod)%mod);
	return ((ans*ans)%mod);
}
string in(string b)
{
    string a;
    for(int i=0;i<b.size();i++)
    {
        if(b[i]=='+')a+='*';
        else a+='+';
    }
    return a;
}
char a[4000][4000],d[4000][4000];
char t[4000][4000],t3[4000][4000];

void rec(int i)
{
    if(i==0)
    {
        a[0][0]='+';
        d[0][0]='*';
        return;
    }
    rec(i-1);
    int j,k,s=(1<<(i-1));
    for(j=0;j<s;j++)
    {
        for(k=0;k<s;k++)
        {
            t[j][k]=t[j+s][k]=t[j][k+s]=a[j][k];
            t[j+s][k+s]=d[j][k];
            t3[j][k]=t3[j+s][k]=t3[j][k+s]=d[j][k];
            t3[j+s][k+s]=a[j][k];
        }
    }
    s*=2;
    for(j=0;j<s;j++)
    {
        for(k=0;k<s;k++)
        {
            a[j][k]=t[j][k];
            d[j][k]=t3[j][k];
        }
    }


  //  t3=in(a+b+c+d);
    //a=b=c=t1;
   // d=t3;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int x;
    string z;
    cin>>x;
    x++;
    rec(x);
    int j,k,s=(1<<(x-1));
    for(j=0;j<s;j++)
    {
        for(k=0;k<s;k++)
        {
            cout<<a[j][k];
        }
        cout<<endl;
    }
   // cout<<a<<'\n'<<b<<'\n'<<c<<'\n'<<d<<endl;




    return 0;
}
