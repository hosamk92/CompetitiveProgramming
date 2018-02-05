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
bool m[500][500]={};
int w[500]={},w1[500]={};
int x;
int dij()
{
    priority_queue<pair<int,int> > p;
    pair<int,int> pp;
    p.push({600-0,1});
    int s,i,j;
    w[1]=0;
    while(!p.empty())
    {
        pp=p.top();
        p.pop();
        s=600-pp.first; i=pp.second;
   //     cout<<i<<' '<<s<<endl;
        if(i==x)return s;

        for(int k=1;k<=x;k++)
            if(m[i][k]&&w[k]>s+1)
            {
                w[k]=s+1;
                p.push({600-(s+1),k});
            }
    }
    return w[x];
}
int dij1()
{
    priority_queue<pair<int,int> > p;
    pair<int,int> pp;
    p.push({600-0,1});
    int s,i,j;
    w1[1]=0;
    while(!p.empty())
    {
        pp=p.top();
        p.pop();
        s=600-pp.first; i=pp.second;
   //     cout<<s<<' '<<i<<endl;
        if(i==x)return s;
        for(int k=1;k<=x;k++)
            if(!m[i][k]&&w1[k]>s+1)
            {
                w1[k]=s+1;
                p.push({600-(s+1),k});
            }
    }
    return w1[x];
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int y,a,b;
    cin>>x>>y;
    for(int i=0;i<y;i++)
    {
        cin>>a>>b;
        m[a][b]=m[b][a]=1;
    }
    for(int i=1;i<=x;i++)
            w[i]=w1[i]=1e8;
    int ans=dij(),ans1=dij1();
    ans=max(ans,ans1);
    if(ans==1e8)cout<<-1;
    else cout<<ans;

    return 0;
}
