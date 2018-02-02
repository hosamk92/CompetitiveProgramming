#include <bits/stdc++.h>

using namespace std;


class MessageMess {
public:
	long long dp[100]={};
	long long mem(vector <string> dictionary, string message,int i)
	{
		if(i==message.size())return dp[i]=1;
		if(i>message.size())return 0;
		if(dp[i]!=-1)return dp[i];
		dp[i]=0;

		for(int j=0;j<dictionary.size();j++)
		{
			int c=1;
			for(int k=0;k<dictionary[j].size();k++)
			{
				c=1;
				if(k+i>message.size()||dictionary[j][k]!=message[k+i] ) {
				c=0;
				break;
				}
			}
			if(c)dp[i]+=mem(dictionary,message,i+dictionary[j].size());
		}
		return dp[i];
	}
	string restore(vector <string> dictionary, string message) {
		memset(dp,-1,sizeof dp);
		long long ans=mem(dictionary,message,0);
		if(ans==1)
		{
			string x="";
			for(int i=0;i<message.size();)
			{
				for(int j=0;j<dictionary.size();j++)
				{
					int c=0;
					for(int k=0;k<dictionary[j].size();k++)
					{
						c=1;
						if(k+i>=message.size()||dictionary[j][k]!=message[k+i] ) {
						c=0;
						break;
						}
					}
					if(i+dictionary[j].size()==message.size()&&c)
					{
						x+=dictionary[j];
						i+=dictionary[j].size();
					}
					else if(dp[i+dictionary[j].size()]==1&&c)
					{
						x+=dictionary[j];
						x+=" ";
						i+=dictionary[j].size();
					}
				}
			}
			return x;
		}
		else if(ans==0) return "IMPOSSIBLE!";
		return "AMBIGUOUS!";
	}
};


