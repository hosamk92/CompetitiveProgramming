/// first we get the value that we would get if cut any rope using DFS
/// then for each node we get the max and the 2nd max in it's which are connect to this node directly or indirectly
/// then loop on all nodes and print the max sum of the 1st max and 2nd max

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
ll arr[200200]={},n,maxi[200200]={},sum[200200]={},maxi2[200200]={};
vector<vector<int> > v(200200);
ll getsum(int i,int p)
{
    ll ans=arr[i];
    for(int j=0;j<v[i].size();j++)
    {
        if(v[i][j]==p)continue;
        ans+=getsum(v[i][j],i);
    }
    sum[i]=ans;
    return ans;
}
ll getmaxi(int i,int p)
{
    if(v[i].size()==1&&i!=1)return maxi2[i]=maxi[i]=i;
    ll ans=-1e10,ans2=-1e10;
    for(int j=0;j<v[i].size();j++)
    {
        if(v[i][j]==p)continue;
        getmaxi(v[i][j],i);

        if(ans==-1e10||sum[v[i][j]]>=sum[ans]||sum[maxi[v[i][j]]]>=sum[ans])
        {
            ans2=ans;
            if(sum[maxi[v[i][j]]]<sum[v[i][j]])
                ans=v[i][j];
            else
                ans=maxi[v[i][j]];
        }
        else if(ans2==-1e10||sum[v[i][j]]>sum[ans2]||sum[maxi[v[i][j]]]>sum[ans2])
            if(sum[maxi[v[i][j]]]<sum[v[i][j]])
                ans2=v[i][j];
            else
                ans2=maxi[v[i][j]];
    }
    maxi[i]=ans;
    maxi2[i]=ans2;
    return 0;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    getsum(1,-1);
    getmaxi(1,-1);
    ll ans=-1e10;
    for(int i=1;i<=n;i++){
  //      cout<<maxi[i]<<' '<<maxi2[i]<<endl;
        if(maxi[i]==-1e10||maxi2[i]==-1e10||maxi[i]==maxi2[i])
            continue;
        else
            ans=max(ans,sum[maxi[i]]+sum[maxi2[i]]);
    }
    if(ans==-1e10)
        cout<<"Impossible";
    else cout<<ans;
    return 0;
}
