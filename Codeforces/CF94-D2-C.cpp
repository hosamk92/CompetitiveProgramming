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

    ll x,y,a,b,c,d,s;
    cin>>x>>y>>a>>b;

    if(a==b||y==1)s=1;
    else if(b%y==0&&b-a<y)s=1;
    else if(b%y>a%y&&b-a<y&&a%y)s=1;
    else if(a%y==1&&b%y==0)s=1;
    else if(b==x&&a%y==1)s=1;

    else if(b==x)s=2;
    else if(b%y==0||a%y==1)s=2;
    else if(b%y==((a-1)%y))s=2;
    else if(b-a<y)s=2;
    else if(b-a<y*2&&((b%y==0||b%y>y/2)||((y-(a%y))>y/2&&a%y!=0)))s=2;
    else s=3;

    cout<<s;


    return 0;
}
