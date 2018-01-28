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

vector<vector <int> >arr;
vector <int>ans;
int n;

int dfs(int i,string a,int s)
{
    if(i-1==n)
    {
        if(s>ans.size())
        {
           ans.clear();
           for(int j=1;j<=n;j++)
                if(a[j]=='1')
                    ans.push_back(j);
        }
        return 0;
    }
    bool c=0;
    for(int j=0;j<arr[i].size();j++)
    {
        if(a[arr[i][j]]=='1')
        {
            c=1;break;
        }
    }
    dfs(i+1,a,s);
    if(!c)
    {
        a[i]='1';
        dfs(i+1,a,s+1);
        a[i]='0';
    }
    return 0;
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
        arr.clear();
        int k,a,i,b;
        string x;
        cin>>n>>k;
        arr.resize(n+1);
        for(i=0;i<k;i++)
        {
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(i=0;i<=n;i++)x+='0';

        dfs(1,x,0);
        cout<<ans.size()<<'\n';
        for(i=0;i<ans.size()-1;i++)
            cout<<ans[i]<<' ';
        cout<<ans[i];

        cout<<'\n';
        ans.clear();
    }


    return 0;
}
