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
int tree[100010*2+1][2]={},arr[100010];
void build(int in,int s,int e)
{
    if(s==e)
    {
        tree[in][0]=arr[s];
        tree[in][1]=0;
        return;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    tree[in][0]=max(tree[in*2][0],tree[in*2+1][0]);
    tree[in][1]=max(min(tree[in*2][0],tree[in*2+1][0]),
                    max(tree[in*2][1],tree[in*2+1][1]));
}
void up(int in,int s,int e,int ele,int v)
{
    if(s>ele||e<ele||e<s)return;
    if(s==e&&ele==e)
    {
        tree[in][0]=v;
        tree[in][1]=0;
        return;
    }
    int m=(s+e)/2;
    up(in*2,s,m,ele,v);
    up(in*2+1,m+1,e,ele,v);
    tree[in][0]=max(tree[in*2][0],tree[in*2+1][0]);
    tree[in][1]=max(min(tree[in*2][0],tree[in*2+1][0]),
                    max(tree[in*2][1],tree[in*2+1][1]));
}
pair<int,int> qur(int in,int s,int e,int f,int l)
{
    if(s>l||e<f||e<s)return pair<int,int>();
    if(s>=f&&l>=e)
    {
        return make_pair(tree[in][0],tree[in][1]);
    }
    int m=(s+e)/2;
    pair<int,int>x,y,z;
    x=qur(in*2,s,m,f,l);
    y=qur(in*2+1,m+1,e,f,l);
    z.first=max(x.first,y.first);
    z.second=max(min(x.first,y.first),
                    max(x.second,y.second));
    return z;
}

int main()
{

   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int b,a;
    cin>>a;
    int x,y,z;
    char q;
    for(int i=0;i<a;i++)
        cin>>arr[i];
    cin>>b;
    build(1,0,a-1);
    pair<int,int>ans;
    z=1;
    for(int i=0;i<b;i++)
    {
        cin>>q;
        if(q=='Q')
        {
            cin>>x>>y;
            ans=qur(1,0,a-1,x-1,y-1);
            cout<<ans.first+ans.second<<'\n';
        }
        else
        {
            cin>>x>>y;
            up(1,0,a-1,x-1,y);
        }
    }

    return 0;
}
