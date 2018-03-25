/// first get the max number of marks needed for each index
/// then move backward and if the max of the element before me is lower than what i have then decrease what we have

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
ll arr[100200]={},arr2[100200]={};
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin>>x;
    for(int i=1;i<=x;i++)
    {
        cin>>arr[i];
        arr2[i]=max(arr2[i-1],arr[i]);
    }
    ll z=arr2[x]+1,y=0,ans=0;
    for(int i=x;i>=1;i--)
    {
        ans+=(z-arr[i]-1);
        if(arr2[i-1]+1<z)z--;
    }
    cout<<ans;



    return 0;
}
