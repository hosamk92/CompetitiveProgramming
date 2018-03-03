/// using two pointers 
/// and segment tree to check the range cost

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
ll x,y,z;
struct node
{
    int a[6]={};
};
node merge(node x,node yy)
{
    node tmp;
    for(int i=0;i<y;i++)
        tmp.a[i]=max(x.a[i],yy.a[i]);
    return tmp;
}
node tree[100100*4]={},arr[100100*4]={};

void build (int in ,int s,int e)
{
    if(s==e)
    {
        tree[in]=arr[s];
        return ;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    tree[in]=merge(tree[in*2],tree[in*2+1]);
}
node qur(int in ,int s,int e,int f,int l)
{
    node tmp;
    if(s>l||f>e||s>e)return tmp;
    if(s>=f&&l>=e)return tree[in];
    int m=(s+e)/2;
    return merge(qur(in*2,s,m,f,l),qur(in*2+1,m+1,e,f,l));
}
inline int getsum(node n)
{
    int sum=0;
    for(int i=0;i<y;i++)
        sum+=n.a[i];
    return sum;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>x>>y>>z;
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            cin>>arr[i].a[j];
    build(1,0,x-1);
    int j=0,ans=0;
    node ans1;
    for(int i=0;i<x;i++)
    {
        for(;j<x;j++)
        {
            j=max(j,i);
            node tmp=qur(1,0,x-1,i,j);
            int sum=getsum(tmp);
          //  cout<<sum<<' '<<i<<' '<<j<<endl;
            if(sum>z)break;
            if(j-i+1>ans)
            {
                ans1=tmp;
                ans=j-i+1;
            }
        }
    }
   // cout<<ans<<endl;
    for(int i=0;i<y;i++)
        cout<<ans1.a[i]<<' ';


    return 0;
}
