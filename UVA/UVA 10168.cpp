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
vector<ll>v;
bool p[10000003]={};
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(ll i=2;i<10000003;i++)
    {
        if(!p[i])
        {
            v.push_back(i);
            for(ll j=i*i;j<10000003;j+=i)
                p[j]=1;
        }
    }

    int t;
    while(cin>>t)
    {
        ll i=0;
        if(t<8)cout<<"Impossible."<<'\n';
        else
        {
            t-=2;
            if(t%2==0)
            {
                t-=2;
                for(i=0;i<v.size();i++)
                {
                    if(!p[t-v[i]])
                    {
                        cout<<2<<' '<<2<<' '<<v[i]<<' '<<t-v[i]<<'\n';
                        break;
                    }
                }
            }
            else
            {
                for(i=0;i<v.size();i++)
                {
                    if(!p[t-v[i]-v[i]])
                    {
                        cout<<2<<' '<<v[i]<<' '<<v[i]<<' '<<t-v[i]-v[i]<<'\n';
                        break;
                    }
                }
            }
        }
    }


    return 0;
}
