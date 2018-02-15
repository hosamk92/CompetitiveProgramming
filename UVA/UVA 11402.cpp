/// save the number of the two types in the segment tree and make lazy for update in case of I invert invert the child to avoid problems ///

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
int tree[1024000*4][3]={};
char lazy[1024000*4];
string x;
void build(int in,int s,int e)
{
    if(s>e)
    {
        tree[in][0]=tree[in][1]=0;
        lazy[in]='0';
        return;
    }
    if(s==e)
    {
        if(x[s]=='0')
        tree[in][0]=1;
        else tree[in][1]=1;
        lazy[in]='0';
        return ;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    tree[in][0]=tree[in*2][0]+tree[in*2+1][0];
    tree[in][1]=tree[in*2][1]+tree[in*2+1][1];

    lazy[in]='0';
}
void prop(int in,int s,int e)
{
    int sum=tree[in][0]+tree[in][1];

    if(lazy[in]=='F')
    {
        tree[in][1]=sum;
        tree[in][0]=0;
    }
    else if(lazy[in]=='E')
    {
        tree[in][0]=sum;
        tree[in][1]=0;
    }
    else
    {
        sum=tree[in][0];
        tree[in][0]=tree[in][1];
        tree[in][1]=sum;
        if(s==e)
        {
            lazy[in]='0';
            return;
        }
        if(lazy[in*2]=='E')lazy[in*2]='F';
        else if(lazy[in*2]=='F')lazy[in*2]='E';
        else if(lazy[in*2]=='I')lazy[in*2]='0';
        else lazy[in*2]='I';

        if(lazy[in*2+1]=='E')lazy[in*2+1]='F';
        else if(lazy[in*2+1]=='F')lazy[in*2+1]='E';
        else if(lazy[in*2+1]=='I')lazy[in*2+1]='0';
        else lazy[in*2+1]='I';
        lazy[in]='0';
        return;
    }
    if(s!=e)
    lazy[in*2]=lazy[in*2+1]=lazy[in];
    lazy[in]='0';
}
void up(int in,int s,int e,int f,int l,char v)
{
    if(lazy[in]!='0')prop(in,s,e);
    if(s>e||f>e||s>l)return;
    if(f<=s&&l>=e)
    {
        lazy[in]=v;
        prop(in,s,e);
        return ;
    }
    int m=(s+e)/2;
    up(in*2,s,m,f,l,v);
    up(in*2+1,m+1,e,f,l,v);
    tree[in][0]=tree[in*2][0]+tree[in*2+1][0];
    tree[in][1]=tree[in*2][1]+tree[in*2+1][1];
}
int qur(int in,int s,int e,int f,int l)
{
    if(lazy[in]!='0')prop(in,s,e);
    if(s>e||f>e||s>l)return 0;
    if(f<=s&&l>=e)
    {
     //   cout<<s<<' '<<e<<' '<<tree[in][1]<<' ';
        return tree[in][1];
    }
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
        int a,b,d;
        char z;
        string c;
        x="";
        cin>>a;
        for(int i=0;i<a;i++)
        {
            cin>>b>>c;
            while(b--)
                x+=c;
        }
      //  cout<<x<<'\n';
        build(1,0,x.size()-1);
        cin>>a;
        cout<<"Case "<<k++<<":\n";
        int sss=1;
        for(int i=0;i<a;i++)
        {
            cin>>z>>b>>d;
            if(z=='S')cout<<"Q"<<sss++<<": "<<qur(1,0,x.size()-1,b,d)<<'\n';
            else
             up(1,0,x.size()-1,b,d,z);
        }
      //  for(int i=0;i<=x.size()*2;i++)
    //        tree[i][0]=tree[i][1]=0,lazy[i]='0';
        memset(tree,0,sizeof tree);

    }



    return 0;
}
