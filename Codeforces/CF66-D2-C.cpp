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
 //   ios::sync_with_stdio(false);
   // cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    string x,y,z;
    vector<string>vec[200];
    int i,j,ans=0,k=0,maxi=0;
    map<string,map<string,bool> >m1;
    map<string,int>m,mm;

    while(cin>>x)
    {

        z="";
        y="";
        for(i=3;i<x.size();i++)
        {
            if(x[i]==92)
            {
                y+=z;
                y+=x[i];
                vec[k].push_back(z);
                z="";
                continue;
            }
            z+=x[i];
        }
        z=x[0]+x[1]+x[2];
        z+=vec[k][0];
        m[z]++;
        ans=max(ans,m[z]);

        if(m1[z][y]==0)
        {
            y=vec[k][0];
            y+=((char)92);
            for(j=1;j<vec[k].size();j++)
            {
                y+=vec[k][j];
                y+=((char)92);
                if(m1[z][y]==0)
                m1[z][y]=1,mm[z]++,maxi=max(maxi,mm[z]);
            }
        }
        k++;
    }
        cout<<maxi<<' '<<ans<<endl;





    return 0;
}
