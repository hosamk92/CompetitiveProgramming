#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

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

    ll a,b,c,d,x,s=0,f,ff,fff,ans,ans1;
    cin>>a>>b>>c>>d>>x;
    for(ll i=0;i<x;i++)
    {
        cin>>f>>ff>>fff;
        ans=(f*a)+(ff*b)+fff;
        ans1=(f*c)+(ff*d)+fff;
        if(ans>0&&ans1<0)s++;
        if(ans1>0&&ans<0)s++;
    }
    cout<<s;
    return 0;
}
