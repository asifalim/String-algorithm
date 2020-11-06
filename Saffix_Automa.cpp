#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=5e4+2;            //O(n)complexity
struct node                  //TO understand RUET RAPL YouTube channel
{
    int len,link;
    map<char,int>next;
} aut[N+N+2];
int sz,last;
void make_clear()
{
  for(int i=0;i<2*N;i++)aut[i].next.clear();
  aut[0].len=0;
  aut[0].link=-1;
  sz=last=0;
}
void insert(char c)
{
    int now=++sz,p,q,clone;
    aut[now].len=aut[last].len+1;
    for(p=last; p!=-1 and !aut[p].next.count(c); p=aut[p].link)aut[p].next[c]=now;
    if(p==-1)aut[now].link=0;
    else
    {
        q=aut[p].next[c];
        if(aut[q].len==aut[p].len+1)aut[now].link=q;
        else
        {
            clone=++sz;
            aut[clone].len=aut[p].len+1;
            aut[clone].next=aut[q].next;
            aut[clone].link=aut[q].link;
            for(; p!=-1 and aut[p].next[c]==q; p=aut[p].link)aut[p].next[c]=clone;
            aut[now].link=aut[q].link=clone;
        }
    }
    last=now;
}
void build_sa_automa(string s)
{
    make_clear();
    for(int i=0;i<s.size();i++)insert(s[i]);
}
ll find()
{
    ll to=0;
    for(int i=1;i<=sz;i++)to+=aut[i].len-aut[aut[i].link].len;
    return to;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        string s;
        cin>>s;
        build_sa_automa(s);
        ll ans=find();
        cout<<ans<<endl;
    }
    return 0;
}
