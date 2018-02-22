/// make sweep line for all X coordinate and put in it vector contian the index of the shot 
/// then move on all targets from their X-coordinate - Radius to X-coordinate + Radius 
/// and the if any element in the sweep line can be in the target if yes add it

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int x,t,tt,neg=4*10000,xx[200100]={},yy[200100]={},a[20010]={},ch[20010]={},r[20010]={},ans[20010];
vector<vector<int> >m(neg+neg);

int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>x;
    for(int i=0;i<x;i++){
        cin>>t>>r[i];
        a[i]=t+neg;
        ans[i]=1e6;
    }
    int y;
    cin>>y;
    for(int j=0;j<y;j++)
    {
        cin>>t>>tt;
        xx[j]=t+neg;
        yy[j]=tt+neg;
        m[xx[j]].push_back(j);
    }
    int anss=0;
    for(int i=0;i<x;i++)
    {
        for(int j=a[i]-r[i];j<=a[i]+r[i];j++)
        {
            for(int k=0;k<m[j].size();k++)
            {
                int l=m[j][k];
           //     cout<<r[i]<<' '<<yy[l]<<' '<<xx[l]<<' '<<a[i]<<' '<<l<<'\n';
         //       cout<<i<<' '<<l<<endl;
                if(r[i]*r[i]>=((yy[l]-neg)*(yy[l]-neg))+((xx[l]-a[i])*(xx[l]-a[i])) )
                {
                    if(ch[i]==0)anss++;
                    ch[i]=1;
                //    cout<<"LOL";
                    ans[i]=min(ans[i],l+1);
                    break;
                }
            }
        }
    }
    cout<<anss<<'\n';
    for(int i=0;i<x;i++)
        if(ans[i]==1e6)cout<<-1<<' ';
        else cout<<ans[i]<<' ';

    return 0;
}

