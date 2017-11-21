#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    long long a,b,x,y,a1,a2,a3;
    cin>>a>>b>>x>>y;
    a3=__gcd(x,y);
    x/=a3;
    y/=a3;

    a1=a/x;
    a2=b/y;
    cout<<(min(a1,a2)*x)<<' '<<(min(a1,a2)*y);

    return 0;
}
