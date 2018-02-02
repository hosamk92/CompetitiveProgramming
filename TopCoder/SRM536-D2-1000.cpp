#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class MergersDivTwo {
public:
    int x;
    double rec(int i,vector<int>v,int k,long double s)
    {
        long double ans=-1e8;;
     //   cout<<s<<' '<<k<<'\n';
        if(v.size()==i&&k>=x)return s;
        if(v.size()==i)return -1e8;

        if(k>=x&&k<x*2)
        {
            ans=max(rec(i+1,v,2,(s+v[i])/2),rec(i+1,v,k+1,((s*k)+v[i])/(k+1)));
        }
        else if(k>=x)
        {
        	 ans=rec(i+1,v,2,(s+v[i])/2);
        }
        if(k<x)
        ans=rec(i+1,v,k+1,((s*k)+v[i])/(k+1));

        return ans;
    }
    double rec1(int i,vector<int>v,int k,long double s)
    {
        long double ans=-1e8;;
     //   cout<<s<<' '<<k<<'\n';
        if(v.size()==i&&k>=x)return s;
        if(v.size()==i)return -1e8;

        if(k>=x&&k<(int)x+(x/2))
        {
            ans=max(rec1(i+1,v,2,(s+v[i])/2),rec1(i+1,v,k+1,((s*k)+v[i])/(k+1)));
        }
        else if(k>=x)
        {
        	 ans=rec1(i+1,v,2,(s+v[i])/2);
        }
        if(k<x)
        ans=rec1(i+1,v,k+1,((s*k)+v[i])/(k+1));

        return ans;
    }
	long double findMaximum(vector <int> v, int k) {
		sort (v.begin(),v.end());
		x=k;
		if(k==2)
        {
            double ans=v[0];
            for(int i=1;i<v.size();i++)
            {
                ans=(ans+v[i])/2;
            }
            return ans;
        }
		if(k<=4)return rec1(0,v,0,0);
		cout<<v.size()<<endl;
		return rec(0,v,0,0);
	}
};

