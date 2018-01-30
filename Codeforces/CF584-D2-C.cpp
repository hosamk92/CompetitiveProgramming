#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>


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

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x,i,y,y1,v[100200]={};
    char z[100200];
    cin>>x>>y;
    y=x-y;
    y1=y;

    string a,b;
    cin>>a>>b;
    for(i=0;i<x;i++)
    {
        if(a[i]==b[i]&&y1)
        {
            z[i]=a[i];
            v[i]=1;
            y1--;
        }
        else if(a[i]==b[i])
        {
            if(a[i]=='z')z[i]='a';
            else z[i]=a[i]+1;
            y--;
            v[i]=1;
        }
    }
    int y2,y3,y4,y5;
    y2=y3=y1;
    y4=y5=y;
    for(i=0;i<x;i++)
    {
        if(v[i])continue;
      //  cout<<y2<<' '<<y3<<' '<<y4<<' '<<y5<<endl;
        if(y2)
        {
            z[i]=a[i];
            y2--;
        }
        else if(y3)
        {
            z[i]=b[i];
            y3--;
        }
        else
        {
            if(a[i]=='z')z[i]='a';
            else z[i]=a[i]+1;
            if(z[i]==b[i])
            {
                if(b[i]=='z')z[i]='a';
                else z[i]=b[i]+1;
            }
        }

    }
    if(y2==0&&y3==0)
    {
        for(i=0;i<x;i++)
        cout<<z[i];
    }
    else cout<<-1;

    return 0;
}
