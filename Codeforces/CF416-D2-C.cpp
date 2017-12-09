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
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<int,int>arr[1020];
    int x,a[1020]={},b[1020]={},i,y,j;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>a[i]>>b[i];
    }
    cin>>y;
    for(i=0;i<y;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr,arr+y);
    map<int,bool>m;
    vector<pair<int,int> > v;
    int sum=0,k,maxi;
    for(i=0;i<y;i++)
    {
        maxi=0; k=0;
        for(j=0;j<x;j++)
        {
            if(m[j+1]==1)continue;
            if(a[j]<=arr[i].first)
            {
                if(b[j]>maxi)
                {
                    maxi=b[j];
                    k=j+1;
                }
            }
        }
        if(k!=0)
        {
            m[k]=1;
            sum+=maxi;
            v.push_back({k,arr[i].second+1});
        }
    }
    cout<<v.size()<<' '<<sum<<'\n';
    for(i=0;i<v.size();i++)
        cout<<v[i].first<<' '<<v[i].second<<'\n';
    return 0;
}
