#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const double PI = acos(-1.0);

const double EPS = 1e-9;

typedef complex<float> point;


#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

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
double dp[1002][1002][3];
double mem(int i,int j,int k)
{
    if(i==0)return 0;
    if(j==0)return k;
    double &ret=dp[i][j][k];
    if(ret!=-1)return ret;
    ret=0;
    if(k)
    {
        ret=((double)i/(i+j));
        ret+=((double)j*mem(i,j-1,!k)/(i+j));
    }
    else
    {
        ret+=(((double)((double)j*mem(i,j-2,!k)/((i+j)))*((double)(j-1)/(i+j-1)))
        +((double)((double)j*mem(i-1,j-1,!k)/((i+j)))*((double)(i)/(i+j-1))));
    }
    return ret;
}

int main()
{

   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    for(int i=0;i<1001;i++)
        for(int j=0;j<1001;j++)
            dp[i][j][0]=dp[i][j][1]=-1;
    cin>>a>>b;
    cout<<fixed<<setprecision(9)<<mem(a,b,1);

    return 0;
}
