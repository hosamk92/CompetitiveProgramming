/// get the max number of spheres in the given hight
/// and then check if the remaing space can contain either 1 or 2 spere
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

    double x,y,z,zz;

    long long a,b,c;
    cin>>x>>y;
    b=x;c=y;
    a=y/(x/2)+1;
  //  cout<<a<<' '<<((ld)(a-1)*(x/2.0))<<endl;
    zz=y-((ld)(a-1)*(x/2.0));
    z=sqrt(3.0/8.0)*x;
  //  cout<<z<<' '<<zz<<' '<<z+zz<<endl;
    if(zz+z+(0.03*x)>=x&&zz<y)a++;
    cout<<a;

    return 0;
}
