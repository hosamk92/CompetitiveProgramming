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

    ll a,b,c,z=0,x=0,v;
    cin>>a>>b;
    c=(a*b)/__gcd(a,b);

    z=(c)/a;
    x=c/b;
  //  cout<<z<<' '<<x<<' '<<v<<endl;
    if(b>a)z--;
    else x--;
    if(x==z)cout<<"Equal";
    else if(z>x)cout<<"Dasha";
    else cout<<"Masha";


    return 0;
}
