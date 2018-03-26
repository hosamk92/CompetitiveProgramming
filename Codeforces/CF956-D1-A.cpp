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
vector<vector<int> > v(100),vv(100);
bool NotEqual(int i,int j)
{
    if(v[i].size()!=v[j].size())return 1;
    for(int k=0;k<v[i].size();k++)
    {
        if(v[i][k]!=v[j][k])return 1;
    }
    return 0;
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,i,j;
    char c;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++){
            cin>>c;
            if(c=='#'){
                v[j].push_back(i);
                vv[i].push_back(j);
            }
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=1;j<vv[i].size();j++)
        {
           // cout<<v[i][j]<<' ';
            if(NotEqual(vv[i][j-1],vv[i][j]))
            {
                cout<<"No";
                return 0;
            }
        }
       // cout<<endl;
    }
    cout<<"Yes";



    return 0;
}
