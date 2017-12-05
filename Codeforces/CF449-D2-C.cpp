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

unsigned long long f[100200]={};
string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string a="What are you doing while sending \"";
string b="\"? Are you busy? Will you send \"";
string c="\"?";

char rec(ll n,ll k)
{
    if(n==0)return s[k];
    if(k<a.size())return a[k];
    k-=a.size();
    if(k<f[n-1])return rec(n-1,k);
    k-=f[n-1];
    if(k<b.size())return b[k];
    k-=b.size();
    if(k<f[n-1])return rec(n-1,k);
    k-=f[n-1];
    return c[k];
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    f[0]=s.size();
    for(int i=1;i<=100000;i++)
    {
        if(f[i-1]>=1e18)f[i]=f[i-1];
        else
        f[i]=(f[i-1]*2)+a.size()+b.size()+c.size();
    }
//    cout<<f[1]<<endl;
    int q;
    string ans;
    cin>>q;
    while(q--)
    {
        ll n,k;
        cin>>n>>k;
        k--;
        if(f[n]<=k)ans+='.';
        else
        {
            ans+=rec(n,k);
        }
    }
    cout<<ans;

    return 0;
}
