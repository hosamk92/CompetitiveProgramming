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
int p[20000105]={};
    vector<pair<int,int> > vec;

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<ll>v;

    for(ll i=2;i<=20000100;i++)
    {
        if(!p[i])
        {
            v.push_back(i);
            for(ll j=i*i;j<=20000100;j+=i)
            {
                p[j]=1;
            }
        }
    }
    for(int i=0;;i++)
    {
        if(vec.size()==100000)break;
        if(v[i]==v[i+1]-2)vec.push_back({v[i],v[i+1]});
    }

    ll x,i;
    while(cin>>x)
    {
        x--;
        cout<<"("<<vec[x].first<<", "<<vec[x].second<<")"<<'\n';

    }

    return 0;
}
