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
                                                  //Rcursion form with memorization
/*int rec(int idx1,int idx2)
{
   if(idx1<0 or idx2<0)return 0;
   if(~dp[idx1][idx2])return dp[idx1][idx2];
   if(s[idx1]==ss[idx2])return dp[idx1][idx2]=1+rec(idx1-1,idx2-1);
   return dp[idx1][idx2]=max(rec(idx1,idx2-1),rec(idx1-1,idx2));
}
cout<<rec(s.size()-1,ss.size()-1)<<endl;*/
