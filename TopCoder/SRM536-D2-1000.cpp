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
    double x;
    double rec(int i,vector<int>v,double k,double s,int r)
    {
        double ans=-1e8;;
     //   cout<<s<<' '<<k<<'\n';
        if(v.size()==i&&k>=x)return s;
        if(v.size()==i)return -1e8;
        if(k==x&&r)
        {
            ans=rec(i+1,v,2,(s+v[i])/2,r+1);
            if(ans!=-1e8)return ans;
        }
        if(k>=x&&r==0)
        {
            ans=rec(i+1,v,2,(s+v[i])/2,r+1);
            if(ans!=-1e8)return ans;
            ans=rec(i+1,v,k+1,((s*k)+v[i])/(k+1),r);
            if(ans!=-1e8)return ans;
        }
        if(k<x)
        ans=rec(i+1,v,k+1,((s*k)+v[i])/(k+1),r);

        return ans;
    }
	double findMaximum(vector <int> v, int k) {
		sort (v.begin(),v.end());
		x=k;
		return rec(1,v,1,v[0],0);
	}
};
