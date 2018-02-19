/// check for every point if it's in the any of the shapes if rectangle check the if it's in it's bound
/// if circle check if the distance between it and the circle less than the radius 

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


int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i=0;
    char x[100]={};
    double a[100]={},b[100]={},c[100]={},d[100]={},X,Y;
    while(1)
    {
        cin>>x[i];
        if(x[i]=='*')break;
        else if(x[i]=='r')
            cin>>a[i]>>b[i]>>c[i]>>d[i];
        else cin>>a[i]>>b[i]>>c[i];
        i++;
    }
    int k=0;
    while(1)
    {
        cin>>X>>Y;
        k++;
        bool ch=0;
        if(X==9999.9&&Y==9999.9)break;
        for(int j=0;j<i;j++)
        {
            if(x[j]=='r')
            {
                if(X>a[j]&&X<c[j]&&Y<b[j]&&Y>d[j])
                {
                    ch=1;
                    cout<<"Point "<<k<<" is contained in figure "<<j+1<<"\n";
                }
            }
            else
            {
                if((X-a[j])*(X-a[j])+((Y-b[j])*(Y-b[j]))<c[j]*c[j])
                {
                    ch=1;
                    cout<<"Point "<<k<<" is contained in figure "<<j+1<<"\n";
                }
            }
        }
        if(ch==0)
            cout<<"Point "<<k<<" is not contained in any figure\n";
    }


    return 0;
}
