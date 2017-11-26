#include <bits/stdc++.h>
#include <fstream>

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
int arr[100200]={};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int x,i,ans=0;
    vector<ll>v;
    cin>>x;
    map<ll,vector<int> > m;
    map<int,int>ma,mm;
    for(i=0;i<x;i++)
    {
        cin>>arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(),v.end());
    for(i=x-1;i>=0;i--)
    {
        m[v[i]].push_back(i);
    }
    for(i=0;i<x;i++)
    {
        ma[i]=m[arr[i]][m[arr[i]].size()-1];;
        m[arr[i]].pop_back();
    }
    int a=0,s=0;
    for(i=0;i<x;i++)
    {
        if(i>=ma[i])a++;
        else mm[ma[i]]++;
        a+=mm[i];
        s++;
        if(a==s)
        {
            ans++;
        }
    }
    cout<<ans;




    return 0;
}
