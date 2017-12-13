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
int x,y,z,arr[10020]={},m=0;

int rec(int i,int j,int cost)
{
    if(cost<0)return 1e8;
    if(i>=j)return 0;
    if(arr[i]==arr[j])return rec(i+1,j-1,cost);
    m=1;
    return min(rec(i,j-1,cost-1),rec(i+1,j,cost-1))+1;
}


int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r=1;
    cin>>x;
    while(x--){
        cin>>y>>z;
        m=0;
        for(int i=0;i<y;i++)cin>>arr[i];
        int ans=rec(0,y-1,z);
        cout<<"Case "<<r++<<": ";
        if(ans>z)cout<<"Too difficult";
        else if(m==0)cout<<"Too easy";
        else cout<<ans;
        cout<<'\n';
    }

    return 0;
}
