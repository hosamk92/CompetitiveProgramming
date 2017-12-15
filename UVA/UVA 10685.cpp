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
vector<vector <int> > v;
vector<bool>vist;

int dfs(int i)
{
    int ans=0;
    for(int j=0;j<v[i].size();j++)
    {
        if(vist[v[i][j]])continue;
        vist[v[i][j]]=1;
        ans+=(1+dfs(v[i][j]));
    }
    return ans;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y;
    while(cin>>x>>y)
    {
        int ans=0;
        if(x==0&&y==0)break;
        string s,s1;
        map<string ,int>m;
        int i,j;
        v.resize(x+10);
        vist.resize(x+10,0);
        for(i=0;i<x;i++)
        {
            cin>>s;
            m[s]=i;
        }
        for(i=0;i<y;i++)
        {
            cin>>s>>s1;
            v[m[s]].push_back(m[s1]);
            v[m[s1]].push_back(m[s]);
        }
        for(i=0;i<x;i++){
            vist[i]=1;
            ans=max(ans,1+dfs(i));
            vist[i]=0;
        }
        cout<<ans<<'\n';
        vist.clear();
        v.clear();
    }

    return 0;
}
