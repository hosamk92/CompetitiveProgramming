#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

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
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

        ll a,b,c;
    while(cin>>a>>b){

        c=b;
        if(b==0||b==1)
        {
            cout<<c<<" divides "<<a<<"!\n";
            continue;
        }
        if(a<=1)
        {
            cout<<c<<" does not divide "<<a<<"!\n";
            continue;
        }
        vector<int>v;
        v.push_back(b);
        for(ll j=2;j*j<=b;j++)
        {
            if(b%j==0)v.push_back(j);
            if(b%(b/j)==0&&j!=b/j)v.push_back(b/j);
        }
        sort(v.begin(),v.end());
        map<ll,int>m;
        map<ll,int>::iterator it;
        for(int i=0;i<v.size();i++)
        {
            while(1)
            {
                if(b%v[i]!=0)break;
                m[v[i]]++;
                b/=v[i];
            }
        }
        for(it=m.begin();it!=m.end();it++)
        {
            ll x,y,ans=0;
            y=(it)->first;
            for(ll j=y;j<=a;j+=y)
            {
                ll x=j;
                while(1)
                {
                    if(x%y!=0)break;
                    ans++;
                    x/=y;
                }
                if(ans>=(it)->second)break;
            }
            if(ans<(it)->second)
            {
                cout<<c<<" does not divide "<<a<<"!\n";
                goto fin;
            }
        }
        cout<<c<<" divides "<<a<<"!\n";
        fin:;
    }

    return 0;
}
