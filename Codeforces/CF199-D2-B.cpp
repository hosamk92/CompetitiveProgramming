/// check if a circle doesn't intersect with the other 2 circles or if intersect by point
/// in any of this cases add in the counter 

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
bool check(double r,double d,double r1,double r2)
{
   // cout<<abs(d-r)<<' '<<r2<<' '<<r1<<' '<<d+r<<endl;
    if(abs(d-r)+(1e-9)>=r2)return 1;
    if(r1+(1e-9)>=d+r)return 1;
    return 0;
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    double x,y,a,b,X,Y,A,B,ans=0;
    cin>>x>>y>>a>>b>>X>>Y>>A>>B;
    double d=hypot(x-X,y-Y);
    ans+=check(a,d,A,B);
    ans+=check(b,d,A,B);
    ans+=check(A,d,a,b);
    ans+=check(B,d,a,b);
 //   cout<<d<<' ';
//    cout<<ans<<' '<<check(a,d,A,B)<<' '<<check(b,d,A,B)<<' '<<check(A,d,a,b)<<' '<<check(B,d,a,b);;
    cout<<ans;

    return 0;
}
