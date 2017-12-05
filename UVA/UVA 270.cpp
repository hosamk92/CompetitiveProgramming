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

const double PI = acos(-1.0);

const double EPS = 1e-9;

typedef complex<double> point;

#define X real()
#define Y imag()
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
int ccw(point a, point b, point c) {
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
	return +1;
  if (t < -EPS)
	return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
	return -1;
  if (norm(v1) < norm(v2) - EPS)
	return +1;
  return 0;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,ca=0;
    cin>>n;
    string x;
    cin.ignore();
    getline(cin,x);
    while(n--){
        int a=0,b=0,j=0;
        bool c=0;
        int p[800][2]={};
        while(getline(cin,x)){
            if(x=="") break;
            sscanf(x.c_str(),"%d %d",&p[j][0],&p[j][1]);
            ++j;
        }
        int s,ans=0,k,z;
        for(int i=0;i<j;i++)
        {
            map <double,int> m;
            for(k=0;k<j;k++){
                s=0;
                if(i==k)continue;
                //cout<<p[k][1]-p[i][1]<<' '<<p[k][0]-p[i][0]<<' ';
               // cout<<atan2(p[k][1]-p[i][1],p[k][0]-p[i][0])<<' '<<i<<' '<<k<<endl;
                ans=max(ans,++m[atan2(p[k][1]-p[i][1],p[k][0]-p[i][0])]+1);
            }
        //    cout<<ans<<endl;
        }
        if(ca!=0)cout<<"\n";
        ca++;
        cout<<ans<<'\n';;
    }



    return 0;
}
