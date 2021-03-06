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

    map<ll,int>m,mm;
    for(ll j=2;j<=32;j++)
    for(ll i=2;fast_pow(i,j)<=1e10;i++)
    {
        m[fast_pow(i,j)]=j;
        if(j%2!=0)
        mm[-fast_pow(i,j)]=j;
    }

    ll x,i;
    while(cin>>x)
    {
        if(x==0)break;
        if(m[x]==0&&mm[x]==0)cout<<1<<'\n';
        else
        {
            if(x<0)cout<<mm[x]<<'\n';
            else
            cout<<m[x]<<'\n';
        }

    }

    return 0;
}
