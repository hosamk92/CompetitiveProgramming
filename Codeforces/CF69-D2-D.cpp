#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int dp[500][500][2][2][2];
int v[25]={},vy[25]={},d,n;
int mem(int x,int y,int k,int m1,int m2)
{
    double dis=x+y;
  //  cout<<x<<' '<<y<<' '<<dis<<' '<<d<<endl;
    int &ret=dp[x][y][k][m1][m2];
    if(ret!=-1)return ret;
    ret=!k;
    if(dis>=d)
    {
        if(k&&m1)return 0;
        if(!k&&m2)return 1;
        if(k&&!m1)
        {
            ret=max(ret,mem(y,x,!k,1,m2));
            if(ret)return ret;
        }
        else if(!k&&!m2)
        {
            ret=min(ret,mem(y,x,!k,m1,1));
            if(!ret)return ret;
        }
        return ret;
    }

    for(int i=0;i<n;i++)
    {
        if(k)
        {
            ret=max(ret,mem(x+v[i],y+vy[i],!k,m1,m2));
            if(ret)return ret;
        }
        else
        {
            ret=min(ret,mem(x+v[i],y+vy[i],!k,m1,m2));
            if(!ret)return ret;
        }
    }
    if(k&&!m1)
    {
        ret=max(ret,mem(y,x,!k,1,m2));
        if(ret)return ret;
    }
    else if(!k&&!m2)
    {
        ret=min(ret,mem(y,x,!k,m1,1));
        if(!ret)return ret;
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
    int x,y;
    cin>>x>>y>>n>>d;
    for(int i=0;i<n;i++)
        cin>>v[i]>>vy[i];
    if(mem(x,y,1,0,0))
        cout<<"Anton";
    else
        cout<<"Dasha";

    return 0;
}

