/* 
mark all places he can go from each point and go for the next point if not marked inc the answer
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

int arr[1002][1002]={};

void mark(int i,int j)
{
    arr[i][j]=1;
    for(int k=0;k<1001;k++)
    {
        if(arr[k][j]==2)mark(k,j);
        if(arr[i][k]==2)mark(i,k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 //   freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int x,i,j,ans=0,a[300]={},y[300]={};
    map<int,bool>m,my;
    cin>>x;
    for( i=0;i<x;i++)
    {
        cin>>a[i]>>y[i];
        arr[a[i]][y[i]]=2;
    }
    mark(a[0],y[0]);
    for(i=1;i<x;i++)
    {
        if(arr[a[i]][y[i]]==1)continue;
        arr[a[i]][y[i]]=1;
        mark(a[i],y[i]);
        ans++;
    }
    cout<<ans;

    return 0;
}
