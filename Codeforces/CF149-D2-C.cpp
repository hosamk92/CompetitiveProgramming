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

    vector <int>ans,ans1;
    vector<pair<int,int> > arr;
    int x,i,y;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>y;
        arr.push_back({y,i+1});
    }
    if(arr.size()%2==1)arr.push_back({0,-1});
    sort(arr.begin(),arr.end());
    for(i=arr.size()-1;i>=1;i-=2){
        ans.push_back(arr[i].second);
        if(arr[i-1].first!=0)
        ans1.push_back(arr[i-1].second);
    }
    cout<<ans.size()<<'\n';
    for(i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    cout<<'\n';
    cout<<ans1.size()<<'\n';
    for(i=0;i<ans1.size();i++)cout<<ans1[i]<<' ';
    cout<<'\n';

    return 0;
}
