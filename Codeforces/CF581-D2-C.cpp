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

    int x,a,i,y,ans=0;
    cin>>x>>y;
    priority_queue <pair<int,int> > arr;
    for(i=0;i<x;i++)
    {
        cin>>a;
        ans+=(a/10);
        arr.push({(a%10),100-a});
    }
    pair<int,int>p;
    while(1)
    {
        p=arr.top();
        arr.pop();
       // cout<<p.second<<' '<<p.first<<' '<<y<<endl;
        if(p.second<10-p.first||10-p.first>y)break;
        arr.push({0,p.second-(10-p.first)});
        y-=(10-p.first);
        ans++;
    }
    cout<<ans;



    return 0;
}
