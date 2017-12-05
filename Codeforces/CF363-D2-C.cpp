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

    string a,z,d;
    cin>>a;
    if(a.size()<=2){cout<<a; return 0;}
    z+=a[0];
    z+=a[1];
    for(int i=2;i<a.size();i++)
    {
        if(a[i]==a[i-1]&&a[i]==a[i-2])continue;
        z+=a[i];
    }
    if(z.size()<=2){cout<<z; return 0;}
    d+=z[0];
    d+=z[1];
    for(int i=2;i<z.size();i++)
    {
        if(d[d.size()-1]==z[i]&&d[d.size()-2]==d[d.size()-3])continue;
        d+=z[i];
    }
    cout<<d;


    return 0;
}
