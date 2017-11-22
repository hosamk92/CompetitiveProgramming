#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    string x,y;
    cin>>x>>y;
    if(x.size()<y.size())
    {
        cout<<0;return 0;
    }
    int i,j,arr[27]={},t=0,k,ans=0,a[27]={},c;
    for(i=0;i<y.size();i++)a[y[i]-'a']++;
    for(i=0;i<x.size();i++)
    {
        if(i>=y.size())
        {
            k=0;c=1;
            for(j=0;j<27;j++)
            {
                if(arr[j]>a[j]){
                c=0;break;
                }
                if(arr[j]<a[j])k+=(a[j]-arr[j]);
            }
            if(t>=k&&c)ans++;
        }
        if(x[i]!='?')
        arr[x[i]-'a']++;
        else t++;
        if(i>=y.size())
        {
            if(x[i-y.size()]!='?')
            arr[x[i-y.size()]-'a']--;
            else t--;
        }
    }
    k=0;c=1;
    for(j=0;j<27;j++)
    {
        if(arr[j]>a[j]){
                c=0;break;
        }
        if(arr[j]<a[j])k+=(a[j]-arr[j]);
    }
    if(t>=k&&c)ans++;
    cout<<ans;



    return 0;
}
