#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int idd=0,j;
string arr[100200]={};
struct trie
{
    unordered_map <string,trie*>child;
    vector<trie*>ch;
    unordered_map <string,int>frq;
    int is,mx;
    int id;
    trie(int i)
    {
        is=mx=0;
        id=i;
    }
    void insert(trie *t, string st,string ans)
    {
        int c=1,i=0;
        stringstream ss(st);
        string s;
        while(i<j)
        {
            s=arr[i++];
            if(t->child.find(s) == t->child.end())
            {
                t->child[s] = new trie(idd++);
                t->ch.push_back(t->child[s]);
            }
            t->is++;
            t->mx=max(t->mx,++t->frq[ans]);
            t = t->child[s];
        }
    }
};
trie* root=new trie(idd++);

double dp[100010][102];
double mem(int i,int t,trie* node)
{
    if(t==0)return 0;
    double &ret=dp[i][t];
    if(ret!=-1)return ret;
    ret=0;
    for(auto it : node->ch)
        ret+=(mem(it->id,t-1,it)*it->is*1.0/node->is);
    return ret=max(ret,mem(root->id,t-1,root)+(node->mx*1.0/node->is));
}


int main()
{
//    ios::sync_with_stdio(false);
  //  cin.tie(0);

    int t,n;
    string s,a;
    cin>>t>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        j=0;
        getline(cin,s);
        stringstream ss(s);
        while(ss >> a)
            arr[j]=a,j++;
        root->insert(root,s,a);
    }
    for(int i=0;i<=100001;i++)
        for(int j=0;j<=105;j++)
            dp[i][j]=-1;
    cout<<fixed<<setprecision(8)<<mem(root->id,t,root);

    return 0;
}
