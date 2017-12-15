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
int x,y,arr[200],arr1[200];
int dp[10300][505]={};
int mem(int i,int s)
{
    if(s>x+200)return -1e8;
    if(i==y)
    {
        if((s>2000&&s<=x+200)||(s<=x))
        return 0;
        return -1e8;
    }
    int &ret=dp[s][i];
    if(ret!=-1)return ret;
    ret=-1e8;
    ret=max(ret,mem(i+1,s));
    ret=max(ret,mem(i+1,s+arr[i])+arr1[i]);
    return ret;

}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin>>x>>y)
    {
        memset(dp,-1,sizeof dp);
        for(int i=0;i<y;i++)cin>>arr[i]>>arr1[i];
        int ans1=mem(0,0);
        cout<<(ans1)<<'\n';
    }

    return 0;
}
