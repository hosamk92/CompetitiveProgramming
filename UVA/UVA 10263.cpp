#include <bits/stdc++.h>
#include <fstream>

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
struct point
{
    double x,y;
};

double dist(point p1,point p2)
{
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    double tt,eps=1e18;
    while(cin>>tt){
        double x,n,y,maxi=1e18;
        int i;
        double t;
        point p[250],p4,p2,p0,p3,p5,ans;
        p0.x=tt;
        cin>>p0.y;
        cin>>n;
        cin>>p[0].x>>p[0].y;
        for(i=1;i<=n;i++){
            cin>>p[i].x>>p[i].y;
            p2.x=p[i].x-p[i-1].x;
            p2.y=p[i].y-p[i-1].y;

            p3.x=p0.x-p[i-1].x;
            p3.y=p0.y-p[i-1].y;

            p4.x=p0.x-p[i].x;
            p4.y=p0.y-p[i].y;

            x=(p2.x*p3.x)+(p2.y*p3.y);
            y=(p2.x*p2.x)+(p2.y*p2.y);
            t=x/y;
            p5.x=p[i-1].x+(p2.x*t);
            p5.y=p[i-1].y+(p2.y*t);
            if(x<=0){
                if(dist(p[i-1],p0)<maxi){
                    maxi=dist(p[i-1],p0);
                    ans.x=p[i-1].x; ans.y=p[i-1].y;
                }
            }
            else if(y<=x){

                if(dist(p[i],p0)<maxi){
                    maxi=dist(p[i],p0);
                    ans.x=p[i].x; ans.y=p[i].y;
                }
            }
            else{
                if(dist(p5,p0)<maxi){
                    maxi=dist(p5,p0);
                    ans.x=p5.x; ans.y=p5.y;
                }
            }
        }
        cout<<fixed<<setprecision(4)<<ans.x<<'\n'<<ans.y<<'\n';
    }

    return 0;
}
