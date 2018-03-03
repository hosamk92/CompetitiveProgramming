/// use recursion to check all solution and output the min

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

typedef complex<double> point;

ll a[6]={},b[6]={},maxi=1e9;

inline double dist(ll x,ll y,ll xx,ll yy)
{
    return sqrt(((x-xx)*(x-xx))+((y-yy)*(y-yy)));
}

bool ch(ll *x,ll *y)
{
    ll x1=x[0],y1=y[0],x2=x[0],y2=y[0],j=0,k=0,xx[6]={},yy[6]={};
    for(ll i=0;i<4;i++)
    {
        for(ll j=0;j<4;j++)
        {
            if(i==j)continue;
            if(x[i]==x[j]&&y[i]==y[j])return 0;
        }
    }
    for(ll i=0;i<4;i++)
    {
  //      cout<<x[i]<<' '<<y[i]<<"  ";
        if(y[i]==y1&&x[i]>x1)
        {
            j=i;
            x1=x[i];
        }
        if(y[i]>y1)
        {
            y1=y[i];
            x1=x[i];
            j=i;
        }

        if(y[i]==y2&&x[i]<x2)
        {
            k=i;
            x2=x[i];
        }
        if(y[i]<y2)
        {
            y2=y[i];
            x2=x[i];
            k=i;
        }
    }
    ld eps=1e-9;
   // cout<<endl;
    ll l=0;
    for(ll i=0;i<4;i++)
    {
        if(i==j||i==k)continue;
        xx[l]=x[i];
        yy[l++]=y[i];
    }
    xx[3]=x[j]; yy[3]=y[j];
    xx[2]=x[k]; yy[2]=y[k];
    bool f=( (dist(xx[3],yy[3],xx[0],yy[0])==dist(xx[3],yy[3],xx[1],yy[1]))&&
             (dist(xx[2],yy[2],xx[0],yy[0])==dist(xx[2],yy[2],xx[1],yy[1])) &&
             (dist(xx[2],yy[2],xx[0],yy[0])==dist(xx[3],yy[3],xx[0],yy[0])) &&
             (abs(dist(xx[2],yy[2],xx[3],yy[3])-(dist(xx[3],yy[3],xx[0],yy[0])*sqrt(2)))<=eps));

//    cout<<' '<<dist(xx[2],yy[2],xx[3],yy[3])<<' '<<(dist(xx[3],yy[3],xx[0],yy[0])*sqrt(2))<<' '<<f<<endl;
    return f;
}

ll rec(ll i,ll *x,ll *y,ll ans)
{
    if(i==4){
      //  cout<<ans<<' ';
        if(ch(x,y)){
            maxi=min(maxi,ans);
        }
        return 0;
    }
    rec(i+1,x,y,ans);
    for(ll j=0;j<3;j++)
    {
        x[i]-=a[i];
        y[i]-=b[i];
        ll xx=x[i];
        x[i]=-y[i];
        y[i]=xx;
        x[i]+=a[i];
        y[i]+=b[i];
        rec(i+1,x,y,ans+j+1);
    }
    x[i]-=a[i];
    y[i]-=b[i];
    ll xx=x[i];
    x[i]=-y[i];
    y[i]=xx;
    x[i]+=a[i];
    y[i]+=b[i];
    return 0;
}


int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--){
        maxi=1e9;
        ll x[6],y[6];
        for(ll i=0;i<4;i++){
            cin>>x[i]>>y[i]>>a[i]>>b[i];
        }
        rec(0,x,y,0);
        if(maxi==1e9)cout<<-1;
        else cout<<maxi;
        cout<<'\n';
    }


    return 0;
}
