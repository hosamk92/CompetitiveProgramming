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

    double x[7]={},y[7]={},i=0;
    while(cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3])
    {
        if(x[0]==x[2]&&y[0]==y[2])swap(x[0],x[1]),swap(y[0],y[1]);
        if(x[0]==x[3]&&y[0]==y[3])swap(x[0],x[1]),swap(y[0],y[1]),
            swap(x[2],x[3]),swap(y[2],y[3]);
        if(x[1]==x[3]&&y[1]==y[3])swap(x[3],x[2]),swap(y[2],y[3]);
        
        cout<<fixed<<setprecision(3)<<x[3]-(x[1]-x[0])<<' '<<y[3]-(y[1]-y[0])<<'\n';
    }



    return 0;
}
