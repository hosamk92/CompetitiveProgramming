/// making range of min and max value for each cube in X,Y,Z 
/// and getting the intersection the range which fit in all cubes 
/// print the the volume = (MaxX-MinX)*(MaxY-MinY)*(MaxZ-MinZ)

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;


int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    while(cin>>x)
    {
        if(x==0)break;
        int a,b,c,d,A,B,C,D,ch=1,Da,Db,Dc;
        cin>>a>>b>>c>>d;
        int da=a+d,db=b+d,dc=c+d;
        for(int i=1;i<x;i++)
        {
            cin>>A>>B>>C>>D;
            Da=A+D; Db=B+D; Dc=C+D;
            if(A>da||B>db||C>dc||a>Da||b>Db||c>Dc)ch=0;

            if(a<A)
                a=A;
            if(b<B)
                b=B;
            if(c<C)
                c=C;

            da=min(da,Da);
            db=min(db,Db);
            dc=min(dc,Dc);
        }
             //   cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';

        if(ch==0)cout<<0<<'\n';
        else
        cout<<(da-a)*(db-b)*(dc-c)<<'\n';
    }


    return 0;
}

