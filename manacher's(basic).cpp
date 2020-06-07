#include<bits/stdc++.h>
using namespace std;
//int p[10000];
string createnew(const string &s)
{
    string ss;
    ss+='@';
    for(int i=0; i<s.size(); i++)
    {
        ss+='#'+s.substr(i,1);
    }
    ss+="#$";
    return ss;
}
string asif(const string &s)
{
    string ss=createnew(s);
    int c=0,r=0,sz=ss.size(),m,i;
    int p[sz+2];
    memset(p,0,sizeof(p));
    for(i=1; i<ss.size()-1; i++)
    {
        m=c-(i-c);
        if(i<r)
            p[i]=min(r-i,p[m]);
        while(ss[i+1+p[i]]==ss[i-1-p[i]])
            p[i]++;
        if(i+p[i]>r)
        {
            c=i;
            r=i+p[i];
        }
    }
    int mx=0,cc=0,cn=0;
    for(i=1; i<sz-1; i++)
    {
        if(p[i]>mx)
        {
            mx=p[i];
            cc=i;
        }
    }
    int mm=(cc-1-mx)/2;
    cout<<mx<<endl;
    return s.substr(mm,mx);
}
int main()
{
    int t,n,i,j,cn=0;
    string s,ss;
    cin>>t>>s;
    ss=asif(s);
    cout<<ss<<endl;
    return 0;
}
