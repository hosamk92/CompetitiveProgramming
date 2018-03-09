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
ll x,y,z,a[200],b[200],c[200],arr[200]={},dp[(1<<21)-1],k,l;
map<int,int>m;
vector<pair< pair<ll,ll> , pair<ll ,ll> > > v;

ll mini()
{
    ull ans=1e19,xx;
    int msk=0;
    for(auto it=m.begin();it!=m.end();it++)
    {
        int ll=(it)->second;
        l=ll;
        memset(dp,-1,sizeof dp);
        vector<int>vv;
        vv.push_back(0);
        dp[0]=0;
        for(int i=0;i<=l;i++)
        {
            k=vv.size();
            for(int j=0;j<k;j++){
                msk=vv[j];
                if(dp[msk|arr[i]]==-1)
                {
                    dp[msk|arr[i]]=dp[msk]+a[i];
                    vv.push_back((msk|arr[i]));
                }
                else dp[msk|arr[i]]=min(dp[msk|arr[i]],dp[msk]+a[i]);
            }
        }
        xx=dp[(1<<y)-1];
//        cout<<mem(0)<<' '<<xx<<endl;
        if(xx!=-1)
        ans=min(ans,(ull)(z*b[ll])+xx);
    }
    return ans;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>x>>y>>z;
    ll t;
    for(int i=0;i<x;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        for(int j=0;j<c[i];j++){
            cin>>t;
            arr[i]=(arr[i]|(1<<(t-1)));
        }
        v.push_back({{b[i],a[i]},{c[i],arr[i]}});
       // cout<<arr[i]<<"LLOL"<<endl;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<x;i++)
    {
        a[i]=v[i].first.second;
        b[i]=v[i].first.first;
        c[i]=v[i].second.first;
        arr[i]=v[i].second.second;
        m[b[i]]=i;
    }
    ull aa=mini();
    if(aa==1e19)cout<<-1;
    else
    cout<<aa;


    return 0;
}
