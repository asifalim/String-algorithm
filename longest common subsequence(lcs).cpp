#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main()
{
    int t,i,j;
    int b,c,d,e,ans=0;
    string s,ss,st2;
    while(cin>>s>>ss)
    {
        d=s.size();
        e=ss.size();
        for(int i=0; i<d; i++)       //little length
        {
            for(int j=0; j<e; j++)   //large length
            {
                if(s[i]==ss[j])dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        cout<<dp[d][e]<<endl;
        //for printing lcs
        i=d;j=e;
        while(i>0 and j>0)
        {
        if(s[i-1]==ss[j-1])st2=s[i-1]+st2,i--,j--;
        else if(dp[i-1][j]>dp[i][j-1])i--;else j--;
        }
    }
    return 0;
}
