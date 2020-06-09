#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*This method can take lot of memory so it would be
    better to use it if the memory limit is higher*/
    //time complexity O(n)
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        string s,p;
        cin>>s>>p;//string s and pattern p
        int ss,pp;
        ss=s.size();
        pp=p.size();
        int dp[ss+1][pp+1];
        dp[0][0]=1;
        for(i=1; i<=ss; i++)dp[i][0]=0;
        for(i=1; i<=pp; i++)
        {
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-2];
            else dp[0][i]=0;
        }
        for(i=1; i<=ss; i++)
        {
            for(j=1; j<=pp; j++)
            {
                if(s[i-1]==p[j-1] or p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    if(dp[i][j-2]==1)
                        dp[i][j]=1;
                    else if(p[j-2]=='.' or s[i-1]==p[j-2])
                    {
                        if(dp[i-1][j]==1)
                            dp[i][j]=1;
                        else
                            dp[i][j]=0;
                    }
                    else
                        dp[i][j]=0;
                }
                else
                    dp[i][j]=0;
            }
        }
        //for checking dp table
        /*for(i=0; i<=ss; i++)
        {
            for(j=0; j<=pp; j++)
                cout<<dp[i][j]<<" ";
                cout<<endl;
        }*/
        if(dp[ss][pp]==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
