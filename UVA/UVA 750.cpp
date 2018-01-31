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
int arr[10][10]={};
vector<vector<pair<int,int> > > vec,vec2;
void rec(int i,int j ,vector<pair<int,int> > v)
{
    if(v.size()==8)
    {
        vec.push_back(v);

    }
    if(i==9)return;
    if(arr[i][j]==0)
    {
        for(int k=1;k<=8;k++)
            arr[k][j]++;
        for(int l=1;l<=8;l++)
            arr[i][l]++;
        arr[i][j]--;

        for(int k=1;k<=8;k++)
        {
            if(i+k<=8&&j+k<=8)
                arr[i+k][k+j]++;
            if(i-k>=1&&j-k>=1)
                arr[i-k][j-k]++;
            if(i+k<=8&&j-k>=1)
                arr[i+k][j-k]++;
            if(i-k>=1&&j+k<=8)
                arr[i-k][j+k]++;
        }


        v.push_back({i,j});
        if(j==8)
        rec(i+1,1,v);
        else
            rec(i,j+1,v);
        v.pop_back();
        for(int k=1;k<=8;k++)
            arr[k][j]--;
        for(int l=1;l<=8;l++)
            arr[i][l]--;
        arr[i][j]++;
        for(int k=1;k<=8;k++)
        {
            if(i+k<=8&&j+k<=8)
                arr[i+k][k+j]--;
            if(i-k>=1&&j-k>=1)
                arr[i-k][j-k]--;
            if(i+k<=8&&j-k>=1)
                arr[i+k][j-k]--;
            if(i-k>=1&&j+k<=8)
                arr[i-k][j+k]--;
        }

    }
    if(j==8)
    rec(i+1,1,v);
    else
        rec(i,j+1,v);
}

int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int,int> >v;
    rec(1,1,v);
    vec2.push_back(vec[0]);
    for(int j=0;j<vec.size();j++)
    {
        for(int i=0;i<8;i++)
        {
            if(vec2[vec2.size()-1][i]!=vec[j][i])
            {
                vec2.push_back(vec[j]);
                break;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int x,y,j;
        cin>>x>>y;
        cout<<"SOLN       COLUMN\n";
        cout<<" #      ";
        for(int i=1;i<=7;i++)
            cout<<i<<' ';
        cout<<8<<"\n\n";
        int s=1;
        swap(x,y);
        for(j=0;j<vec2.size();j++)
        {
            if(vec2[j][x-1].first==x&&vec2[j][x-1].second==y){
            if(s<=9)
            cout<<' '<<s++<<"      ";
            else
                cout<<s++<<"      ";
            for(int i=0;i<7;i++)
                cout<<vec2[j][i].second<<' ';
            cout<<vec2[j][7].second<<'\n';
            }
        }
        if(t)cout<<'\n';
    }
    return 0;
}
