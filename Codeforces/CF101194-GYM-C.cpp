#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int len[2000]={},ben[2000]={},tree[2000*4]={},lazy[2000*4]={},arr[2000],x;
bool wall[2000]={};
void build(int in,int s,int e)
{
    if(s==e)
    {
        tree[in]=len[s];
        wall[s]=0;
        lazy[in]=0;
        return ;
    }
    int m=(s+e)/2;
    build(in*2,s,m);
    build(in*2+1,m+1,e);
    tree[in]=max(tree[in*2],tree[in*2+1]);
}
void prop(int in,int s,int e)
{
    if(s!=e)
    {
        lazy[in*2]+=lazy[in];
        lazy[in*2+1]+=lazy[in];
    }
    tree[in]-=lazy[in];
    lazy[in]=0;
}
void up(int in,int s,int e,int f ,int l)
{
    if(s>f||f>e)return ;
    if(s==f&&f==e)
    {
        tree[in]=min(tree[in],l);
        return ;
    }
    int m=(s+e)/2;
    up(in*2,s,m,f,l);
    up(in*2+1,m+1,e,f,l);
    tree[in]=max(tree[in*2],tree[in*2+1]);
}
int get(int in,int s,int e,int f ,int l)
{
    if(s>l||f>e)return 0;
    if(s>=f&&l>=e)
    {
        return tree[in];
    }
    int m=(s+e)/2;
    int a=get(in*2,s,m,f,l);
    int b=get(in*2+1,m+1,e,f,l);
    return max(a,b);
}
int ch[100100]={},chh[100200]={};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,mm=1;
    cin>>t;
    while(t--)
    {
        cin>>x;
        vector<vector<int> > v(100100);
        arr[x]=(int)1e5+5;
        ch[arr[x]]=1;
        chh[arr[x]]=1;
        for(int i=0;i<x;i++)
            cin>>arr[i],v[arr[i]].push_back(i);
        for(int i=0;i<x;i++)
        {
            int k=0;
            for(int j=i;j<=x;j++)
            {
                if(ch[arr[j]]!=0)
                {
                    len[i]=((j-1)-i)+1;
                    k=j;
                    break;
                }
                ch[arr[j]]++;
            }
            for(int j=i;j<k;j++)
                ch[arr[j]]--;
        }
        for(int i=0;i<x;i++)
        {
            int k=0;
            for(int j=i;j>=-1;j--)
            {
                if(j==-1||ch[arr[j]]!=0)
                {
                    ben[i]=(i-(j+1))+1;
                    k=j;
                    break;
                }
                ch[arr[j]]++;
            }
            for(int j=i;j>k;j--)
                ch[arr[j]]--;
        }
        build(1,0,x-1);
        int ans=tree[1];
        for(int i=0;i<x;i++)
        {
           // cout<<len[i]<<' '<<ben[i]<<' '<<i<<endl;
            int k=0;
            for(int j=i;j<=x;j++)
            {
                if(ch[arr[j]]!=0)
                {
                    k=j;
                    break;
                }
                ch[arr[j]]++;
                for(int l=0;l<v[arr[j]].size();l++)
                {
                    if(v[arr[j]][l]>j)
                    {
                        int r=v[arr[j]][l];
                        for(int f=0;f<ben[v[arr[j]][l]]&&!wall[r];f++,r--)
                        {
                            up(1,0,x-1,r,f);
                        }
                        wall[v[arr[j]][l]]=1;
                    }
                }
                ans=max(ans,get(1,0,x-1,j+1,x-1)+(j-i+1));
            }
            for(int j=i;j<k;j++)
                ch[arr[j]]--;

            build(1,0,x-1);
        }
        cout<<"Case #"<<mm++<<": "<<ans<<endl;
        memset(len,0,sizeof len);
    //    memset(ch,0,sizeof len);
        memset(ben,0,sizeof ben);
    }

    return 0;
}
