///  get all of the nodes connected to each by xoring it with power of 2 and use dfs to get max

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

vector<vector<int> >v;
int arr[(1<<16)+10]={};
bool ch[(1<<16)+10]={};
int dfs(int i,int k)
{
    int ans=0,ans1=0;
    if(k==2)return 0;
    for(int j=0;j<v[i].size();j++)
    {
        if(ch[v[i][j]])continue;
        if(k==0)ch[v[i][j]]=1;
        ans+=arr[v[i][j]];
    }
    for(int j=0;j<v[i].size();j++)
    {
       // if(ch[v[i][j]])continue;
        ans1=max(ans1,dfs(v[i][j],k+1));
    }
    if(k==0)
        for(int j=0;j<v[i].size();j++)
            ch[v[i][j]]=0;
    return ans+ans1;
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    while(cin>>t){
        v.resize((1<<t)+1);
        for(int i=0;i<(1<<t);i++)
            cin>>arr[i];
        for(int i=0;i<(1<<t);i++)
        {
            for(int j=0;j<t;j++)
            {
                v[i].push_back( ( (1<<j) ^ (i) ) );
            }
        }
        int ans=0;
        for(int i=0;i<(1<<t);i++){
            //    memset(ch,0,sizeof ch);
            ch[i]=1;
            ans=max(ans,dfs(i,0)+arr[i]);
            ch[i]=0;
        }
        cout<<ans<<'\n';
    //    cout<<endl;
        v.clear();
    }



    return 0;
}
