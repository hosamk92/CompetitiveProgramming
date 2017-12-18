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
int dp[103][103]={};
string x,y;
int rec(int i,int j)
{
    if(i>=x.size()||j>=y.size())return 0;
    int &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=0;
    ret=max(ret,rec(i+1,j));
    ret=max(ret,rec(i,j+1));
    if(x[i]==y[j])
        ret=max(ret,1+rec(i+1,j+1));
    return ret;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l=1;
    while(1)
    {
        getline(cin,x);
        if(x[0]=='#')break;
        getline(cin,y);
        if(y[0]=='#')break;
        memset(dp,-1,sizeof dp);
        cout<<"Case #"<<l++<<": you can visit at most "<<rec(0,0)<<" cities.\n";
      //  cout<<rec(0,0)<<endl;
    }


    return 0;
}
