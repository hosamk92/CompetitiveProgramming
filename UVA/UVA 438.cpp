/// first make 3 chords by connecting all the points
/// and using cosine law get the angle of one of them
/// divide the one of the chords length with it's oppisit angle 
/// now we have the radius use it to get the output


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

    long double x[5],y[5]={},A,B,C,a,b,c,R,PI=3.141592653589793,up,down,angle,xx;
    while(cin>>x[0]>>y[0]){

        for(int i=1;i<3;i++)
             cin>>x[i]>>y[i];
        A=sqrt( ((x[0]-x[1])*(x[0]-x[1]))+((y[0]-y[1])*(y[0]-y[1])));
        B=sqrt( ((x[0]-x[2])*(x[0]-x[2]))+((y[0]-y[2])*(y[0]-y[2])));
        C=sqrt( ((x[2]-x[1])*(x[2]-x[1]))+((y[2]-y[1])*(y[2]-y[1])));
        a=A*A;
        b=B*B;
        c=C*C;
        up=a+c-b;
        down=2*A*C;
        xx=up/down;
        angle=acos(xx);

        R=B/(sin(angle));
        cout<<fixed<<setprecision(2)<<R*PI<<'\n';
    }



    return 0;
}
