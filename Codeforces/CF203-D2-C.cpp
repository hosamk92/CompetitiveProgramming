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

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x,y,i,j,a,b,c,d;
    vector<pair<ll,int> > v;
    vector<int>ans;

    cin>>x>>y;
    cin>>a>>b;
    for(i=0;i<x;i++)
    {
        cin>>c>>d;
        v.push_back({(a*c)+(b*d),i});
    }
    sort(v.begin(),v.end());
    for(i=0;i<x;i++)
    {
        if(v[i].first>y)break;
        y-=v[i].first;
        ans.push_back(v[i].second);
    }
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
        cout<<ans[i]+1<<' ';

    return 0;
}
