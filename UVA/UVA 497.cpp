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
int sti(string x)
{
    if(x=="0")return 0;
    int z=0;
    for(int i=0;i<x.size();i++)
    {
        z*=10;
        z+=(x[i]-'0');
    }
    return z;
}
int v[10002]={};
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    cin.ignore();
    string a;
    getline(cin,a);
    while(t--)
    {
        int i=0,dp[10002]={};
        while(1){
            string x;
            getline(cin,x);
            if(x=="")
            {
                break;
            }
            v[i++]=sti(x);
        }
        dp[0]=1;
        int ans=1;
        for(int j=1;j<i;j++)
        {
            for(int k=j;k>=0;k--)
            {
                if(v[j]>=v[k])
                dp[j]=max(dp[j],dp[k]+1);
                ans=max(dp[j],ans);
            }
        }
        cout<<"Max hits: "<<ans<<"\n";
        vector<int>vec;
        for(int j=i-1;j>=0;j--)
        {
            if(dp[j]==ans)
            {
                ans--;
                vec.push_back(v[j]);
            }
        }
        for(int j=vec.size()-1;j>=0;j--)
            cout<<vec[j]<<'\n';
        if(t)
        cout<<'\n';

    }


    return 0;
}
