#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

    vector<pair<int,int> > v;
    ll x,y[100200]={},z,a[100200]={},m[100200]={};
int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>x;
    int t=0;
    for(int i=0;i<x;i++){
        cin>>y[i];
        a[y[i]]++;
        if(a[y[i]]!=1)t=1;
    }
    int ans=0,tmp=0;
    int tmp2=0,tmp3=1e8,counter;
    for(int i=0;i<x;i++){
        cin>>z;
        tmp2=max(tmp2,(int)z);
        v.push_back({z,y[i]});
        ans+=z;
        m[y[i]]+=z;
    }
    if(!t)
    {
        cout<<ans-tmp2;
        return 0;
    }
    sort(v.begin(),v.end());
   // cout<<ans<<endl;
    for(int i=100000;i>=0;i--)
    {
        if(a[i])
        {
       // cout<<i<<' ';
            counter=min(a[i]-1,x-a[i]-(a[i]-1));
           // cout<<counter<<' ';
            if(a[i]==1)
            {
                tmp3=min((ll)tmp3,ans-m[i]);
             //   cout<<endl;
                continue;
            }
            if(counter<=0)
            {
                tmp3=0;
                break;
            }
            tmp=m[i];
            for(int j=x-1;j>=0;j--)
            {
                if(v[j].second>=i)continue;
                if(0>=counter)break;
                counter--;
           //     cout<<v[j].first<<endl;
                tmp+=v[j].first;
            }
         //   cout<<tmp<<' '<<counter<<endl;
            tmp3=min(tmp3,ans-tmp);
        }
    }
    cout<<tmp3<<endl;



    return 0;
}
