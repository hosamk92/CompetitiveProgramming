/// keep moving left and see how far can you go right by using two pointers and do it the other way too
/// keep moving right and see how far can you go left 
/// and print the max

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll arr[500200]={},y,arr2[500200]={},x;

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
        arr2[x-i]=sum;
    }
    arr[x]=arr2[x]=1e10;
    arr[0]=arr2[0]=-1e10;
    if(s[0]=='w'&&a<=z)cout<<0;
    else
    {
        maxi=0;
        ll ans=1,A,j=0;
        if(s[0]=='w')a-=z;
        a--;
        A=a;
        ll temp=0,t;
        for(int i=1;i<=x;i++)
        {
            temp+=y;
            if(arr[i]+temp>a)
            {
                t=temp-y;
                j=i-1;
                break;
            }
        }
        maxi=max(maxi,ans+j);
        for(int i=x-1,l=1;i>=1;i--,l++)
        {
            ans++;
            a-=y;
            if(s[i]=='w')a-=z;
            a--;
            if(a<0)
            {
                maxi=max(ans-1,maxi);
                break;
            }
            for(int k=j;k>=0;k--)
            {
                if(k<i&&arr[k]+t<=a-(y*l))
                {
                    j=k;
                    break;
                }
                t-=y;
            }
         //   cout<<ans<<' '<<j<<' '<<(a-(y*l))<<' '<<t<<endl;
            maxi=max(maxi,ans+j);
        }

        a=A;
        temp=0;
        ans=1;
        for(int i=1;i<=x;i++)
        {
            temp+=y;
            if(arr2[i]+temp>a)
            {
                t=temp-y;
                j=i-1;
                break;
            }
        }
        maxi=max(maxi,ans+j);
        for(int i=1;i<x;i++)
        {
            ans++;
            a-=y;
            if(s[i]=='w')a-=z;
            a--;
            if(a<0)
            {
                maxi=max(ans-1,maxi);
                break;
            }
            for(int k=j;k>=0;k--)
            {
                if(x-k>i&&arr2[k]+t<=a-(i*y))
                {
                    j=k;
                    break;
                }
                t-=y;
            }
           // cout<<ans<<' '<<j<<endl;
            maxi=max(maxi,ans+j);
        }

        cout<<maxi;
    }


    return 0;
}
