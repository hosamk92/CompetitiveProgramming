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
bool p[1000020]={};
vector <ll>vec;
ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll i,j;
    map<ll,bool>m;
    int n;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        if(p[i]==0)
        {
            for(j=i;j<=n;j+=i)
            {
                p[j]=1;
            }
            if(m[j-i]==0){
            vec.push_back(j-i);
            m[j-i]=1;
            }
        }
    }
    sort(vec.begin(),vec.end());
   // for(i=0;i<vec.size();i++)cout<<vec[i]<<' ';
    if(n<=1)cout<<n;
    else
    {
        if(vec.size()==1)cout<<vec[0];
        else if(vec.size()==2)cout<<lcm(vec[1],vec[0]);
        else if(vec.size()>=3)cout<<lcm(vec[vec.size()-3],lcm(vec[vec.size()-1],vec[vec.size()-2]));
    }

    return 0;
}
