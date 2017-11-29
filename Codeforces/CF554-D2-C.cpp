#include <bits/stdc++.h>
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
long long arr[1020]={};
ll nCp(ll a,ll b)
{
    ll ans2=1,mod=1000000007;
    if(b>a)return 0;
    else if(b==a)return 1;
    else
    {
        ans2=arr[a];
        ans2*=fast_pow(arr[a-b],mod-2,mod);
        ans2%=mod;
        ans2*=fast_pow(arr[b],mod-2,mod);
        ans2%=mod;
        return ans2;
    }
}


int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    arr[0]=1;
    ll mod=1000000007,ans=1;
    for(i=1;i<1003;i++)
    {
        ans*=i;
        ans%=mod;
        arr[i]=ans;
    }
    ll s=0,p=1,a;
    cin>>n;
    cin>>a;
    s=a;
    for(i=1;i<n;i++)
    {
        cin>>a;
        p*=nCp(s+a-1,a-1);
        p%=mod;
        s+=a;
    }
    cout<<p;

    return 0;
}
