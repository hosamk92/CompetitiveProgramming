///check if any two lines intersect and the output the ones that never intersect
#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;
const double PI = acos(-1.0);

const double EPS = 1e-9;

typedef complex<double> point;

#define X real()
#define Y imag()
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define normalize(a)            (a)/length(a)

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
bool intersect(point p1, point p2, point p3, point p4) {
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
  }
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

   /* P = A + t AB ---- (1)
    P = C + s CD ---- (2)
    CA + t AB = s CD
    CA × AB = s (CD × AB) ---- (3)*/
    int tt=0;
    cin>>tt;
    while(tt--){
        int ss[200]={},ans=0;
        double a[200],b[200],c[200],d[200];
        int x;
        cin>>x;
        for(int i=0;i<x;i++)
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        for(int i=0;i<x;i++)
        {
            for(int j=i+1;j<x;j++){
                point A(a[i],b[i]),B(c[i],d[i]),C(a[j],b[j]),D(c[j],d[j]);

                if(intersect(A,B,C,D))
                {

                    ss[i]++;
                    ss[j]++;
                }
            }
        }
        for(int i=0;i<x;i++)if(ss[i]==0)ans++;
        cout<<ans<<'\n';
    }


    return 0;
}
