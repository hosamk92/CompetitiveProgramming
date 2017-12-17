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
vector <vector<int> >v;
vector<bool>vist;
vector<pair<int,string> > ans;
map<int,string>mm;

int y;
int dfs(int i,int a)
{
    int b=0,c;
    for(int j=0;j<v[i].size();j++)
    {
 //       if(vist[v[i][j]])continue;
        if(a!=1)
        b+=dfs(v[i][j],a-1);

        if(vist[v[i][j]])continue;
        vist[v[i][j]]=1;
        c=dfs(v[i][j],y);
        ans.push_back({c,mm[v[i][j]]});
    }
    if(a==1)return v[i].size();
   // cout<<b<<endl;
    return b;
}
bool cmp(pair<int,string>x,pair<int,string>y)
{
    if(x.first==y.first)return x.second<y.second;
    return x.first>y.first;
}



int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,l=1;
    cin>>t;
    while(t--)
    {
        v.resize(1010);
        vist.resize(1010,0);
        ll x,i,j=1,a,b,k,c;
        string z,zz;
        map<string ,int>m;
        cin>>x>>y;
        for(i=0;i<x;i++)
        {
            cin>>z;
            if(m[z]==0)
            m[z]=j,mm[j++]=z;
            cin>>b;
            for(k=0;k<b;k++)
            {
                cin>>zz;
                if(m[zz]==0)
                m[zz]=j,mm[j++]=zz;
                v[m[z]].push_back(m[zz]);
            }
        }
        for(i=0;i<j;i++)
        {
            if(vist[i])continue;
            vist[i]=1;
            c=dfs(i,y);
            ans.push_back({c,mm[i]});
        }
        sort(ans.begin(),ans.end(),cmp);
    //    reverse(ans.begin(),ans.end());
        cout<<"Tree "<<l++<<":\n";
        for(i=0;i<ans.size();i++)
        {
          //  i=ans.size()-j-1;
            if(ans[i].first==0)break;
            if(i>=3&&ans[i].first!=ans[i-1].first)break;
            cout<<ans[i].second<<' '<<ans[i].first<<'\n';
        }
        cout<<'\n';
        ans.clear();
        v.clear();
        vist.clear();
        mm.clear();
    }


    return 0;
}
