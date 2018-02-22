#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector<vector<int> >v(100200);
bool p[100200]={};
int arr[100200]={},m[100200]={};
int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll i,j;
    for(i=2;i<100001;i++)
    {
        if(!p[i])
        {
            for(j=i;j<100001;j+=i)
            {
                p[i]=1;
                v[j].push_back(i);
            }
        }
    }
    int x;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>arr[i];
        m[arr[i]]=1;
    }
    int ans=0,maxi=1;
    for(i=0;i<x;i++)
    {
        for(j=0;j<v[arr[i]].size();j++)
        {
            ans=0;
            for(int k=arr[i]-v[arr[i]][j];k>0;k-=v[arr[i]][j])
            {
                ans=max(ans,m[k]);
                if(m[k])break;
            }
            m[arr[i]]=max(ans+1,m[arr[i]]);
            maxi=max(maxi,m[arr[i]]);
        }
    }
    cout<<maxi;

    return 0;
}

