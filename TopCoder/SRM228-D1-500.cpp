#include <bits/stdc++.h>

using namespace std;


class BagsOfGold {
public:
	int dp[60][60][3];
	vector <int>arr;
	int mem(int i,int j,int k)
	{
		if(i==j&&k)return arr[i];
		else if(i==j)return -arr[i];
		int &ret=dp[i][j][k];
		if(ret!=-1)return ret;
		ret=-1e8;
		if(k){
			ret=max(ret,arr[i]+mem(i+1,j,!k));
			ret=max(ret,arr[j]+mem(i,j-1,!k));
		}
		else{
			ret=min(mem(i,j-1,!k)-arr[j],mem(i+1,j,!k)-arr[i]);

		}
		return ret;
	}
	int netGain(vector <int> bags) {
		memset(dp,-1,sizeof dp);
		arr.clear();
		for(int i=0;i<bags.size();i++)arr.push_back(bags[i]);
		return mem(0,bags.size()-1,1);
	}
};
