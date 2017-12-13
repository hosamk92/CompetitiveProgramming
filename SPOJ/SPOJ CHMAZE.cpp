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
char arr[30][30][20]={};
int x,y,z;
int c[30][30][20]={};
int dx[]={0,0,1,-1,0};
int dy[]={1,-1,0,0,0};
int dfs(int i,int j,int k,int cost)
{
    if(c[i][j][k]<cost||i>=x||j>=y||k>=z||i<0||k<0||j<0||arr[i][j][k]=='1')
        return 1e8;
    if(i==x-1&&j==y-1)return cost;
    c[i][j][k]=cost;
    int ans=1e8;
    for(int l=0;l<5;l++)
        ans=min(ans,dfs(i+dx[l],j+dy[l],(k+1)%z,cost+1));
    return ans;
}


int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r=1;
    while(1){
        int i,j,k;
        cin>>x>>y>>z;
        if(x==0&&y==0&&z==0)break;

        for(i=0;i<z;i++)
            for(j=0;j<x;j++)
                for(k=0;k<y;k++){
                    cin>>arr[j][k][i];
                    c[j][k][i]=1e8;
                }
        c[0][0][0]=1e8;
        int ans=dfs(0,0,0,0);
        cout<<"Case "<<r++<<": ";
        if(ans==1e8)cout<<"Luke and Leia cannot escape.";
        else
            cout<<"Luke and Leia can escape in "<<ans<<" steps.";
        cout<<'\n';
    }

    return 0;
}
