/// binery search on the answer and check using sweep line

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll x,y,z,arr[100010]={},temp[100010]={},arr1[100010]={};


bool ch(ll m)
{
    for(int i=0;i<x;i++)
        temp[i]=arr[i];
    ll t=y,val=0,i=0,s=0,f;
    memset(arr1,0,sizeof arr1);
    for(int i=0;i<x;i++)
    {
        s-=arr1[i];
        temp[i]+=s;
     //   cout<<temp[i]<<' '<<s<<' '<<t<<endl;
        if(temp[i]<m)
        {
            if(m-temp[i]>t)return 0;
            t-=(m-temp[i]);
            s+=(m-temp[i]);
            arr1[i+z]+=(m-temp[i]);
            temp[i]=m;
   //         cout<<"LOL "<<t<<' '<<temp[i]<<' '<<(m-temp[i])<<' '<<s<<endl;
        }
    }
    return 1;
}

ll bs()
{
    ll f=0,l=2000000000,m;
    while(f<=l)
    {
        m=(f+l)/2;
       // cout<<m<<endl;
        bool c=ch(m),cc=ch(m+1);
        if(c&&!cc)return m;
        if(c)f=m+1;
        else l=m-1;
    }
    return m;
}

int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>x>>y>>z;
    for(int i=0;i<x;i++){
        cin>>arr[i];
        temp[i]=arr[i];
    }
    cout<<bs();

    return 0;
}
