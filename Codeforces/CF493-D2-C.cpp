#include <bits/stdc++.h>
#include <fstream>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

long long arr[200200]={},a[200200]={},arr1[400200]={},m[200200]={},m1[200200]={};
long long m2[200200][2]={},m3[200200][2]={};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int x,i,y;
    cin>>x;
    for(i=0;i<x;i++)
    {
        cin>>arr[i];
        arr1[i]=arr[i];
    }
    cin>>y;
    for(i=0;i<y;i++){
        cin>>a[i];
        arr1[i+x]=a[i];
    }
    sort(arr1,arr1+x+y);
    map <long long ,int> co;
    int j=1;
    for(i=0;i<x+y;i++)
    {
        if(!co[arr1[i]])
        {
            co[arr1[i]]=j;
            j++;
        }
    }
    for(i=0;i<x;i++){
        arr[i]=co[arr[i]];
        m[arr[i]]++;
    }
    for(i=0;i<y;i++){
        a[i]=co[a[i]];
        m1[a[i]]++;
    }
    sort(arr,arr+x);
    sort(a,a+y);

    for(i=1;i<200001;i++)
    {
        m2[i][0]=m2[i-1][0]+m[i];
        m3[i][0]=m3[i-1][0]+m1[i];
    }
    for(i=200001;i>=0;i--)
    {
        m2[i][1]=m2[i+1][1]+m[i];
        m3[i][1]=m3[i+1][1]+m1[i];
    }
    int ans,ans1,dif=-10000000,aa1,aa2;
    for(i=1;i<200001;i++)
    {
        ans=(m2[i-1][0]*2)+(m2[i][1]*3);
        ans1=(m3[i-1][0]*2)+(m3[i][1]*3);
        if(ans-ans1>dif)
        {
            dif=ans-ans1;
            aa1=ans; aa2=ans1;
        }
    }
    cout<<aa1<<':'<<aa2;




    return 0;
}
