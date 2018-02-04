#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

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

ll a[200010]={},b[200010]={};
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);


    while(1)
    {
        ll x,i,j;
        cin>>x;
        if(!x)return 0;
        for(i=0;i<x;i++)
        {
            cin>>a[i]>>b[i];
        }
        int s=0,o=0;
        for(i=0;i<x;i++)
        {
            if(a[i]==a[x/2]||b[i]==b[x/2])
                continue;
            if(a[i]>a[x/2]&&b[i]>b[x/2])s++;
            else if(a[i]<a[x/2]&&b[i]<b[x/2])s++;
            else o++;
        }
        cout<<s<<' '<<o<<'\n';
    }

    return 0;
}
