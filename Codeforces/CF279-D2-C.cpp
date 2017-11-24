/* 
make two arrays 1 for increasing 
the other for decrasing 
and put in every index the number of elements bigger or lower than this element
and use both array to check the problem condtion
*/

#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

double Fib(double x,double z);
string BinDec(ull x);
string StringInt(ll x);
ull StringInt(string x);
ull BinDec (string x);
ull POWMOD (ull x,ull y,ull mod);
ull POWE(long long , long long);

int arr[100200]={},ans[100200]={},ans1[100200]={};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 //   freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    ll x,y,i,j,q1,q,prev,s;
    cin>>x>>y;
    for(i=0;i<x;i++)cin>>arr[i];
    prev=-1e9;
    s=0;
    for(i=x-1;i>=0;i--){
        if(arr[i]>=prev)
        {
            prev=arr[i];
            s++;
        }
        else
        {
            prev=arr[i];
            s=1;
        }
        ans[i]=s;
    }
    prev=1e10;
    s=0;
    for(i=x-1;i>=0;i--){
        if(arr[i]<=prev)
        {
            prev=arr[i];
            s++;
        }
        else
        {
            prev=arr[i];
            s=1;
        }
        ans1[i]=s;
    }
    // ans1 increasing
    // ans decreasing
    for(i=0;i<y;i++)
    {
        cin>>q>>q1;
        q--;q1--;
        if(q1-q<=ans1[q]-1
           ||q1-q<=ans[q]-1
           ||q1-q<=ans1[q]+ans[q+ans1[q]-1]-2 )cout<<"Yes\n";
        else cout<<"No\n";
    }


    return 0;
}
