#include <bits/stdc++.h>
///******************************try everything using recursion and adding dp with unordered maps to avoid time limit **********************************

#include <fstream>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll ans=0;
unordered_map<ll,bool>dp[3]={},m;
int rec(ll i,bool k,int s)
{
    int ret=!k,ss=0;
    if(dp[k].find(i)!=dp[k].end())
        return dp[k][i];
    dp[k][i]=ret;
    for(ll j=2;j*j<=i;j++)
    {
        if(i%j==0)
        {
            ss++;
            if(k)
            ret=max(ret,rec(j,!k,s+1));
            else
            ret=min(ret,rec(j,!k,s+1));
            if(ret==1&&k)
            {
                ans=j;
                dp[k][i]=1;
                return 1;
            }
        }
        if((i%(i/j))==0&&i/j!=j)
        {
            ss++;
            if(k)
            ret=max(ret,rec(i/j,!k,s+1));
            else
            ret=min(ret,rec(i/j,!k,s+1));
            if(ret==1&&k)
            {
                dp[k][i]=1;
                ans=i/j;
                return 1;
            }
        }
    }

    if(ss==0)return dp[k][i]=k;;
    dp[k][i]=ret;
    return ret;

}
int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x;
    cin>>x;
    int t=rec(x,1,0);
    if(t){
    cout<<t<<'\n';
    cout<<ans;
    }
    else cout<<2;

    return 0;
}

