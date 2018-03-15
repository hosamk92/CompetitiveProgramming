///try to add 1 person each time if i can't , i make team of 3 
///if at a time i the number of people is -ve then it's impossible
/// otherwise we have the answer when we have n people in our vector
#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;
const double PI = acos(-1.0);

const double EPS = 1e-9;

typedef complex<double> point;

#define X real()
#define Y imag()
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define normalize(a)            (a)/length(a)

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

vector<vector<int> > v(200200);
vector<int>ans;
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x,s=0,a;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cin>>a;
        v[a].push_back(i);
    }
    while(1)
    {
        if(x==0)break;
        if(s<0)
        {
            cout<<"Impossible";
            return 0;
        }
        if(v[s].empty()){
                s-=3;
                continue;
        }
        ans.push_back(v[s][v[s].size()-1]);
        v[s].pop_back();
        s++;
        x--;
    }
    cout<<"Possible\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<' ';

    return 0;
}
