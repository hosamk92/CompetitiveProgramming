//// brute force for the edges of the circle from 0 to 10000 and make
//// check before it to see if there is 2 vetixes with distance greater than th diamter to make it faster


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

    while(1){
        long double my,arr[200]={},arr2[200]={},x[5],y[5]={},A,B,C,D,E,F,S,SS,a,b,c,R[200],PI=3.141592653589793,up,down,angle,xx,cx,cy;
        int n;
        cin>>n;
        if(n==0)return 0;
        for(int i=0;i<n;i++)
            cin>>arr[i]>>arr2[i];
        cin>>my;
        if(2>=n)
        {
            if(n==1)goto sec;
            if(sqrt( ((arr[0]-arr[1])*(arr[0]-arr[1]))+((arr2[0]-arr2[1])*(arr2[0]-arr2[1])))<=2*my )goto sec;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            if(sqrt( ((arr[i]-arr[j])*(arr[i]-arr[j]))+((arr2[i]-arr2[j])*(arr2[i]-arr2[j])))>my*2)
            {
                goto fail;
                break;
            }
        }
        for(int j=0;j<10000;j++)
            for(int jj=0;jj<10000;jj++){
                cx=j;
                cy=jj;
                bool check=1;
                for(int i=0;i<n;i++)
                {
                    if(( ((arr[i]-cx)*(arr[i]-cx))+((arr2[i]-cy)*(arr2[i]-cy)))>my*my)
                    {
                        check=0;
                        break;
                    }
                }
                if(check)
                {
                    goto sec;
                }
            }
        fail:;
        cout<<"There is no way of packing that polygon.\n";
        continue;
        sec:;
        cout<<"The polygon can be packed in the circle.\n";

    }



    return 0;
}
