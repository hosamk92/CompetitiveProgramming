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
vector<vector<int> > v;
int vis[200]={};

bool dfs(int i,int p)
{
    bool c=0;
    for(int j=0;j<v[i].size();j++)
    {
        if(v[i][j]==p)continue;
        if(vis[v[i][j]]==1)
            c=1;
        if(vis[v[i][j]]==0)
        {
            vis[v[i][j]]=1;
            if(dfs(v[i][j],i))c=1;
        }
    }
    return c;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m,i,j,a,b,n;
    char c;
    cin>>n>>m;
    v.resize(n+1);
    for(i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(m==n){
        dfs(1,-1);
            vis[1]=1;
    for(i=1;i<=n;i++)
    {
    //    cout<<i<<' '<<vis[i]<<endl;
        if(vis[i]==0)
        {
            cout<<"NO";
            return 0;
        }
    }
     cout<<"FHTAGN!";
    }
    else
        cout<<"NO";


    return 0;
}
