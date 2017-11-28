#include <bits/stdc++.h>
#include <fstream>

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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,k=0;
    cin>>n;
    while(n--)
    {
        ll x,arr[60][6]={},i,j,c;
        ll a[6]={};
        a[2]=a[3]=1e9;
        a[0]=a[1]=-1e9;
        ll ans=0;
        vector <pair<ll,ll> >v ,v1;
        cin>>x;
        for(i=0;i<x;i++)
            for(j=0;j<4;j++){
                cin>>arr[i][j];
                if(j<=1)
                a[j]=max(a[j],arr[i][j]);
                else
                a[j]=min(a[j],arr[i][j]);
            }
    //    cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<' ';
        if(a[2]-a[0]>=0&&a[3]-a[1]>=0)
        ans=max((ll)0,(a[2]-a[0])*(a[3]-a[1]));



        k++;
        cout<<"Case "<<k<<": ";

        cout<<ans<<'\n';

    }

    return 0;
}
