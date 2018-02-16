///     use the tree to know if the string is correct or not by making each node to have left and right and complete if the root has right=0 and left=0 then it's correct

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

    int d,k=1;
    while(cin>>d){
        int a,b;
        string z;
        string c;
        cin>>x>>a;
        cout<<"Test "<<k++<<":\n";
        build(1,0,d-1);
        for(int i=0;i<a;i++)
        {
            cin>>b;
            {
                if(b==0){
                if(tree[1][0]==0&&tree[1][1]==0)cout<<"YES\n";
                else cout<<"NO\n";
                }
                else
                up(1,0,d-1,b-1);
            }
        }
  //      cout<<endl;
        memset(tree,0,sizeof tree);
    }



    return 0;
}
