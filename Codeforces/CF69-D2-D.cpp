/// dp with 3d first for x and second for y and 3rd for player
/// add all vectors to our point till the distance become bigger 

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int dp[500][500][2];
int v[25]={},vy[25]={},d,n;
int dist(int x,int y){
	return (x-250)*(x-250)+(y-250)*(y-250);
}
int mem(int x,int y,int k)
{
    int dis=dist(x,y);
    if(dis>d)return k;

    int &ret=dp[x][y][k];
    if(ret!=-1)return ret;
    ret=!k;
    for(int i=0;i<n;i++){
        if(k)
        ret=max(ret,mem(x+v[i],y+vy[i],!k));
        else
            ret=min(ret,mem(x+v[i],y+vy[i],!k));
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
    x+=250;
    y+=250;
    d=d*d;
    for(int i=0;i<n;i++)
        cin>>v[i]>>vy[i];
    if(mem(x,y,1))
        cout<<"Anton";
    else
        cout<<"Dasha";

    return 0;
}
