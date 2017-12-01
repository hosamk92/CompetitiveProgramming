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
struct line
{
    point s,e;
};
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
// check if the line inside the rectangle
bool lol(line l,line l1,line l2,line l3,line l4)
{
    if(ccw(l1.s, l1.e, l.s) == 1 && ccw(l3.s, l3.e, l.s) == -1 &&
       ccw(l2.s, l2.e, l.s) == 1 && ccw(l4.s, l4.e, l.s) == -1)return 1;
       return 0;
}
bool intersect(line l1,line l2)
{
    bool x = (l1.s == l1.e), y = (l2.s==l2.e);
    if(x && y)  return l1.s == l2.s;
    if(x)   return ccw(l2.s, l2.e, l1.s) == 0;
    if(y)   return ccw(l1.s, l1.e, l2.s) == 0;

    float a,b,a1,b1,t=0,t2,e,f,e1,f1,t3,t4,t5,t6,t7,t8,t1;
    point p;

    a=(l2.s.X-l1.s.X)/(l1.e.X-l1.s.X);
    b=(l2.e.X-l2.s.X)/(l1.e.X-l1.s.X);
    e=(l2.s.Y-l1.s.Y)/(l1.e.Y-l1.s.Y);
    f=(l2.e.Y-l2.s.Y)/(l1.e.Y-l1.s.Y);

    e1=(l1.s.X-l2.s.X)/(l2.e.X-l2.s.X);
    f1=(l1.e.X-l1.s.X)/(l2.e.X-l2.s.X);
    a1=(l1.s.Y-l2.s.Y)/(l2.e.Y-l2.s.Y);
    b1=(l1.e.Y-l1.s.Y)/(l2.e.Y-l2.s.Y);


    t2=(e1+(f1*e))/(1-(f1*f));
    if(std::isnan(t2))
    t2=(e1+(f1*a))/(1-(f1*b));
    if(std::isnan(t2))
    t2=(a1+(b1*e))/(1-(b1*f));
    if(std::isnan(t2))
    t2=(a1+(b1*a))/(1-(b1*b));

    t=(a+(b*e1))/(1-(b*f1));
    if(std::isnan(t))
    t=(a+(b*a1))/(1-(b*b1));
    if(std::isnan(t))
    t=(e+(f*e1))/(1-(f*f1));
    if(std::isnan(t))
    t=(e+(f*a1))/(1-(f*b1));

   // cout<<t<<' '<<t2<<endl;

    if(t>=0&&t<=1&&t2>=0&&t2<=1)return 1;
    return 0;
}




int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--){
        line l1,l2,l3,l4,l;
        point s,e;
        double x,y,a,b;

        cin>>a>>x>>b>>y;
        l.s.real(a);
        l.s.imag(x);
        l.e.real(b);
        l.e.imag(y);
        cin>>a>>x>>b>>y;
        s.real(a);
        s.imag(x);
        e.real(b);
        e.imag(y);

        l1.s=l2.e=s;
        l3.s=l4.e=e;

        l1.e.real(s.X);
        l3.e.real(s.X);
        l1.e.imag(e.Y);
        l3.e.imag(e.Y);

    //    l2.s=l4.s=(e.X,s.Y);
        l2.s.real(e.X);
        l4.s.real(e.X);
        l2.s.imag(s.Y);
        l4.s.imag(s.Y);

     //   dis(l4);

        if(intersect(l,l1)
           ||intersect(l,l2)
           ||intersect(l,l3)
           ||intersect(l,l4)
           ||lol(l,l1,l2,l3,l4))
            cout<<"T\n";
        else cout<<"F\n";

    }



    return 0;
}
