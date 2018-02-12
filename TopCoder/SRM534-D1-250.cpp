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
#include <bits/stdc++.h>


using namespace std;


class EllysCheckers {
public:
	
	int dp[(1<<21)-1][3],x=0;
	int mem(int msk,int k)
	{
		if((msk&(1<<(x-1))))msk=(msk^(1<<(x-1)));
		if(msk==0)return k;
		int &ret=dp[msk][k];
		if(ret!=-1)return ret;
		ret=!k;
		int nmsk=(1<<21)-1,t;
		for(int i=0;i<x;i++)
        {	
        	if((msk&(1<<i))&&
        		!(msk&(1<<(i+1))))
        	{
        		t=(nmsk^(1<<i));
        		if(k)ret=max(ret,mem(((msk&t)^(1<<(i+1))),!k));
        		else ret=min(ret,mem(((msk&t)^(1<<(i+1))),!k));
        	}
        }
        for(int i=0;i<x-3;i++)
        {	
        	if( (msk&(1<<i))&&
        		(msk&(1<<(i+1)))&&
        		(msk&(1<<(i+2)))&&
        		!(msk&(1<<(i+3)))
        		)
        	{
        		t=(nmsk^(1<<i));
        		if(k)ret=max(ret,mem(((msk&t)^(1<<(i+3))),!k));
        		else ret=min(ret,mem(((msk&t)^(1<<(i+3))),!k));
        	}
        }
        return ret;
	}
	string getWinner(string s) {
		int msk=0;
		x=s.size();
		memset(dp,-1,sizeof dp);
		for(int i=0;i<s.size()-1;i++)
		{
			if(s[i]=='o')msk+=(1<<i);
		}
		bool ans=mem(msk,0);
		if(ans)return "YES";
		return "NO";
	}
};

