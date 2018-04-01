#include<bits/stdc++.h>

#define KhaledAshraf ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define modulo lln(1e9+7)
#define PI acos(-1.0)
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))

typedef long long lln;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
using namespace std;

int x[100002]={};
const int ss=26;

struct trie
{
    //trie *child[ss];
    unordered_map <char,trie*>child;
    int is;
    trie()
    {
      //  memset(child,0,sizeof(child));
        is=0;
    }
    void insert(trie *t, string s)
    {
        int j=0;
        for(int i = s.size()-1; i >=0 ; i--,j++)
        {
            if(t->child.count(s[i]) == 0)
            {
                 t->child[ s[i] ] = new trie;
            }
            t->is++ ;
            x[j]=max(x[j],t->is); /* new word */
            t = t->child[ s[i] ];
        }
    }
    void rem(trie *t, string s)
    {
        int j=0;
        for(int i = s.size()-1; i >=0 ; i--,j++)
        {
            t->is=0 ;
            x[j]=0; /* new word */
            t = t->child[ s[i] ];
        }
    }/*
    void insert (string str,int i)
    {
        if(-1==i)is++ ;
        else{
               // cout<<*str;
        int in=(str[i])-'a';
        if(child[in]==0)
            child[in]=new trie();
        child[in]->insert(str,i-1);
        is++;
        }
    }
    void rem (string str,int i)
    {
        if(-1==i)is-- ;
        else{
               // cout<<*str;
        int in=(str[i])-'a';

        child[in]->rem(str,i-1);
        is--;
        }
    }*/

    void get(string str,int i,int j)
    {
      //  cout<<a<<' '<<b<<endl;
        if(i==-1);
        else{
            x[j]=max(x[j],(is));
            is=0;
            int in=str[i]-'a';
            if(child.find(in)==child.end())return ;
            child[in]->get(str,i-1,j+1);
        }
    }

};

int main()
{
  //  KhaledAshraf
    int T;
    scanf("%d",&T);
//    cin>>T;
    string S[int(1e4+5)];
        trie tr;
    while(T--){
        int N,Q;
        scanf("%d %d",&N,&Q);
//        cin>>N>>Q;
        for(int i=0;i<N;i++){
            cin>>S[i];
            tr.insert(&tr,S[i]);
        }

        while(Q--){
            int X;
            cin>>X;
            printf("%d\n",x[X]);
        }
        for(int i=0;i<N;i++){
            tr.rem(&tr,S[i]);
        }
       // for(int i=0;i<100001;i++)x[i]=0;
    }

    return 0;
}
