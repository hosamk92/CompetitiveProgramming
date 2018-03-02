/// binery search the for the requird quilty

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector<pair<string,pair<ll,ll> > > v;
ll n,mon;

bool ch(ll m)
{
    map<string,bool> M;
    map<string,bool>::iterator it;
    ll t=0;
    for(int i=0;i<v.size();i++)
    {
        if(M[v[i].first]||v[i].second.second<m)continue;
        t+=v[i].second.first;
        M[v[i].first]=1;
    }
    if(t>mon)return 0;
    for(it=M.begin();it!=M.end();it++)
    {
        if((it)->second!=1)return 0;
    }
    return 1;
}

ll bs()
{
    ll f=0,l=1000000001,m;
    while(1)
    {
        m=(f+l)/2;
        bool c=ch(m),cc=ch(m+1);
        if(c&&!cc)return m;
        if(c)f=m+1;
        else l=m-1;
    }
}

int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll q,p;
        string t,type;
        cin>>n>>mon;
        for(int i=0;i<n;i++){
            cin>>type>>t>>p>>q;
            v.push_back({type,{p,q}});
        }
        sort(v.begin(),v.end());
        cout<<bs()<<'\n';
        v.clear();
    }




    return 0;
}
