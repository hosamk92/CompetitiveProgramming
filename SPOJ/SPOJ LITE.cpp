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

int a,tree[100000*4+1][2]={},lazy[100000*4+1]={};
void build(int in,int s,int e)
{
    if(s>e)return;
    if(s==e)
    {
        tree[in][0]=1;
        tree[in][1]=0;
        lazy[in]=0;
        return ;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    lazy[in]=0;
    tree[in][0]=tree[in*2][0]+tree[in*2+1][0];
    tree[in][1]=tree[in*2][1]+tree[in*2+1][1];
}
void prop(int in,int s,int e)
{
    if(!lazy[in])return;
    swap(tree[in][0],tree[in][1]);
    if(s!=e){
        lazy[in*2]=(!lazy[in*2]);
        lazy[in*2+1]=(!lazy[in*2+1]);
    }
    lazy[in]=0;
}
int qur(int in,int s,int e,int f,int l)
{
    prop(in,s,e);
    if(f>e||l<s||s>e)return 0;
    if(f<=s&&l>=e)return tree[in][1];
    int m=(s+e)/2;
    return qur(in*2,s,m,f,l)+qur(in*2+1,m+1,e,f,l);
}
void up(int in,int s,int e,int f,int l,int v)
{
    prop(in,s,e);
    if(f>e||l<s||s>e)return ;
    if(f<=s&&l>=e)
    {
        lazy[in]=v;
        prop(in,s,e);
        return;
    }
    int m=(s+e)/2;
    up(in*2,s,m,f,l,v);
    up(in*2+1,m+1,e,f,l,v);
    tree[in][0]=tree[in*2][0]+tree[in*2+1][0];
    tree[in][1]=tree[in*2][1]+tree[in*2+1][1];
}
int main()
{

   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int b;
    cin>>a>>b;
    int x,y,z,q;
    build(1,0,a-1);
    z=1;
    for(int i=0;i<b;i++)
    {
        cin>>q;
        if(q)
        {
            cin>>x>>y;
            cout<<qur(1,0,a-1,x-1,y-1)<<'\n';
        }
        else
        {
            cin>>x>>y;
            up(1,0,a-1,x-1,y-1,z);
        }
    }

    return 0;
}
