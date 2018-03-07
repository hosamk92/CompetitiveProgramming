/// brute force all vertices and check if every 4 can be square and the other 4 can be rectangle

#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>


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

ll fast_pow(ll a,ll b,ll mod)
{
	if(b==0)
		return 1ll;
	ll ans=1;
	if(b%2)
		return ans=(fast_pow(a,b-1,mod)*a)%mod;
	ans=(fast_pow(a,b/2,mod)%mod);
	return ((ans*ans)%mod);
}
bool checkSq(vector<pair<int,int> >v)
{
    sort(v.begin(),v.end());
    vector<int>x,y;
    for(int i=0;i<v.size();i++)
    {
        x.push_back(v[i].first);
        y.push_back(v[i].second);
    //    cout<<x[i]<<' '<<y[i]<<endl;
    }
    vector<double>ans;
    ans.push_back(hypot(x[0]-x[1],y[0]-y[1]));
    ans.push_back(hypot(x[0]-x[2],y[0]-y[2]));
    ans.push_back(hypot(x[3]-x[1],y[3]-y[1]));
    ans.push_back(hypot(x[3]-x[2],y[3]-y[2]));
    ans.push_back(hypot(x[0]-x[3],y[0]-y[3]));
  //  cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<' '<<ans[4]<<ans[0]*sqrt(2)<<endl;
    if(ans[0]==ans[1]&&ans[1]==ans[2]&&ans[2]==ans[3]&&abs(ans[4]-ans[0]*sqrt(2))<=1e-9&&ans[0]!=0)return 1;
    return 0;
}
bool checkRec(vector<pair<int,int> >v,bool l)
{
    sort(v.begin(),v.end());
    vector<int>x,y;
    for(int i=0;i<v.size();i++)
    {
        x.push_back(v[i].first);
        y.push_back(v[i].second);
    }
    vector<double>ans;
    ans.push_back(hypot(x[0]-x[1],y[0]-y[1]));
    ans.push_back(hypot(x[0]-x[2],y[0]-y[2]));
    ans.push_back(hypot(x[3]-x[1],y[3]-y[1]));
    ans.push_back(hypot(x[3]-x[2],y[3]-y[2]));
    ans.push_back(hypot(x[0]-x[3],y[0]-y[3]));
    ans.push_back(hypot(x[1]-x[2],y[1]-y[2]));
    if(ans[0]==ans[3]&&ans[1]==ans[2]&&ans[0]&&ans[1]&&abs(ans[4]-ans[5])<=1e-9)return 1;

    return 0;
}


int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<int,int>arr[10];
    for(int i=0;i<8;i++)cin>>arr[i].first>>arr[i].second;
    for(int i=0;i<8;i++)
        for(int j=i+1;j<8;j++)
            for(int k=j+1;k<8;k++)
                for(int l=k+1;l<8;l++){
                    vector<pair<int,int> > v,vv;
                    for(int c=0;c<8;c++)
                    {
                        if(c==i||c==j||c==k||c==l){
                            v.push_back(arr[c]);
                        }
                        else
                        {
                            vv.push_back(arr[c]);
                        }
                    }
                    if(checkRec(v,0)&&checkSq(vv))
                    {
                        cout<<"YES\n";
                        for(int c=0;c<8;c++)
                        {
                            if(c==i||c==j||c==k||c==l);
                            else cout<<c+1<<' ';
                        }
                        cout<<'\n'<<i+1<<' '<<j+1<<' '<<k+1<<' '<<l+1<<'\n';
                        return 0;
                    }
                }
    cout<<"NO";


    return 0;
}
