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
int arr[10][10]={};
vector<vector<pair<int,int> > > vec,vec2;
void rec(int i,int j ,vector<pair<int,int> > v)
{
    if(v.size()==8)
    {
        vec.push_back(v);

    }
    if(i==9)return;
    if(arr[i][j]==0)
    {
        for(int k=1;k<=8;k++)
            arr[k][j]++;
        for(int l=1;l<=8;l++)
            arr[i][l]++;
        arr[i][j]--;

        for(int k=1;k<=8;k++)
        {
            if(i+k<=8&&j+k<=8)
                arr[i+k][k+j]++;
            if(i-k>=1&&j-k>=1)
                arr[i-k][j-k]++;
            if(i+k<=8&&j-k>=1)
                arr[i+k][j-k]++;
            if(i-k>=1&&j+k<=8)
                arr[i-k][j+k]++;
        }


        v.push_back({i,j});
        if(j==8)
        rec(i+1,1,v);
        else
            rec(i,j+1,v);
        v.pop_back();
        for(int k=1;k<=8;k++)
            arr[k][j]--;
        for(int l=1;l<=8;l++)
            arr[i][l]--;
        arr[i][j]++;
        for(int k=1;k<=8;k++)
        {
            if(i+k<=8&&j+k<=8)
                arr[i+k][k+j]--;
            if(i-k>=1&&j-k>=1)
                arr[i-k][j-k]--;
            if(i+k<=8&&j-k>=1)
                arr[i+k][j-k]--;
            if(i-k>=1&&j+k<=8)
                arr[i-k][j+k]--;
        }

    }
    if(j==8)
    rec(i+1,1,v);
    else
        rec(i,j+1,v);
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x,y,a,b,c,d,s;
    cin>>x>>y>>a>>b;

    if(a==b||y==1)s=1;
    else if(b%y==0&&b-a<y)s=1;
    else if(b%y>a%y&&b-a<y&&a%y)s=1;
    else if(a%y==1&&b%y==0)s=1;
    else if(b==x&&a%y==1)s=1;

    else if(b==x)s=2;
    else if(b%y==0||a%y==1)s=2;
    else if(b%y==((a-1)%y))s=2;
    else if(b-a<y)s=2;
    else if(b-a<y*2&&((b%y==0||b%y>y/2)||((y-(a%y))>y/2&&a%y!=0)))s=2;
    else s=3;

    cout<<s;


    return 0;
}
