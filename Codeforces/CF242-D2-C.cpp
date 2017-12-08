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
ll x1,x2,y1,y2,n;
int dx[]={1,-1, 1,-1,0,1, 0,-1};
int dy[]={1,-1,-1, 1,1,0,-1, 0};
map<pair<ll,ll>,bool>m;
map<pair<ll,ll> , ll> s;

void dij(ll i,ll k)
{
    pair<ll,ll>jj,kk;
    priority_queue <pair<ll,pair<ll,ll> > >llo;
    llo.push({1e17,{i,k}});
    s[{i,k}]=0;
    while(!llo.empty()){

        jj=llo.top().second;
        llo.pop();
        if(m[jj]==0)continue;
    //    cout<<jj.first<<' '<<jj.second<<endl;
        for(int l=0;l<8;l++)
        {
            kk={jj.first+dx[l],jj.second+dy[l]};
      //      cout<<kk.first<<' '<<kk.second<<' '<<s[kk]<<' '<<s[jj]<<endl;
            if(s[kk]>s[jj]+1)
            {
                s[kk]=s[jj]+1;
                llo.push({1e17-s[kk],kk});
            }
        }
    }
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    ll a,b,c,i,j;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        for(j=b;j<=c;j++)
        {
            m[make_pair(a,j)]=1;
            s[make_pair(a,j)]=1e17;
        }
    }
    dij(x1,y1);
    ll ans=s[{x2,y2}];
    if(ans>=1e9)cout<<-1;
    else
    cout<<ans;

    return 0;
}
