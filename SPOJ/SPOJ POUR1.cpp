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

    int x;
    cin>>x;
    while(x--)
    {
        int a,b,c,z=0,y=0,ans=1e8,mini;
        cin>>a>>b>>c;
        if(c==0)ans=0;
        if(c==a||c==b)ans=1;
        mini=0;
        while(1)
        {
            if(y==a)break;
            mini+=2;
            y+=b;
            if(y>=a)y=a;
            if(y>c)break;
            if(y==c){
                ans=min(ans,mini);
                break;
            }
        }
        mini=0;
        while(1)
        {
            if(z==b)break;
            mini+=2;
            z+=a;
            if(z>=b)z=b;
            if(z>c)break;
            if(z==c){
                ans=min(ans,mini);
                break;
            }
        }
        y=a;
        mini=1;
        while(1)
        {
            if(y<=0)break;
            mini++;
            y-=b;
            if(y<c)break;
            if(y==c){
                ans=min(ans,mini);
                break;
            }
            mini++;
        }
        z=b;
        mini=1;
        while(1)
        {
            if(z<=0)break;
            mini++;
            z-=a;
            if(z<c)break;
            if(z==c){
                ans=min(ans,mini);
                break;
            }
            mini++;
        }
        if(ans==1e8||c%__gcd(a,b)!=0||c>max(a,b))cout<<-1<<'\n';
        else
        cout<<ans<<'\n';
    }

    return 0;
}