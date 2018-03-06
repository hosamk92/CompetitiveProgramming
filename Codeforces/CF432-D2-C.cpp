/*i am using the idea that all even numbers can be made using 2 prime numbers 
and moving in the array and making selection sort but insted of using nested loop i use segment tree
if the distance between min val and my postion is prime i swap them if not if even i get the two prime number
that make that distance and swap by this order and add swap (i,i+1) since here distance isn't prime but prime +1
if odd i do the same but i leave the last step swap(i,i+1)*/

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
int tree[100000*4]={},arr[100200]={},x;
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
void up(int in,int s,int e,int ind,int v)
{
    if(s>ind||ind>e)return;
    //cout<<s<<' '<<e<<' '<<ind<<endl;
    if(s==e&&s==ind)
    {
      //  cout<<arr[s]<<' '<<v<<endl;
        arr[s]=v;
        tree[in]=s;
        return;
    }
    int m=(s+e)/2;
    up(in*2,s,m,ind,v);
    up(in*2+1,m+1,e,ind,v);
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
bool p[100210]={};
vector<int>v;
vector<pair<int,int> > ans;
pair<int,int> vv[100010]={};
void sort()
{
    int t;
    for(int i=0;i<x;i++)
    {
        int j=qur(1,0,x-1,i,x-1);
        if(i==j)continue;
        int k=j-i+1;
       // cout<<i<<' '<<k<<' '<<j<<' '<<arr[i]<<' '<<arr[j]<<' '<<p[k]<<' '<<vv[k].first<<' '<<vv[k].second<<endl;
        if(!p[k])
        {
            ans.push_back({i,j});
            t=arr[i];
            up(1,0,x-1,i,arr[j]);
            up(1,0,x-1,j,t);
        }
        else if(k%2==0)
        {
            ans.push_back({i+vv[k].first,j});
            t=arr[i+vv[k].first];
            up(1,0,x-1,i+vv[k].first,arr[j]);
            up(1,0,x-1,j,t);
            ans.push_back({i+1,i+vv[k].first});
            t=arr[i+1];
            up(1,0,x-1,i+1,arr[i+vv[k].first]);
            up(1,0,x-1,i+vv[k].first,t);
            ans.push_back({i,i+1});
            t=arr[i+1];
            up(1,0,x-1,i+1,arr[i]);
            up(1,0,x-1,i,t);
        }
        else
        {
            k++;
            ans.push_back({i+vv[k].first,j});
            t=arr[i+vv[k].first];
            up(1,0,x-1,i+vv[k].first,arr[j]);
            up(1,0,x-1,j,t);
            ans.push_back({i,i+vv[k].first});
            t=arr[i];
            up(1,0,x-1,i,arr[i+vv[k].first]);
            up(1,0,x-1,i+vv[k].first,t);

        }
       // break;
    }
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(ll i=2;i<=100000;i++)
    {
        if(!p[i])
        {
            v.push_back(i);
            for(ll j=i*i;j<=100000;j+=i)
                p[j]=1;
        }
    }
    for(int i=4;i<=100000;i+=2)
    {
        for(int j=0;j<v.size();j++)
        {
            if(!p[i-v[j]])
            {
                vv[i]={i-v[j],v[j]};
                break;
            }
        }
    }

    arr[100001]=1e10;
    cin>>x;
    for(int i=0;i<x;i++)
        cin>>arr[i];
    build(1,0,x-1);
    int j=0;
    sort();
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first+1<<' '<<ans[i].second+1<<'\n';;

    return 0;
}
