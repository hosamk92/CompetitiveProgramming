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
ll p[1000020]={};
vector <ll>vec;
ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll i,j;
    int n;
    cin>>n;
    p[1]=1;
    p[2]=2;
    for(i=3;i<=n;i++)
    {
        p[i]=max(p[i-1],max(lcm(i,lcm(i-1,i-2)),lcm(i,lcm(i-1,i-3))));
    }
    cout<<p[n];

    return 0;
}
