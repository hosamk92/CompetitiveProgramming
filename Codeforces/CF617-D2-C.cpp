/// make 2 arrays and store in it the distance from the first fountain and the second
/// move on the 2 arrays choose 1 of them as the radius of the first and make the second bigger to cover all distance
/// print the min answer

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;


int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x1,y1,x2,y2,n,a,b,arr[3000],arr2[3000];
    cin>>n>>x1>>y1>>x2>>y2;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        arr[i]=((a-x1)*(a-x1))+((b-y1)*(b-y1));
        arr2[i]=((a-x2)*(a-x2))+((b-y2)*(b-y2));
    }
    arr[n]=0;
    ll ans=1e19;
    for(int i=0;i<=n;i++)
    {
        a=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>arr[i])a=max(a,arr2[j]);
        }
        ans=min(ans,a+arr[i]);
    }
    cout<<ans;



    return 0;
}
