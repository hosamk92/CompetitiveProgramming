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

ll fast_pow(ll a,ll b)
{
	if(b==0)
		return 1ll;
	ll ans=1;
	if(b%2)
		return ans=(fast_pow(a,b-1)*a);
	ans=(fast_pow(a,b/2));
	return ((ans*ans));
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a,b,i,x;
    map<ll,ll>m,mm;
    map<pair<ll,ll> ,ll>mmm;
    map<ll,ll>::iterator itt;
    map<pair<ll,ll> ,ll>::iterator it;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>a>>b;
        m[a]++;
        mm[b]++;
        mmm[{a,b}]++;
    }
    ll ans=0;
    for(itt=m.begin();itt!=m.end();itt++)
    {
        a=(*itt).second-1;
        ans+=((a*(a+1))/2);
    }
    for(itt=mm.begin();itt!=mm.end();itt++)
    {
        a=(*itt).second-1;
        ans+=((a*(a+1))/2);
    }
    for(it=mmm.begin();it!=mmm.end();it++)
    {
        a=(*it).second-1;
        ans-=((a*(a+1))/2);
    }
    cout<<ans;


    return 0;
}
