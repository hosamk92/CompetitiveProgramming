
/// get the distance between all routers and postions and compare it with the radius if less than radius print yes ///


#include <bits/stdc++.h>

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
    int t,k=1;
    cin>>t;
    while(t--)
    {
        int a,b,x[200],y[200],z[200],xx,yy;
        cin>>a>>b;
        cout<<"Case "<<k++<<":\n";
        for(int i=0;i<a;i++)
            cin>>x[i]>>y[i]>>z[i];
        for(int i=0;i<b;i++)
        {
            cin>>xx>>yy;
            for(int j=0;j<a;j++)
            {
                if((((xx-x[j])*(xx-x[j]))+((yy-y[j])*(yy-y[j])))<=z[j]*z[j])
                {
                    cout<<"Yes\n";
                    goto fin;
                }
            }
            cout<<"No\n";
            fin:;
        }
    }

    return 0;
}

