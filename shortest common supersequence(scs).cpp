#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int dp[105][105];
int main()
{
    int t,i,j;
    int b,c,d,e,ans=0;
    string s,ss;
    while(cin>>s>>ss)
    {
        d=s.size();
        e=ss.size();
        for(int i=0; i<d; i++)
        {
            for(int j=0; j<e; j++)
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
        int i = d;
        int j = e;
        string result = "";
        while(i>0 && j>0)
        {
            if(s[i-1]==ss[j-1])
            {
                result = s[i-1]+result;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                result = s[i-1]+result;
                i--;
            }
            else
            {
                result = ss[j-1]+result;
                j--;
            }
        }
        while(i>0)
        {
            result = s[i-1]+result;
            i--;
        }
        while(j>0)
        {
            result = ss[j-1]+result;
            j--;
        }
        cout<<result<<endl;
    }
    return 0;
}

