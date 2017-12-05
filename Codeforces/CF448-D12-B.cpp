#include <bits/stdc++.h>
#include <fstream>

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
	vector<ll> v;
ll n;
ll bs(ll a)
{
    ll f=0,l=n,m;
    while(f<=l)
    {
        m=(f+l)/2;
        if(v[m-1]<a&&v[m]>=a)return m;
        if(v[m]>=a)l=m-1;
        else f=m+1;
    }
    return f;
}
ll bs1(ll a)
{
    ll f=0,l=n,m;
    while(f<=l)
    {
        m=(f+l)/2;
        if(v[m]>a&&v[m-1]<=a)return m-1;
        if(v[m]>a)l=m-1;
        else f=m+1;
    }
    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 //   freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ll x,y,i,j,k,ans=0,a,b;
	cin>>n>>x>>y;
	for(i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    v.push_back(1e10);
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    {
        if(v[i]%x!=0){
        a=(x-(v[i]%x))+((y-1)*x);
        b=(x-(v[i]%x))+((y)*x)-1;
        }
        else
        {
            a=((y-1)*x);
            b=(y*x)-1;
        }
        a=max((ll)0,a);
        if(a<0||b<0)
        {
            if(v[i]%x==0&&y==1)ans++;
            if(v[i]%x!=0&&y==0)ans++;
            continue;
        }
        if(a>b)continue;
        j=lower_bound(v.begin(),v.end(),a+v[i])-v.begin();
        k=upper_bound(v.begin(),v.end(),b+v[i])-v.begin();
     //   if(b+v[i]!=v[k-1])k--;
       // cout<<k<<' '<<j<<endl;
        ans+=max((ll)0,(k-j));
    }
    cout<<ans;

    return 0;
}
