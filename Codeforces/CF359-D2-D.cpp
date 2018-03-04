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
vector<vector<int> >v(1000010);

int tree[300100*4]={},arr[300100*4]={};

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
    tree[in]=__gcd(tree[in*2],tree[in*2+1]);
}
int qur(int in ,int s,int e,int f,int l)
{
    if(s>l||f>e||s>e)return 0;
    if(s>=f&&l>=e)return tree[in];
    int m=(s+e)/2;
    return __gcd(qur(in*2,s,m,f,l),qur(in*2+1,m+1,e,f,l));
}
bool ch(int m)
{
    if(m>=x)return 0;
    int ans;
    vector<int>::iterator it;
    for(int i=0;i<x-m;i++)
    {
        ans=qur(1,0,x-1,i,i+m);
        it=lower_bound(v[ans].begin(),v[ans].end(),i);
        if(v[ans][it-v[ans].begin()]<=i+m)return 1;
    }
    return 0;
}
int bs()
{
    int f=0,l=x-1,m;
    while(f<=l)
    {
        m=(f+l)/2;
        bool c=ch(m);
        if(c)f=m+1;
        else l=m-1;
    }
    if(ch(f))return f;
    return l;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>x;
    for(int i=0;i<x;i++){
        cin>>arr[i];
        v[arr[i]].push_back(i);
    }
    for(int i=0;i<1000001;i++)
        v[i].push_back(1e8);

    build(1,0,x-1);
    int m=bs();

    int ans;
    vector<int>::iterator it;
    vector<int>vec;
    for(int i=0;i<x-m;i++)
    {
        ans=qur(1,0,x-1,i,i+m);
        it=lower_bound(v[ans].begin(),v[ans].end(),i);
        if(v[ans][it-v[ans].begin()]<=i+m)
        {
            vec.push_back(i);
        }
    }
    cout<<vec.size()<<' '<<m<<'\n';
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]+1<<' ';



    return 0;
}
