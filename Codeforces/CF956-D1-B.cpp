/// the idea it maximaize the k and i ana minimize the j
/// since all element are sorted we will move on all the elements
/// the element that we are standing on is j
/// then max i will be equal j-1
/// then all we have to do is search for the max k using binery search
/// value[k] can't exeed value[i] + u

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

    ll a,b,x,j,k;
    ld ans=-1;
    vector<ll>v;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    v.push_back(1e10);
    for(int i=1;i<a;i++)
    {
        j=v[i-1]+b;
        k=lower_bound(v.begin(),v.end(),j)-v.begin();
        if(v[k]>j)k--;
        if(k==i)continue;
        ld t1=v[k]-v[i-1],t2=v[k]-v[i];
        ans=max(ans,(ld)t2/t1);
    }
    cout<<fixed<<setprecision(10)<<ans;

    return 0;
}
