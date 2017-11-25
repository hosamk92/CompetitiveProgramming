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

    ll x[5]={},ans=0;
    cin>>x[0]>>x[1]>>x[2];
    sort(x,x+3);
    cout<<min( (x[0]+x[1]+x[2])/3,x[0]+x[1]);


    return 0;
}
