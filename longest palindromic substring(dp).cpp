#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,k,mx=1;
        string s;
        cin>>s;
        n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)dp[i][i]=1;
        for(i=0;i<n-1;i++)if(s[i]==s[i+1])dp[i][i+1]=1,mx=2;
        for(i=2; i<n; i++)
        {
            for(j=0; j<n-i; j++)
            {
                k=i+j;
                if(s[j]==s[k] and dp[j+1][k-1])dp[j][k]=1,mx=max(mx,i+1);
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
