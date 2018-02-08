#include <bits/stdc++.h>
#include <fstream>
#include <cfloat>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const double PI = acos(-1.0);

const double EPS = 1e-9;

typedef complex<float> point;


#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

ll fast_pow(ll a,ll b)
{
	if(b==0)
		return 1ll;
	ll ans=1;
	if(b%2)
		return ans=(fast_pow(a,b-1)*a);
	ans=(fast_pow(a,b/2));
	return ((ans*ans));
}
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int main()
{
   // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k=1;
    cin>>k;
    while(k--)
    {
        vector<pair<int,pair<int,int> > > v;
        int a,b,c,x,y;
        subset subsets[200]={};
        cin>>x>>y;
        for(int i=0;i<y;i++)
        {
            cin>>a>>b>>c;
            v.push_back({c,{a,b}});
        }
        sort(v.begin(),v.end());
        for (int v = 0; v <= x; ++v)
        {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        int ans=0;
        vector<int>ch;
        for(int i=0;i<y;i++)
        {
            a=find(subsets,v[i].second.first);
            b=find(subsets,v[i].second.second);
            if(a!=b)
            {
                ch.push_back(i);
                ans+=v[i].first;
                Union(subsets,a,b);
            }
        }
        int maxi=1e8;
        for(int j=0;j<ch.size();j++)
        {
            for (int v = 0; v <= x; ++v)
            {
                subsets[v].parent = v;
                subsets[v].rank = 0;
            }
            int ans=0;
            for(int i=0;i<y;i++)
            {
                if(ch[j]==i)continue;
                a=find(subsets,v[i].second.first);
                b=find(subsets,v[i].second.second);
                if(a!=b)
                {
                    ans+=v[i].first;
                    Union(subsets,a,b);
                }
            }
            if(ans<maxi)
            {
                for(int i=1;i<x;i++)
                {
                    if(find(subsets,i+1)!=find(subsets,i))
                    {
                        ans=maxi;
                        break;
                    }
                }
                maxi=ans;
            }

        }
        cout<<ans<<' '<<maxi<<'\n';

    }

    return 0;
}
