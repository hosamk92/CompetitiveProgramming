#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

long long x,arr[100200]={},tree[400200]={};
long long merge(long long t1,long long t2)
{
    if(!t1)return t2;
    if(!t2)return t1;
    if(t1%t2==0)return t2;
    if(t2%t1==0) return t1;
    return __gcd(t1,t2);
}
void build(long long in,long long s,long long e)
{
    if(s==e)
        tree[in]=arr[s];
    if(s>=e)return;
    long long m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    tree[in]=merge(tree[2*in+1],tree[2*in]);
}
long long query(long long in,long long s,long long e,long long f,long long l)
{
    if(s>e||f>e||s>l)return 0;
    if(f<=s&&e<=l)
        return tree[in];
    long long m=(s+e)/2,ans=query(in*2,s,m,f,l),ans2=query(in*2+1,m+1,e,f,l);
    return merge(ans,ans2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    long long i,y,a,b,ans;
    map<long long ,vector <int> > m;
    cin>>x;
    for(i=0;i<x;i++){
        cin>>arr[i];
        m[arr[i]].push_back(i);
    }
    build(1,0,x-1);
    int lo,hi;
    cin>>y;
    for(i=0;i<y;i++)
    {
        cin>>a>>b;
        ans=query(1,0,x-1,a-1,b-1);
        {
            lo=lower_bound(m[ans].begin(),m[ans].end(),a-1)-m[ans].begin();
            hi=upper_bound(m[ans].begin(),m[ans].end(),b-1)-m[ans].begin();
            hi--;
            cout<<(b-a+1)-(hi-lo+1)<<'\n';

        }

    }

    return 0;
}
