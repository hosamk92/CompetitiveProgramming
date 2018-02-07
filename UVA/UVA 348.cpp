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
int x,a[20]={},b[20]={};
ll maxi=1e18,ANS=0;
string z;
void rec(int s,int e,ll score,string ans,ll f,ll ff)
{
    string Z;
    if(s==-1&&e==x)
    {
        if(score<maxi)
        {
            maxi=score;
            z=ans;
        }
    }
    ll nwscore=score;
    string g="";
    if(s!=-1){
        if(s+1==10)Z="10";
        else Z=((s+1)+'0');
        rec(s-1,e,score+(a[s]*f*ff),"(A"+Z+" x "+ans+")",a[s],ff);
        g="A"+Z;
        for(int i=s-1;i>0;i--){
            if(i+1==10)Z="10";
            else Z=((i+1)+'0');
            nwscore+=(a[i]*a[i+1]*b[i+1]);
            g="(A"+Z+" x "+g+")";
            rec(i-1,e,nwscore+(a[i]*f*ff),"("+g+" x "+ans+")",a[i],ff);
        }

    }
    if(e!=x){
        nwscore=score;
        if(e+1==10)Z="10";
        else Z=((e+1)+'0');
        rec(s,e+1,score+(b[e]*f*ff),"("+ans+" x "+"A"+Z+")",f,b[e]);
        g="A"+Z;
        for(int i=e+1;i<x;i++){
            if(i+1==10)Z="10";
            else Z=((i+1)+'0');
            nwscore+=(a[i]*b[i]*a[i-1]);
            g="("+g+" x A"+Z+")";
            rec(s,i+1,nwscore+(b[i]*f*ff),"("+ans+" x "+g+")",f,b[i]);
        }
    }
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k=1;
    while(1)
    {
        maxi=1e18;
        cin>>x;
        if(x==0)return 0;
        for(int i=0;i<x;i++)
        {
            cin>>a[i]>>b[i];
        }
        z="";
        string Z,ZZ;
        for(int i=0;i<x-1;i++)
        {
            if(i+1==10)Z="10";
            else Z=((i+1)+'0');
            if(i+2==10)ZZ="10";
            else ZZ=((i+2)+'0');
            rec(i-1,i+2,a[i]*b[i]*b[i+1],"(A"+Z+" x "+"A"+ZZ+")",a[i],b[i+1]);
        }
        cout<<"Case "<<k++<<": "<<z<<' '<<ANS<<'\n';
        ANS=0;
    }

    return 0;
}
