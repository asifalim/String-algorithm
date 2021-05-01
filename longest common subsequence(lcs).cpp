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
/*int lcs(int idx1,int idx2)
{
    if(idx1==N or idx2==M)return 0;
    if(~dp[idx1][idx2])return dp[idx1][idx2];
    if(s[idx1]==ss[idx2])return dp[idx1][idx2]=1+lcs(idx1+1,idx2+1);
    return dp[idx1][idx2]=max(lcs(idx1+1,idx2),lcs(idx1,idx2+1));
}
void getlcs(int idx1,int idx2)
{
    if(idx1==N or idx2==M)return;
    if(s[idx1]==ss[idx2])sr+=s[idx1],getlcs(idx1+1,idx2+1);
    else if(dp[idx1+1][idx2]>dp[idx1][idx2+1])getlcs(idx1+1,idx2);
    else getlcs(idx1,idx2+1);
}*/
