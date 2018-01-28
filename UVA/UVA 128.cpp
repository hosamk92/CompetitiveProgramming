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
string stb(int x)
{
    string z="";
    while(x!=0)
    {
        if(x%2==0)z+='0';
        else z+='1';
        x/=2;
    }
    reverse(z.begin(),z.end());
    return z;
}
ll bts(string x)
{
    ll y=1,z=0;
    for(int i=x.size()-1;i>=0;i--)
    {
        if(x[i]=='1')z+=y;
        y*=2;
    }
    return z;
}



int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string x,q,a;
    while(getline(cin,x)&&x!="#"){
        ll yy,y=0;
        char b;
        for(int i=0;i<x.size();i++)
        {
            y<<=8;
            y+=x[i];
            y%=34943;
        }
        y<<=16;
        y%=34943;
       // cout<<
        for(int i=0;i<=34942;i++)
        {

            yy=y+i;
            if(yy%34943==0)
            {
                q=stb(i);
                while(q.size()<16)
                {
                    q='0'+q;
                }
                for(int k=0;k<16;){
                    string a;
                    for(int j=0;j<4;j++,k++)
                    {
                        a+=q[k];
                    }
                    b=bts(a);
                    if(b>=10)b+=('A'-10);
                    else b+='0';
                    cout<<b;
                    if(k==8)cout<<' ';
                }
                cout<<'\n';
                break;
            }
        }
    }

    return 0;
}
