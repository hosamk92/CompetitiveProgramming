#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

    long long arr[100200]={},a[100200]={};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int x,i;
    cin>>x;
    for(i=0;i<x;i++)cin>>arr[i],a[i]=arr[i];
    sort(a,a+x);
    int s=0;
    for(i=0;i<x;i++)
    {
        if(arr[i]!=a[i])s++;
    }
    if(s<=2)cout<<"YES";
    else cout<<"NO";

    return 0;
}
