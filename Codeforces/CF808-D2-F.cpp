#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
const int INF = 2000000000;
struct Edge
{
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index) :
			from(from), to(to), cap(cap), flow(flow), index(index)
	{
	}
};
struct Dinic
{
	int N;
	vector<vector<Edge> > G;
	vector<Edge *> dad;
	vector<int> Q;
	Dinic(int N) :
			N(N), G(N), dad(N), Q(N)
	{
	}
	void AddEdge(int from, int to, int cap)
	{
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to)
			G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	long long BlockingFlow(int s, int t)
	{
		fill(dad.begin(), dad.end(), (Edge *) NULL);
		dad[s] = &G[0][0] - 1;

		int head = 0, tail = 0;
		Q[tail++] = s;
		while (head < tail)
		{
			int x = Q[head++];
			for (int i = 0; i < G[x].size(); i++)
			{
				Edge &e = G[x][i];
				if (!dad[e.to] && e.cap - e.flow > 0)
				{
					dad[e.to] = &G[x][i];
					Q[tail++] = e.to;
				}
			}
		}
		if (!dad[t])
			return 0;

		long long totflow = 0;
		for (int i = 0; i < G[t].size(); i++)
		{
			Edge *start = &G[G[t][i].to][G[t][i].index];
			int amt = INF;
			for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
			{
				if (!e)
				{
					amt = 0;
					break;
				}
				amt = min(amt, e->cap - e->flow);
			}
			if (amt == 0)
				continue;
			for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
			{
				e->flow += amt;
				G[e->to][e->index].flow -= amt;
			}
			totflow += amt;
		}
		return totflow;
	}

	long long GetMaxFlow(int s, int t)
	{
		long long totflow = 0;
		while (long long flow = BlockingFlow(s, t))
			totflow += flow;
		return totflow;
	}
};
int x,y,a[200],b[200],c[200];
bool p[300000]={};
bool ch(int lvl)
{
    Dinic din(x+10);
    int sum=0,maxone=0,j=0;
    vector<int>e,o;
    for(int i=0;i<x;i++)
    {
        if(c[i]<=lvl)
        {
            if(b[i]==1)
            {
                if(a[i]>maxone)sum=sum-maxone+a[i],maxone=a[i],j=i;
                continue;
            }
            if(b[i]%2==0)
                din.AddEdge(x+6,i,a[i]),e.push_back(i);
            else
                din.AddEdge(i,x+5,a[i]),o.push_back(i);
            sum+=a[i];
        }
    }
    //cout<<maxone<<' '<<j<<endl;
    if(maxone!=0)
        din.AddEdge(j,x+5,a[j]),o.push_back(j);
    for(int i=0;i<e.size();i++)
        for(int j=0;j<o.size();j++)
        {
            if(p[b[e[i]]+b[o[j]]]==0)din.AddEdge(e[i],o[j],1e8);
        }
    int su=din.GetMaxFlow(x+6,x+5);
    //cout<<sum-su<<' '<<sum<<' '<<su<<endl;
    return (sum-su>=y) ;
}

int bs()
{
    int f=0,l=x,m;
    while(f<=l)
    {
        m=(f+l)/2;
        //cout<<m<<endl;
        if(ch(m))l=m-1;
        else f=m+1;
    }
    if(ch(l))return l;
    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(ll i=2;i<=200000;i++)
    {
        if(p[i]==0)
        {
            for(ll j=i*i;j<=200000;j+=i)
                p[j]=1;
        }
    }
    cin>>x>>y;
    for(int i=0;i<x;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
   // cout<<ch(30)<<endl;
    if(ch(x+1)==0)cout<<-1;
    else
    cout<<bs();



    return 0;
}
