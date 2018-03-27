/// dangerous turns will happen in only 4 cases
///  y inc. then x dec.
///  y dec. then x inc.
///  x inc. then y inc.
///  x dec. then y dec.

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

    ll x,s=0,a[1010]={},b[1020]={};
    cin>>x;
    for(int i=0;i<=x;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=2;i<=x;i++)
    {
        if(b[i-2]<b[i-1]&&a[i-1]>a[i])s++;
        if(b[i-2]>b[i-1]&&a[i-1]<a[i])s++;
        if(a[i-2]<a[i-1]&&b[i-1]<b[i])s++;
        if(a[i-2]>a[i-1]&&b[i-1]>b[i])s++;
    }
    cout<<s;

    return 0;
}
