/// used Determinant eqn. to get the volume

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int Size=7;

void GetCo(ld D[Size][Size],ld T[Size][Size],int i,int j,int n)
{
    int x=0,y=0;
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {
            if(r!=i&&c!=j)
            {
              //  cout<<x<<' '<<y<<endl;
                T[x][y++]=D[r][c];
                if(y==n-1)
                {
                    y=0;
                    x++;
                }
            }
        }
    }
}
ld Dit(ld D[Size][Size],int n)
{
   // cout<<n<<endl;
    if(n==1)return D[0][0];
    ld T[Size][Size];
    int S=1;
    ld ans=0;
    for(int i=0;i<n;i++)
    {
        GetCo(D,T,0,i,n);
        ans+=(S*D[0][i]*Dit(T,n-1));
        S=-S;
    }
    return ans;
}
int main()
{
    // freopen("tshirts.in","r",stdin);
    //freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ld D[Size][Size]={},Di[Size][Size]={};
        cin>>D[0][1]>>D[0][2]>>D[0][3]>>D[1][2]>>D[1][3]>>D[2][3];

        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
            {
                if(j==i)Di[i][j]=0;
                else if(i==4||j==4)Di[i][j]=1;
                else Di[i][j]=D[min(i,j)][max(i,j)]*D[min(i,j)][max(i,j)];
            }
        cout<<fixed<<setprecision(4)<<sqrt((ld)Dit(Di,5)/288)<<'\n';
    }

    return 0;
}

