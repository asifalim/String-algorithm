#include<bits/stdc++.h>
using namespace std;
#define ll long long int//O(n+l+z) -> n=string_len, l=keyword_len, z=keyword_occurrence
const int N=2e6,M=1002;//N -> query*each_query_keyword_max_len
stack<int>stk;        //M -> num_of_query
int node[N][65],fail[N],end_pos[M],cnt,res[N];
int ch(char c)
{
    if(c>='a' and c<='z')return c-'a';
    else if(c>='A' and c<='Z')return c-'A'+26;
    else if(c>='0' and c<='9')return c-'0'+52;
    else return 62;
}
void insert(string s,int pos)
{
    int now=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=ch(s[i]);
        if(!node[now][c])node[now][c]=++cnt;
        now=node[now][c];
    }
    end_pos[pos]=now;
}
void failure()
{
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<64; i++)
        {
            int now=node[u][i];
            if(!now)continue;
            q.push(now);
            stk.push(now);
            int temp=u;
            while(temp)
            {
                temp=fail[temp];
                if(node[temp][i])
                {
                    fail[now]=node[temp][i];
                    break;
                }
            }
        }
    }
}
void aho_corasick(string s)
{
    int now=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=ch(s[i]);
        while(now and !node[now][c])now=fail[now];
        if(!node[now][c])continue;
        res[node[now][c]]++;
        now=node[now][c];
    }
}
void ans()
{
    while(!stk.empty())
    {
        int u=stk.top();
        stk.pop();
        res[fail[u]]+=res[u];
    }
}
void make_clear()
{
    cnt=0;
    memset(node,0,sizeof(node));
    memset(fail,0,sizeof(fail));
    memset(res,0,sizeof(res));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        make_clear();
        int n,i,m,j;
        string s,ss;
        cin>>ss>>n;
        for(i=0; i<n; i++)cin>>s,insert(s,i);
        failure();
        aho_corasick(ss);
        ans();
        for(i=0; i<n; i++)cout<<(res[end_pos[i]]?"Yes":"No")<<endl;
    }
    return 0;
}
