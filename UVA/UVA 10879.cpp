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

    int n,j=0;
    cin>>n;
    while(n--)
    {
        ll x,i=0,k=0,a[5]={},b[5]={};
        cin>>x;
        for(i=2;i*i<=x;i++)
        {
            if(k==2)break;
            if(x%i==0)
            {
                a[k]=i; b[k]=x/i;
                k++;
            }
        }
        j++;
        cout<<"Case #"<<j<<": "<<x<<" = "<<a[0]<<" * "<<b[0]<<" = "<<a[1]<<" * "<<b[1]<<'\n';
    }

    return 0;
}
