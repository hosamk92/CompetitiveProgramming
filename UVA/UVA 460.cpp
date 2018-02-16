/// get the rectangle by it's lower left will be the max lower left of both rectangle and it's upper right will be the min upper right of both rectangles 
/// if the rectnagle doesn't fit in both rectangles or is a edge print no overlap

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
ll tree[30000*4][4]={};
string x;
void build(int in,int s,int e)
{
    if(e==s)
    {
        if(x[s]=='(')tree[in][0]=1;
        else tree[in][1]=1;
        return ;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);

    int t=min(tree[in*2][0],tree[in*2+1][1]);
    tree[in][2]=t+tree[in*2+1][2]+tree[in*2][2];
    tree[in][0]=tree[in*2][0]+tree[in*2+1][0]-t;
    tree[in][1]=tree[in*2][1]+tree[in*2+1][1]-t;
}
void up(int in,int s,int e,int f)
{
    if(s>e||e<f||s>f)return;
    if(f==s&&f==e)
    {
        swap(tree[in][0],tree[in][1]);
        return ;
    }
    int m=(s+e)/2;
    up(in*2,s,m,f);
    up(in*2+1,m+1,e,f);
    int t=min(tree[in*2][0],tree[in*2+1][1]);
    tree[in][2]=t+tree[in*2+1][2]+tree[in*2][2];
    tree[in][0]=tree[in*2][0]+tree[in*2+1][0]-t;
    tree[in][1]=tree[in*2][1]+tree[in*2+1][1]-t;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int x[5],y[5],xx,yy,xx2,yy2;
        for(int i=0;i<4;i++)
            cin>>x[i]>>y[i];
        if(x[1]<x[2]||x[3]<x[0]||y[1]<y[2]||y[3]<y[0])cout<<"No Overlap\n";
        else
        {
            xx=max(x[0],x[2]);
            xx2=min(x[1],x[3]);
            yy=max(y[0],y[2]);
            yy2=min(y[1],y[3]);
            if(xx==xx2||yy==yy2)cout<<"No Overlap\n";
            else
                cout<<xx<<' '<<yy<<' '<<xx2<<' '<<yy2<<'\n';
        }
        if(t)cout<<'\n';

    }



    return 0;
}
