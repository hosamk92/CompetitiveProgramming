/// use sparse table to get the ranges with max answer and print it


#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll x,y,z;
struct node
{
    ll arr[7]={};
};
node a[100200],b[100200][21],ans[100200],ttt[100200];

node merge(node a1,node a2)
{
    node temp;
    ll sum=0;
    for(int i=0;i<y;i++)
        temp.arr[i]=max(a1.arr[i],a2.arr[i]),sum+=temp.arr[i];
    if(sum>z)temp.arr[5]=0;
    else temp.arr[5]=a1.arr[5]+a2.arr[5];
    return temp;
}
ll vv=0;
void rec(int kk,ll v)
{
    vv=v;
    int k=kk;
    if(kk<0)return;
    for(int j=0;j<x;j++)
        ttt[j]=ans[j];
    for(int i=0;i<20;i++)
    {
        bool c=0;
        for(int j=0;j<=x-(1<<i)-v;j++)
        {
            if(i==0)
                b[j][20]=merge(ans[j],a[j+v]);
            else
                b[j][20]=merge(ans[j],b[j+(1<<i)+v][i-1]);
            if(b[j][20].arr[5]!=0)c=1;
        }
        if(!c)
        {
            k=i-1;
            break;
        }
        for(int j=0;j<x;j++)
            ttt[j]=b[j][20];
    }
    for(int j=0;j<x;j++)
        ans[j]=ttt[j];

    rec(k-1,(1<<k)+v-1);
}
int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    node aa;
    cin>>x>>y>>z;
    for(int i=0;i<x;i++){
        ll sum=0;
        for(int j=0;j<y;j++){
            cin>>a[i].arr[j];
            sum+=a[i].arr[j];
        }
        if(sum<=z)a[i].arr[5]=1;
        for(int j=0;j<y;j++)
            aa.arr[j]=max(aa.arr[j],a[i].arr[j]);
    }
    if(z==0)
    {
        cout<<0;
        return 0;
    }
    {
        int sum=0;
        for(int j=0;j<y;j++)
        {
            sum+=aa.arr[j];
        }
        if(sum<=z)
        {
            for(int j=0;j<y;j++)
                cout<<aa.arr[j]<<' ';
            return 0;
        }
    }
     k=0;
    for(int i=0;i<20;i++)
    {
        bool c=0;
        for(int j=0;j<=x-(1<<i)-1;j++)
        {
            if(i==0)
                b[j][i]=merge(a[j],a[j+1]);
            else
                b[j][i]=merge(b[j][i-1],b[j+(1<<i)][i-1]);
            if(b[j][i].arr[5]!=0)c=1;

        }
        if(!c)
        {
            k=i-1;
            break;
        }
        for(int j=0;j<=x-(1<<i);j++)
            ans[j]=b[j][i];
    }
    rec(k-1,(1<<(k))-1);
    int l=0,maxi=0;;
    for(int i=0;i<=x;i++){
        if(ans[i].arr[5]>maxi)
        {
            maxi=ans[i].arr[5];
            l=i;
        }
    //    cout<<ans[i].arr[0]<<' '<<ans[i].arr[1]<<' '<<ans[i].arr[5]<<endl;
    }
    for(int j=0;j<y;j++)
        cout<<ans[l].arr[j]<<' ';
    return 0;
}
