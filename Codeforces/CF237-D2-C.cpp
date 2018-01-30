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
int np[1000100]={},arr[1000100]={};

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll i,j,a,b,c;
    for(i=2;i<1000001;i++)
    {
        if(!np[i])
        {
            for(j=i*i;j<1000001;j+=i)
                np[j]=1;
        }
    }
    arr[0]=arr[1]=0;
    ll ans=0,x;
    map<int,int>m;
    for(i=2;i<1000001;i++)
    {
        arr[i]=arr[i-1]+(!np[i]);
        if(!np[i])m[arr[i]]=i;
    }
    cin>>a>>b>>c;
    if(c>arr[b]-arr[a-1])
    {
        cout<<-1;return 0;
    }
    j=a;
    for(i=a;i<=b;i++)
    {
        x=m[arr[i-1]+c];
      //  cout<<i<<' '<<x<<' '<<x-i+1<<' '<<ans<<' '<<arr[i-1]<<' '<<c<<endl;
        if(x>b&&ans==0)
        {
            cout<<-1;return 0;
        }
        else if(x>b||m[arr[i-1]+c]==0)
        {
            ans=max(ans,b-j+1);
            break;
        }
        else
        {
        //    ans=max(ans,(ll)1);
            if(x-i+1>ans){
                ans=min(max(a,b-i+1),x-i+1);
            }
            j=i;
        }

        if(i>=b-ans+1)break;
    }
    cout<<ans;

    return 0;
}
