#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ll fast_pow(ll a,ll b)
{
	if(b==0)
		return 1ll;
	ll ans=1;
	if(b%2)
		return ans=(fast_pow(a,b-1)*a);
	ans=(fast_pow(a,b/2));
	return ((ans*ans));
}
vector <vector<int> > v;
int vist[1000]={},y,x,a[1000],b[1000];
void dfs(int i)
{
  //  cout<<i<<endl;
    for(int j=0;j<v[i].size();j++)
    {
        if(vist[v[i][j]])continue;
        vist[v[i][j]]=1;
        dfs(v[i][j]);
    }
}
bool ch(double z)
{
    memset(vist,0,sizeof vist);
    v.clear();
    v.resize(y+1);
    double tt,ttt,ss;
    ll r=0;
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(i==j)continue;
            tt=a[i]-a[j];
            tt*=tt;
            ttt=b[i]-b[j];
            ttt*=ttt;
            ss=sqrt(ttt+tt);

            if(ss<=z)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    int s=0;
    for(int i=0;i<y;i++)
    {
      //  cout<<i<<endl;
        if(vist[i])continue;
        s++;
        vist[i]=1;
        dfs(i);
    }
    if(s<=x)return 1;
    return 0;
}
vector <double>arr;
double bs()
{
    int f=0,l=arr.size(),m;
    bool ans1=0,ans=0;
    double z;
    while(f<=l)
    {
        m=(f+l)/2;
        ans=ch(arr[m]);
        ans1=ch(arr[m-1]);
    //    cout<<m<<' '<<z<<' '<<ans<<' '<<ans1<<endl;
        if(!ans1&&ans)return arr[m];
        if(ans)l=m-1;
        else f=m+1;
    }
    return arr[f];
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(x==0)x=1;
        for(int i=0;i<y;i++)
            cin>>a[i]>>b[i];
        double ss,tt,ttt;
        arr.clear();
        for(int i=0;i<y;i++)
            for(int j=0;j<y;j++){
                tt=a[i]-a[j];
                tt*=tt;
                ttt=b[i]-b[j];
                ttt*=ttt;
                ss=sqrt(ttt+tt);
                arr.push_back(ss);
        }
        sort(arr.begin(),arr.end());
      //  cout<<x<<' '<<y<<endl;
        cout<<fixed<<setprecision(2);
        cout<<bs();
        if(t)cout<<'\n';
    }

    return 0;
}
