#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const double PI = acos(-1.0);

const double EPS = 1e-3;

typedef complex<float> point;

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
struct line
{
    point a,b;
    int x,y,z;
    bool p;
    void geteqn()
    {
         x=b.X-a.X;
         y=b.Y-a.Y;
         z=__gcd(x,y);
         x/=z;
         y/=z;
         z=(a.Y-(a.X*y/x));
         if(x==0)p=1;
    }
    line(point A,point B)
    {
        p=0;
        a=A; b=B;
        geteqn();
    }
};
point inter(line l1,line l2)
{
    point pp;
    double a,b,c,d;
    a=((double)l1.y/l1.x)-((double)l2.y/l2.x);
    c=l2.z-l1.z;
    b=(double)c/a;
    c=(b-l1.a.X)/(l1.b.X-l1.a.X);
    d=l1.a.Y+(c*(l1.b.Y-l1.a.Y));
    pp=point(b,d);
    return pp;
}
point inter(point p,line l1)
{
    point pp;
    double a,b,c,d;
    b=p.X;
    c=(b-l1.a.X)/(l1.b.X-l1.a.X);
    d=l1.a.Y+(c*(l1.b.Y-l1.a.Y));
    pp=point(b,d);
    return pp;
}
point intery(point p,line l1)
{
    point pp;
    double a,b,c,d;
    b=p.Y;
    c=(b-l1.a.Y)/(l1.b.Y-l1.a.Y);
    d=l1.a.X+(c*(l1.b.X-l1.a.X));
    pp=point(d,b);

    return pp;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    cout<<"INTERSECTING LINES OUTPUT\n";
    while(t--)
    {
        point p[5],ppp;
        map<pair<ll,ll>,int>m;
        int x,y,s=0;
        for(int i=0;i<4;i++){
            cin>>x>>y;
            p[i]=point(x,y);
        }
        line l1(p[0],p[1]),l2(p[2],p[3]);
        cout<<fixed<<setprecision(2);
   //     cout<<l1.x<<' '<<l1.y<<' '<<l1.z<<' '<<l1.p<<endl;
     //   cout<<l2.x<<' '<<l2.y<<' '<<l2.z<<' '<<l2.p<<endl;
        if(l1.p&&l2.p&&p[0].X==p[2].X)cout<<"LINE\n";
        else if(l1.x==l2.x&&l1.y==l2.y&&l2.z!=l1.z&&!l1.p&&!l2.p)cout<<"NONE\n";
        else if(l1.x==l2.x&&l1.y==l2.y&&l2.z==l1.z&&!l1.p&&!l2.p)cout<<"LINE\n";
        else
        {
            if(p[0].Y==p[1].Y)ppp=intery(p[0],l2);
            else if(p[2].Y==p[3].Y)ppp=intery(p[2],l1);
            else if(l1.p)ppp=inter(p[0],l2);
            else if(l2.p)ppp=inter(p[2],l1);
            else
            ppp=inter(l1,l2);
            cout<<"POINT "<<ppp.X<<' '<<ppp.Y<<"\n";
        }

     /*   if(s==0)cout<<"NONE\n";
        else if(s==1)cout<<"POINT "<<ppp.X<<' '<<ppp.Y<<"\n";
        else cout<<"LINE\n";
*/
    }
    cout<<"END OF OUTPUT\n";


    return 0;
}
