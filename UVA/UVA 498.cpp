#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll fast_pow(ll a,ll b)
{
	if(b==0)
		return 1ll;
	ll ans=1;
	if(b%2)
		return ans=(fast_pow(a,b-1)*a);
	ans=(fast_pow(a,b/2));
	return ((ans*ans));
}

int rec(ll a,ll b)
{
    if(a<=b)swap(a,b);
    if(a%b==0)return 1;
    int ans=!(rec(a%b,b));
    if(ans==1)return ans;
    if(a-b!=a%b)return !rec((a%b)+b,b);
    return ans;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);


    string x,z;
    while(getline(cin, x))
    {
        getline(cin, z);
        ll p;
        istringstream iss(x),is(z);
        vector<ll> v,vv;
        while(iss>>p)
        {
           v.push_back(p);
        }
        while(is>>p)
        {
           vv.push_back(p);
        }
        ll a;
        for(int i=0;i<vv.size();i++)
        {
            ll ans=0;
            a=v.size()-1;
            for(int j=0;j<v.size();j++)
            {
                ans+=(v[j]*fast_pow(vv[i],a--));
            }
            if(i+1!=vv.size())
            cout<<ans<<" ";
            else
                cout<<ans<<'\n';
        }
    }

    return 0;
}
