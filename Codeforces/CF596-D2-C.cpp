/*
sorting points and then puting them in place with checking that the next point doesn't have higer x and y
*/
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 //   freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    int x,i,a,b,j;
    vector <pair<int,int> > v;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    map<int,vector<int> > m;
    for(i=v.size()-1;i>=0;i--)
    {
        m[v[i].second-v[i].first].push_back(i);
    }
    int c=1,xx,yy,xx1,yy1;
    xx=xx1=yy=yy1=-1;
    vector <int>ans;
    for(i=0;i<x;i++)
    {
        cin>>a;
        while(1){
            if(m[a].size()>=1)
            {
                j=m[a][m[a].size()-1];
                if(v[j].first<=xx&&v[j].second<=yy)
                {
                    m[a].pop_back();
                    continue;
                }
                if(v[j].first<=xx1&&v[j].second<=yy1)
                {
                    m[a].pop_back();
                    continue;
                }
                if(v[j].first==xx&&v[j].second==yy)xx=v[j].first,yy=v[j].second;
                if(v[j].second==yy1&&v[j].first==xx1)xx1=v[j].first,yy1=v[j].second;
                if(v[j].first>xx)xx=v[j].first,yy=v[j].second;
                if(v[j].second>yy1)xx1=v[j].first,yy1=v[j].second;
                ans.push_back(j);
                m[a].pop_back();
            }
            else
                c=0;
            break;
        }
    }
    if(!c)cout<<"NO";
    else
    {
        cout<<"YES\n";
        for(i=0;i<ans.size();i++)
            cout<<v[ans[i]].first<<' '<<v[ans[i]].second<<'\n';
    }


    return 0;
}
