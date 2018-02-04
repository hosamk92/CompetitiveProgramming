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
map<pair<ll,ll>,ll>mm;
map<ll,bool>m;
ll n;

void getpath(ll a,ll b)
{
    if(m[a])
    {
        n=a;
        return ;
    }
    m[a]=1;
    if(a==b)return ;
    if(a%2==0)return getpath(a/2,b);
    return getpath((a-1)/2,b);
}
ll getpath2(ll a,ll b)
{
    if(a==b)return 0;
    if(a%2==0)return getpath2(a/2,b)+mm[{a,a/2}];
    return getpath2((a-1)/2,b)+mm[{a,(a-1)/2}];
}
ll getpath1(ll a,ll b,ll w)
{
    if(a==b)return 0;
    if(a%2==0)
    {
        mm[{a,a/2}]+=w;
        return getpath1(a/2,b,w);
    }
    mm[{a,(a-1)/2}]+=w;
    return getpath1((a-1)/2,b,w);
}
ll path(ll a,ll b)
{
    m.clear();
    getpath(a,1);
    getpath(b,1);
    return getpath2(a,n)+getpath2(b,n);
}
void incpath(ll a,ll b,ll w)
{
    m.clear();
    getpath(a,1);
    getpath(b,1);
    getpath1(a,n,w);
    getpath1(b,n,w);
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,s,w;
        cin>>s>>a>>b;
        if(s==1)
        {
            cin>>w;
            incpath(a,b,w);
        }
        else
        {
            cout<<path(a,b)<<'\n';
        }

    }

    return 0;
}
