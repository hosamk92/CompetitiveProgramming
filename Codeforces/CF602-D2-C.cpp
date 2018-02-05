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
int dp[500][500],x;
int mem(int a,int b)
{
    if(a==x&&b==x)return 0;
    int &ret=dp[a][b];
    if(ret!=-1)return ret;
    ret=1e8;
    if(a==x)
    {
        for(int i=2;i<=x;i++)
            if(m[b][i])
                ret=min(ret,mem(a,i)+1);
    }
    else if(b==x)
    {
        for(int i=2;i<=x;i++)
            if(!m[a][i])
                ret=min(ret,mem(i,b)+1);
    }
    else
    {
        for(int i=2;i<=x;i++){
            if(!m[a][i]){
                for(int j=2;j<=x;j++)
                {
                    if(i==j&&i!=x)continue;
                    if(m[b][j])
                        ret=min(ret,mem(i,j)+1);
                }
            }
        }
        for(int i=2;i<=x;i++)
            if(!m[a][i])
                ret=min(ret,mem(i,b)+1);
        for(int i=2;i<=x;i++)
            if(m[b][i])
                ret=min(ret,mem(a,i)+1);
    }
    return ret;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp,-1,sizeof dp);
    int y,a,b;
    cin>>x>>y;
    for(int i=0;i<y;i++)
    {
        cin>>a>>b;
        m[a][b]=m[b][a]=1;
    }
    int ans=mem(1,1);
    if(ans==1e8)cout<<-1;
    else cout<<ans;

    return 0;
}
