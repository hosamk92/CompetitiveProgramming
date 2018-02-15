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
ll tree[100000*4]={};
ll lazy[100000*4]={};

void prop(int in,int s,int e)
{
    tree[in]+=(lazy[in]*(e-s+1));
    if(s!=e){
    lazy[in*2]+=lazy[in];
    lazy[in*2+1]+=lazy[in];
    }
    lazy[in]=0;
}
void up(int in,int s,int e,int f,int l)
{
    if(lazy[in])prop(in,s,e);
    if(s>e||f>e||s>l)return;
    if(f<=s&&l>=e)
    {
        lazy[in]++;
        prop(in,s,e);
        return ;
    }
    int m=(s+e)/2;
    up(in*2,s,m,f,l);
    up(in*2+1,m+1,e,f,l);
    tree[in]=tree[in*2]+tree[in*2+1];
}
ll qur(int in,int s,int e,int f,int l)
{
    if(lazy[in])prop(in,s,e);
    if(s>e||f>e||s>l)return 0;
    if(f<=s&&l>=e)
        return tree[in];
    int m=(s+e)/2;
    return qur(in*2,s,m,f,l)+qur(in*2+1,m+1,e,f,l);
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,k=1;
    cin>>t;
    while(t--)
    {
        int a,b,d,x;
        string z;
        string c;
        cin>>x>>a;
        cout<<"Scenario #"<<k++<<":\n";
        for(int i=0;i<a;i++)
        {
            cin>>z>>b>>d;
            if(z[0]=='a')cout<<qur(1,0,x-1,b-1,d-1)<<'\n';
            else
            {
                up(1,0,x-1,b-1,d-1);
                cout<<"OK\n";
            }
        }
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);

    }



    return 0;
}
