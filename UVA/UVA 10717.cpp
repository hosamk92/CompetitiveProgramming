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
int lcm(int a,int b)
{
    return a*b/__gcd(a,b);
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x,y;
    while(cin>>x>>y)
    {
        int ar[20]={},arr[200]={},i;
        int ans=0;
        if(x==0&&y==0)break;
        for(i=0;i<x;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<y;i++)
        {
            cin>>ar[i];
            int ans=-1e8,a,b,c,d,ans1=1e8,z;
            for(int j=0;j<x;j++)
                for(int k=j+1;k<x;k++)
                    for(int l=k+1;l<x;l++)
                        for(int r=l+1;r<x;r++)
                        {
                            a=arr[j]; b=arr[k]; c=arr[l]; d=arr[r];
                            z=lcm(a,lcm(b,lcm(c,d)));
                           // cout<<z<<endl;
                            if(ar[i]%z==0){
                                ans=ans1=ar[i];
                                goto lol;
                            }
                            ans=max((ar[i]/z)*z,ans);
                            ans1=min((ar[i]/z+1)*(z),ans1);
                        }
            lol:;
            cout<<ans<<' '<<ans1<<'\n';
        }
    }

    return 0;
}
