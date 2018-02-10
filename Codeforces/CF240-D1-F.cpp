#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

double Fib(double x,double z);
string BinDec(ull x);
string StringInt(ll x);
ull StringInt(string x);
ull BinDec (string x);
ull POWMOD (ull x,ull y,ull mod);
ull POWE(long long , long long);

int x,tree[4*100002][30]={},lazy[4*100002]={};
string st;

void prop(int in,int s,int e)
{
    int v=lazy[in]-'a';
    for(int i=0;i<27;i++)tree[in][i]=0;
    if(s==e)
    {
        tree[in][lazy[in]-'a']=1;
        st[s]=lazy[in];
    }
    else
    {
        tree[in][v]=(e-s+1);
        lazy[in*2]=lazy[in*2+1]=v+'a';
    }
    lazy[in]=0;
}

void build(int in,int s,int e)
{
    if(s==e)
    {
        tree[in][st[s]-'a']++;
        return;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    for(int i=0;i<27;i++)
        tree[in][i]=tree[in*2][i]+tree[in*2+1][i];
}
void fi(int in,int s,int e)
{
    if(lazy[in])prop(in,s,e);
    if(s==e)
    {
        return;
    }
    int m=(s+e)/2;
    fi(in*2,s,m);
    fi(in*2+1,m+1,e);
    for(int i=0;i<27;i++)
        tree[in][i]=tree[in*2][i]+tree[in*2+1][i];
}

struct Node
{
    int arr[30]={};
};

Node qur(int in,int s,int e,int ss,int ee)
{
    if(lazy[in])prop(in,s,e);
    if(ss>e||ee<s||s>e)return Node();
    Node arr,arr1;
    for(int i=0;i<27;i++)arr.arr[i]=tree[in][i];
    if(ss<=s&&ee>=e)
        return arr;
    int m=(s+e)/2;
    arr=qur(in*2,s,m,ss,ee);
    arr1=qur(in*2+1,m+1,e,ss,ee);
    for(int i=0;i<27;i++)arr.arr[i]+=arr1.arr[i];
    return arr;
}
void qurr(int in,int s,int e,int ss,int ee,int v)
{
    if(lazy[in])prop(in,s,e);
    if(ss>e||ee<s||s>e)return;
    if(ss<=s&&ee>=e)
    {
        lazy[in]=v+'a';
        prop(in,s,e);
        return;
    }
    int m=(s+e)/2;
    qurr(in*2,s,m,ss,ee,v);
    qurr(in*2+1,m+1,e,ss,ee,v);
    for(int i=0;i<27;i++)
        tree[in][i]=tree[in*2][i]+tree[in*2+1][i];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    Node ans;

    int y;
    int i,c,k,q,q1;
    cin>>x>>y;
    cin>>st;
    build(1,0,x-1);
    for(i=0;i<y;i++)
    {
        cin>>q>>q1;
        q--;
        q1--;
        c=0;
        k=0;
        ans=qur(1,0,x-1,q,q1);
        for(int j=0;j<27;j++)
        {
            if(ans.arr[j]%2==1)c++,k=j,ans.arr[j]--;
        }
        if(c<=1)
        {
            if(c)
            qurr(1,0,x-1,q+q1 >> 1,q1+q >>1,k);
            for(int j=0;j<27;j++)
            {
                if(ans.arr[j]==0)continue;
                qurr(1,0,x-1,q,q+(ans.arr[j]/2)-1,j);
                qurr(1,0,x-1,q1-(ans.arr[j]/2)+1,q1,j);
                q=q+(ans.arr[j]/2);
                q1=q1-(ans.arr[j]/2);
            }
        }
    }
    fi(1,0,x-1);
    cout<<st;


    return 0;
}
