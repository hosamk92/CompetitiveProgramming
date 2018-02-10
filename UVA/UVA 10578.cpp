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
int dp[35][6][6][6][6][6][6];
int mem(int i,vector<int> v)
{
    if(i==0)return 0;
    int &ret=dp[i][v[6]][v[1]][v[2]][v[3]][v[4]][v[5]];
    if(ret!=-1)return ret;
    ret=0;
    for(int j=1;j<=6;j++)
    {
        if(i-j>=0&&v[j]>0)
        {
            v[j]--;
            ret=max(ret,((int)!mem(i-j,v)));
            v[j]++;
        }
    }
    return ret;
}

int main()
{

   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x;
    memset(dp,-1,sizeof dp);
    while(cin>>x)
    {
       vector<int>v(7,4);
       int z=31;
       for(int i=0;i<x.size();i++)
       {
           z-=(x[i]-'0');
           v[(x[i]-'0')]--;
       }
       int ans=mem(z,v);
       cout<<x<<' ';
       if(x.size()%2==0)ans=!ans;
       if(ans)cout<<"B"<<'\n';
       else cout<<"A"<<'\n';
    }

    return 0;
}
