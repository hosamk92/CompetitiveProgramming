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
int lcm(int a,int b)
{
    return a*b/__gcd(a,b);
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y;
    while(cin>>x)
    {
        int i,a,b;
        vector<pair<int,int> >v;
        for(i=x+1;i<=x*2;i++)
        {
            a=i*x;
            b=i-x;
            if(a%b==0)
            {
                v.push_back({i,a/b});
            }
        }
        cout<<v.size()<<'\n';
        for(i=0;i<v.size();i++)
            cout<<"1/"<<x<<" = 1/"<<v[i].second<<" + 1/"<<v[i].first<<'\n';
    }

    return 0;
}
