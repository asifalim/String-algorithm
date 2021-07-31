#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+3;
int nxt[mxN];
void prefix_function(string s)
{
    int len=s.size(),k=-1,i=0;
    nxt[0]=-1;
    while(i<len)
    {
        if(k==-1 or s[i]==s[k])nxt[++i]=++k;
        else k=nxt[k];
    }
}
int main()
{
    int t,n,i,j,k=1;
    cin>>t;
    while(t--)
    {
        string s,ss,sss;
        cin>>s>>ss;
        int cn=0;n=ss.size();
        sss+=(ss+"$"+s);
        prefix_function(sss);
        for(i=0; i<=sss.size(); i++)
        {
            if(nxt[i]==n)
            {
                cn++;
                cout<<i-2*n-1<<" ";//for finding index
            }
        }
        cout<<"Case "<<k++<<": "<<cn<<endl;
    }
    return 0;
}
