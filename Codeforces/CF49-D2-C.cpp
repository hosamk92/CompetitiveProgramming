/* 
	put the last element in first and put the rest of the elements after it sorted in increasing order
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

    int x,i;
    cin>>x;
    if(x==1)cout<<1;
    else{
        cout<<x<<' ';
        for(i=1;i<=x-1;i++)
        {
            cout<<i<<' ';
        }
      //  cout<<1;
    }

    return 0;
}
