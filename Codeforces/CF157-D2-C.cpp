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

string a,b;
int dp[2002][2002],maxi=0;

int mem(int i,int j)
{
//    cout<<i<<' '<<j<<' '<<maxi<<endl;
    if(i>=a.size()||j>=b.size())return 0;
    int &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=0;
    if(a[i]==b[j])ret=max(ret,mem(i+1,j+1)+1);
    else
        ret=max(ret,mem(i+1,j+1));
    maxi=max(maxi,mem(i+1,j));
    maxi=max(maxi,mem(i,j+1));

    maxi=max(ret,maxi);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 //   freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    cin>>a>>b;
    memset(dp,-1,sizeof dp);
    mem(0,0);
    cout<<b.size()-maxi;

    return 0;
}
