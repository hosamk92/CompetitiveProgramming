/// check if any two rings intersect and make a graph for each intersecting ring and then find the max connected component in the graph


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
long double x[200],y[200],r[200];
vector<vector<int> > v;
int vis[200]={};

inline long double dis(int i,int j)
{
    return ( ( (x[i]-x[j])*(x[i]-x[j]) ) + ( (y[i]-y[j])*(y[i]-y[j]) ) );
}
int dfs(int i)
{
    int ans=0;
    for(int j=0;j<v[i].size();j++)
    {
        if(vis[v[i][j]])continue;
        vis[v[i][j]]=1;
        ans=ans+dfs(v[i][j])+1;
    }
    return ans;
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n){
        if(n==-1)return 0;
        v.resize(n+2);
        for(int j=0;j<n;j++)
        {
            cin>>x[j]>>y[j]>>r[j];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long double d=dis(i,j);
                if(d<=(r[j]*r[j])+(r[i]*r[i])+(2*r[i]*r[j])&&d>=(r[j]*r[j])+(r[i]*r[i])-(2*r[i]*r[j]))
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            vis[i]=1;
            ans=max(ans,dfs(i)+1);
        }
        if(ans==1)
        cout<<"The largest component contains "<<ans<<" ring.\n";
        else
            cout<<"The largest component contains "<<ans<<" rings.\n";
        v.clear();
        memset(vis,0,sizeof vis);
    }


    return 0;
}
