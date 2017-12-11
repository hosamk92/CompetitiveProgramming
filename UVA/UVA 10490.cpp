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
ll p[100]={};
vector<int>v;
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<ll,int>m;
    for(ll i=2;i<=100;i++)
    {
        if(!p[i])
        {
            m[i]=1;
            for(ll j=i*i;j<=100;j+=i)
            {
                p[j]=1;
            }
        }
    }
    ll x,z;
    while(cin>>x)
    {
        if(x==0)break;
        unsigned long long y=fast_pow(2,x-1)*(fast_pow(2,x)-1);

        set<ll>s;
        ll i;
        z=fast_pow(2,x)-1;
        for(i=2;i*i<z;i++)
        {
            if(z%i==0)s.insert(i);
        }
        if(s.size()==0&&m[x])cout<<"Perfect: "<<y<<"!";
        else if(m[x])
            cout<<"Given number is prime. But, NO perfect number is available.";
        else
            cout<<"Given number is NOT prime! NO perfect number is available.";
        cout<<'\n';
    }

    return 0;
}
