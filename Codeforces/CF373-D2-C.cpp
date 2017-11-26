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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int x,i,a;
    multiset<pair<int,int> >v;
    multiset<pair<int,int> >::iterator it;
    vector<pair<int,int> >arr;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>a;
        arr.push_back({a,i});
        v.insert({a,i});
    }
    sort(arr.begin(),arr.end());
    pair<int,int>y;
    int ans=0;
    for(i=(x-1)/2;i>=0;i--)
    {
      //  cout<<arr[i]<<endl;
        if(v.empty())break;
        it=v.end();
        it--;

       // cout<<arr[i]<<' '<<it->first<<endl;

        if(v.find({arr[i].first,arr[i].second})==v.end()
           ||2*arr[i].first>(it->first))continue;
        y=*v.lower_bound({2*arr[i].first,0});
    //    cout<<y.first<<' '<<arr[i].first<<' '<<it->first<<endl;
        ans++;
        v.erase({arr[i].first,arr[i].second});
        v.erase(y);

    }


    cout<<x-ans;

    return 0;
}
