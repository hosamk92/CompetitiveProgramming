/// D&C there will be only 3 cases
/// min value time size
/// left side of min val
/// right side of min val
/// use segment tree to get min val in O(logn)

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
ll tree[100000*4]={},arr[100200]={},x;
void build(int in,int s,int e)
{
    if(s==e)
    {
        tree[in]=s;
        return ;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    if(arr[tree[in*2]]>arr[tree[in*2+1]])tree[in]=tree[in*2+1];
    else tree[in]=tree[in*2];
}
ll qur(int in,int s,int e,int f,int l)
{
    if(s>e||s>l||f>e)return 100001;
    if(f<=s&&l>=e)
        return tree[in];
    int m=(s+e)/2;
    ll v,i=qur(in*2,s,m,f,l),j=qur(in*2+1,m+1,e,f,l);
    if(arr[i]>arr[j])v=j;
    else v=i;

    return v;
}
ll DC(ll i,ll j)
{
    if(i>j)return 0;
    if(i==j)return arr[i];
    ll mini=qur(1,0,x-1,i,j);
   // cout<<mini<<endl;
    ll ans=arr[mini]*(j-i+1);
    ll k=mini;
    ans=max(ans,DC(i,k-1));
    ans=max(ans,DC(k+1,j));

    return ans;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    arr[100001]=1e10;
    while(1)
    {
        cin>>x;
        if(!x)return 0;
        for(int i=0;i<x;i++)
            cin>>arr[i];
        build(1,0,x-1);
        int j=0;

        cout<<DC(0,x-1)<<"\n";

    }


    return 0;
}
