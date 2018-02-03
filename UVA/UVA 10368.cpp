#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

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

int rec(ll a,ll b)
{
    if(a<=b)swap(a,b);
    if(a%b==0)return 1;
    int ans=!(rec(a%b,b));
    if(ans==1)return ans;
    if(a-b!=a%b)return !rec((a%b)+b,b);
    return ans;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1)
    {
        ll a,b;
        cin>>a>>b;
        if(a==b&&a==0)return 0;
        int ans=rec(a,b);
        if(ans)cout<<"Stan wins\n";
        else cout<<"Ollie wins\n";
    }

    return 0;
}
