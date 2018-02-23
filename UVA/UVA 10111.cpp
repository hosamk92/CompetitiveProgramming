/// using idea dp-masks but with 3 values for each postion insted of 2 (0,for empty),(1,for o),(2,for x)
/// then it's just a normal dp-masks problem


#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int dp[3][3][3][3][3][3][3][3][3][3][3][3][3][3][3][3][2];
////// 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17

/* 1  2  3  4
   5  6  7  8
   9  10 11 12
   13 14 15 16

   win index {1,6,11,16} {4,7,10,13}
   horizontal or Vertical
   st {1,2,3,4}  +4
   st {1,5,9,13} +1
*/
int win[16][5]={{0,5,10,15,0},{3,6,9,12,0}}; /// diagonals winning index
int winMoves=10,ans=0;
int mem(vector<int> a,int k)
{
    int &ret=dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]][a[8]][a[9]][a[10]][a[11]][a[12]][a[13]][a[14]][a[15]][k];
    if(ret!=-1)return ret;
    ret=!k;
  /*  cout<<k<<'\n';
    for(int i=0;i<16;i++)
            if((i+1)%4==0)
            cout<<a[i]<<'\n';
            else cout<<a[i]<<' ';
                */
    for(int i=0;i<winMoves;i++)
    {
        int c=1,cc=1;
        for(int j=0;j<4;j++)
        {
            if(a[win[i][j]]!=1)
            {
                c=0;
            }
            if(a[win[i][j]]!=2)
            {
                cc=0;
            }
        }
        if(c)return ret=0;
        if(cc)return ret=1;
    }
    for(int i=0;i<16;i++)
    {
        if(a[i]==0)
        {
            if(k)
            {
                a[i]=2;
                ret=max(ret,mem(a,!k));
          //      cout<<i<<' '<<ret<<'\n';
                if(ret==1){
                    ans=i;
                    a[i]=0;
                    return ret;
                }
                a[i]=0;
            }
            else
            {
                a[i]=1;
                ret=min(ret,mem(a,!k));
               // cout<<i<<' '<<ret<<" o\n";
                if(ret==0){
                a[i]=0;
                    return ret;
                }
                a[i]=0;
            }
        }
    }
    return ret;
}

int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int j=2;
    /// horizantal and virtical winning index
    for(int i=0;i<4;i++)
    {
        for(int k=4*i,l=0;l<4;k++,l++)
        win[j][l]=k;
        j++;
    }
    for(int i=0;i<4;i++)
    {
        for(int k=i,l=0;l<4;k+=4,l++)
        win[j][l]=k;
        j++;
    }

    char x;
    memset(dp,-1,sizeof dp);

    while(cin>>x)
    {
        if(x=='$')break;
        vector<int> a(17,0);
        char y;
        for(int i=0;i<16;i++)
        {
            cin>>y;
            if(y=='o')
            a[i]=1;
            if(y=='x')
            a[i]=2;
        }

        int an=mem(a,1);
        if(an==1)cout<<"("<<ans/4<<','<<ans%4<<")\n";
        else cout<<"#####\n";

    }


    return 0;
}

