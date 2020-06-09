#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j;
    int b,c,d,e;
    string s,ss="",sss="";
    cin>>s;                       //also can used for two string when none of them are reversed
    for(i=s.size()-1; i>=0; i--)ss+=s[i];
    d=s.size();
    e=ss.size();
    int dp[d+1][d+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<d; i++)       //little length
    {
        for(int j=0; j<e; j++)   //large length
        {
            if(s[i]==ss[j])
            {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else
            {
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    //cout<<dp[d][e];     for finding lps length
    i=d,j=d;
    while(i>0 and j>0)
    {
        if(s[i-1]==ss[j-1])
        {
            sss=s[i-1]+sss;
            i--;
            j--;

        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else j--;
    }
    cout<<sss<<endl;
    return 0;
}

