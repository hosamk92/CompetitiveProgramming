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
int a,b,x,y,ans[2000][3]={},dp[1010][1010][3]={};
char arr[1010][1010]={};
int mem(int i,int j,int k)
{
  //  cout<<i<<' '<<j<<' '<<k<<endl;
    if(i==b&&j<x)return 1e8;
    if(i==b)return 0;
    if(j>y)return 1e8;
    int &ret=dp[i][j][k];
    if(ret!=-1)return ret;
    ret=1e8;
    if(k==0)
    {
        if(j>=x)
            ret=min(ret,mem(i+1,1,1)+ans[i][1]);
        ret=min(ret,mem(i+1,j+1,0)+ans[i][0]);
    }
    else
    {
        if(j>=x)
            ret=min(ret,mem(i+1,1,0)+ans[i][0]);
        ret=min(ret,mem(i+1,j+1,1)+ans[i][1]);
    }
    return ret;
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp,-1,sizeof dp);
    cin>>a>>b>>x>>y;
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
            cin>>arr[i][j];
    for(int i=0;i<b;i++)
        for(int j=0;j<a;j++)
        {
            if(arr[j][i]=='.')ans[i][0]++;
            else ans[i][1]++;
        }
    cout<<min(mem(1,1,0)+ans[0][0],mem(1,1,1)+ans[0][1]);

    return 0;
}
