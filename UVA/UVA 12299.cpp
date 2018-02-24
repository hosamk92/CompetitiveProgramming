/// make segment tree and then when update time swap all elements in the segment tree according to the index provided

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int size,arr[100]={},a[100200]={};
string q;
int conv()
{
    size = 0 ;
    int len = q.size();
    for(int i=0;i<len;i++)
    {
        int s = 0 ;
        while(isdigit(q[i])&&i<len) s = s*10 + q[i]-'0' , i++ ;
        if(s) arr[size++] = s ;
    }
}
int tree[100200*4]={};
void build(int in,int s,int e)
{
    if(s==e)
    {
        tree[in]=a[s];
        return;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    tree[in]=min(tree[in*2],tree[in*2+1]);
}
void up(int in,int s,int e,int ind,int v)
{
    if(s>ind||e<ind||e<s)return;
    if(s==e&&e==ind)
    {
        a[s]=v;
        tree[in]=a[s];
        return;
    }
    int m=(s+e)/2;
    up(in*2,s,m,ind,v);
    up(in*2+1,m+1,e,ind,v);
    tree[in]=min(tree[in*2],tree[in*2+1]);
}
int qur(int in,int s,int e,int inds,int inde)
{
    if(s>inde||e<inds||e<s)return 1e9;
    if(s>=inds&&e<=inde)
        return tree[in];
    int m=(s+e)/2;
    return min(qur(in*2,s,m,inds,inde),qur(in*2+1,m+1,e,inds,inde));
}
int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x,y;
    cin>>x>>y;
    for(int i=0;i<x;i++)
        cin>>a[i];
    build(1,0,x-1);
    while(y--)
    {
        cin>>q;
        conv();
        if(q[0]=='q')
            cout<<qur(1,0,x-1,arr[0]-1,arr[1]-1)<<'\n';
        else
        {
            int t=a[arr[0]-1];
            for(int i=0;i<size;i++)
            {
                up(1,0,x-1,arr[i]-1,a[arr[i+1]-1]);
            }
            up(1,0,x-1,arr[size-1]-1,t);
        }

    }


    return 0;
}
