/// change the input first from 1 string to vector of strings then get the LCS with dp and print it      ////

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int dp[1001][1001]={};

int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k=1;
    string a,b;
    while(getline(cin,a))
    {
        getline(cin,b);
      //  if(a=="1")break;
        if(k<10)cout<<' ';
        cout<<k++<<". ";
        if(b==""||a=="")
        {
            cout<<"Blank!\n";
            continue;
        }
        for(int i=0;i<a.size();i++)
            if(!isdigit(a[i])&&!isupper(a[i])&&!islower(a[i]))a[i]=' ';
        for(int i=0;i<b.size();i++)
            if(!isdigit(b[i])&&!isupper(b[i])&&!islower(b[i]))b[i]=' ';
        istringstream is(a),iss(b);
        string x;
        vector<string>v,vv;
        while(is>>x) v.push_back(x);
        while(iss>>x) vv.push_back(x);

        for(int i=0;i<=v.size();i++)
            for(int j=0;j<=vv.size();j++)
                dp[i][j]=0;
        for(int i=0;i<v.size();i++)
            for(int j=0;j<vv.size();j++)
            {
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i+1][j]);
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1]);
                if(vv[j]==v[i])dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
            }
        cout<<"Length of longest match: "<<dp[v.size()][vv.size()]<<'\n';
    }

    return 0;
}

