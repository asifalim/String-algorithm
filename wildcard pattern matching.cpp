#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*This method can take lot of memory so it would be
    better to use it if the memory limit is higher*/
    int t,n,i,j;
    string s,p;
    int ss,pp;
    cin>>t;
    while(t--)
    {
        cin>>p>>s;
        ss=s.size(),pp=p.size();
        int dp[ss+1][pp+1];
        dp[0][0]=1;
        for(i=1; i<=ss; i++)dp[i][0]=0;
        for(i=1; i<=pp; i++)dp[0][i]=0;
        for(i=1; i<=ss; i++)
        {
            for(j=1; j<=pp; j++)
            {
                if(s[i-1]==p[j-1] or p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    if(dp[i-1][j]==1 || dp[i][j-1]==1 or dp[i-1][j-1])
                        dp[i][j]=1;
                    else dp[i][j]=0;
                }
                else dp[i][j]=0;
            }
        }
        if(dp[ss][pp]==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
