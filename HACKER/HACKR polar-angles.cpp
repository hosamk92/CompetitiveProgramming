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

    int n;
    cin>>n;
    double h,w,i,ans=-1,j,m;
//    cout<<acos(-1)<<endl;
    vector <pair<pair<double,double> , pair<double,double> > > vec;
    for(i=0;i<n;i++)
    {
        cin>>h>>w;
        ans=(atan2(w,h)*180)/acos(-1);
        if(ans<0)ans+=360;
        m=(h*h)+(w*w);
        m=sqrt(m);
        vec.push_back(make_pair(make_pair(ans,m),make_pair(h,w)));
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<vec.size();i++)
    {
        cout<<vec[i].second.first<<' '<<vec[i].second.second<<endl;
    }



    return 0;
}
