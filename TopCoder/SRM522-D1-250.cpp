#include <vector>
#include <bits/stdc++.h>
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


class RowAndCoins {
public:
	string st;
	int x;
	short dp[(1<<15)][3];
	short mem(int msk,int k)
	{
		int A=0,B=0;
		for(int i=0;i<x;i++)
        {
            if((msk&(1<<i))==0)
            {
                if(st[i]=='A')A=1;
                else B=1;
            }
        }
        if(A&&!B)return 1;
        else if(!A&&B)return 0;
        else if(!A&&!B)return k;
        int nmsk=(1<<15)-1;
        short &ret=dp[msk][k];
        if(ret!=-1)return ret;
        ret=!k;
        for(int i=0;i<x;i++)
        {
            int l=i;
            for(int j=i;j<x;j++,l++)
            {
                if((msk&(1<<j))==0)
                {
                    msk=(msk|(1<<j));
                    if(k)
                    ret=max(ret,mem(msk,!k));
                    else
                    ret=min(ret,mem(msk,!k));
                }
            }
            for(int j=i;j<l;j++)
            {
                msk=(msk&(nmsk^(1<<j)));
            }
        }
        return ret;
	}
	string getWinner(string cells) {
		memset(dp,-1,sizeof dp);
		st=cells;
		x=cells.size();
		short ans=mem(0,1);
		if(ans)return "Alice";
		return "Bob";
	}
};
