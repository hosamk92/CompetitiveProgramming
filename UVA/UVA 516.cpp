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
int p[32769]={};
vector<int>v;
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(ll i=2;i<=32767;i++)
    {
        if(p[i]==0)
        {
            v.push_back(i);
            for(ll j=i*i;j<=32767;j+=i)
                p[j]=1;
        }
    }
    while(1)
    {
        string x;
        getline(cin,x);
        if(x=="0")break;
        istringstream iss(x);
        ll p,ans=0,i;
        vector<ll> vv;
        while(iss>>p)
        {
           vv.push_back(p);
        }
        ans=1;
        for(i=0;i<vv.size();i+=2)
        {
            ans*=(fast_pow(vv[i],vv[i+1]));
        }
        ans--;
        int s=0;
        vector<pair<int,int> >r;
        for(i=0;i<v.size();i++)
        {
            if(ans==1)break;
            if(ans%v[i]==0)
            {
                s=0;
                while(1)
                {
                    if(ans%v[i])break;
                    ans/=v[i];
                    s++;
                }
                r.push_back({v[i],s});
            }
        }
        for(int i=r.size()-1;i>0;i--)
            cout<<r[i].first<<' '<<r[i].second<<' ';
        cout<<r[0].first<<' '<<r[0].second;
        cout<<'\n';
    }
    return 0;
}
