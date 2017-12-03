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

    int n;
    while(cin>>n)
    {
        double h,w,i,ans=-1,j,m;
        if(n==0)break;
        for(i=0;i<n;i++)
        {
            cin>>h>>w;
            if(h>=w)
            {
                h/=2;
            }
            else w/=2;
            if(h>=w)
            {
                h/=2;
            }
            else w/=2;
            if(min(h,w)>ans)
            {
                ans=min(h,w);
                j=i;
            }
        }
        cout<<j+1<<'\n';

    }


    return 0;
}
