/// the problem is like a tree of log k (a) levels
/// each element has k elements connected to it
/// first lets sort the array in decreasing order
/// then get cumlicative sum array
/// then we move on our array first by k then k^2 then k^3 and so on
/// for each we add the sum of elements from 1 to k , and k to k^2 / times the power of k
/// then we print this sum

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
ll arr[100200]={},sum[100200]={};
ll a,b,c[100200]={},s=0;

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a;
    for(int i=0;i<a;i++)
        cin>>arr[i];
    sort(arr,arr+a);
    reverse(arr,arr+a);
    for(int i=0;i<a;i++)
    {
        s+=arr[i];
        sum[i]=s;
    }
    cin>>b;
    int x;
    for(int i=0;i<b;i++)
    {
        cin>>x;
        ll z=0,k=1,ans=0;
        z=x;
        if(c[x]!=0)cout<<c[x];
        else
        {
            for(ll j=1;j<a;j+=z,z*=x)
            {
             //   cout<<min((ll)a-1,j+(z)-1)<<' '<<k<<endl;
                ans+=((sum[min((ll)a-1,j+(z)-1)]-sum[j-1])*k);
                k++;
            }
            c[x]=ans;
            cout<<ans;
        }
        cout<<' ';
    }


    return 0;
}
