#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll arr[500200]={},y,arr2[500200]={},x;
ll bs(ll t,ll ee)
{
    ll f=1,e=ee-1,m;
    if(t<arr[0]||e==0)return 0;
    while(f<=e)
    {
        m=(f+e)/2;
        if(arr[m]+(m*y)<=t&&(arr[m+1]+((m+1)*y)>t||m+1==e))return m;
        if(arr[m]+(m*y)>t)e=m-1;
        else f=m+1;
    }
    return m;
}
ll bs2(ll t,ll ee)
{
    ll f=ee+1,e=x-1,m;
    if(t<arr2[x-1]||f==x)return x;
    while(f<=e)
    {
        m=(f+e)/2;
       // cout<<f<<' '<<e<<' '<<m<<endl;
        if(arr2[m]+((x-m)*y)<=t&&(arr2[m-1]+((x-m+1)*y)>t||m-1==f))return m;
        if(arr2[m]+((x-m)*y)>t)f=m+1;
        else e=m-1;
    }
    return m;
}

int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll z,a,sum=0,maxi=0;
    string s;
    cin>>x>>y>>z>>a;
    cin>>s;
    for(int i=1;i<x;i++)
    {
        sum++;
        if(s[i]=='w')sum+=z;
        arr[i]=sum;
    }
    sum=0;
    for(int i=x-1;i>0;i--)
    {
        sum++;
        if(s[i]=='w')sum+=z;
        arr2[i]=sum;
    }
    if(s[0]=='w'&&a<=z)cout<<0;
    else
    {
        ll ans=1;
        if(s[0]=='w')a-=z;
        a--;
        ll A=a;
        if(a-y<=0)cout<<ans;
        else{
            maxi=max(maxi,ans+bs(a-y,x));
            for(int i=x-1,j=1;i>0;i--,j++)
            {
                ans++;
                a-=y;
                if(s[i]=='w')a-=z;
                a--;
                if(a<0)
                {
                    maxi=max(maxi,ans-1);
                    break;
                }
                if(a-(y*j)<0)
                {
                    maxi=max(ans,maxi);
                    break;
                }
                maxi=max(maxi,ans+bs(a-(y*j),i));
            }
            a=A;
            ans=1;
            for(int i=1,j=1;i<x;i++,j++)
            {
                ans++;
                a-=y;
                if(s[i]=='w')a-=z;
                a--;
                if(a<0)
                {
                    maxi=max(maxi,ans-1);
                    break;
                }
                if(a-(y*j)<0)
                {
                    maxi=max(ans,maxi);
                    break;
                }
             //   cout<<i<<' '<<a-(y*j)<<' '<<ans<<' '<<x-bs2(a-(y*j),i)<<'\n';
                maxi=max(maxi,ans+(x-bs2(a-(y*j),i)));
            }



            cout<<maxi;
        }
    }


    return 0;
}
