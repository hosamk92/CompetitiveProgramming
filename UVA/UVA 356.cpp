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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);

    int n,l=0;
    while(cin>>n)
    {
        double i,j,k=n-0.5;
        ll s=0,ans=0;
        for(i=n;i>=0;i--)
        {
            for(j=0;j<=n;j++)
            {
                if(i!=0&&j!=0)
                if(sqrt((i*i)+(j*j))<=k&&
                   sqrt((i*i)+((j-1)*(j-1)))<=k)ans++;
            }
        }
        if(l!=0)cout<<'\n';
        l++;
        cout<<"In the case n = "<<n<<", "<<4+((n-1)*8)<<" cells contain segments of the circle."<<'\n';
        cout<<"There are "<<4*ans<<" cells completely contained in the circle."<<'\n';

       // cout<<4*ans<<' '<<4*s<<'\n';

    }


    return 0;
}
