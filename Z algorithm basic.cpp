#include<bits/stdc++.h>
using namespace std;
vector<int>z_algo(string text)
{
    int len=text.size(),l=0,r=0,i;
    vector<int>z(len);
    for(i=1; i<len; i++)
    {
        if(i>r)
        {
            l=r=i;
            while(r<len and text[r]==text[r-l])
                r++;
            z[i]=r-l;
            r--;
        }
        else
        {
            int ind=i-l;
            if(i+z[ind]<=r)
                z[i]=z[ind];
            else
            {
                l=i;
                while(r<len and text[r]==text[r-l])
                    r++;
                z[i]=r-l;
                r--;
            }
        }
    }
    return z;
}
int main()
{
    int t,n,i,j;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string text,pat;
        getline(cin,text);
        getline(cin,pat);
        string total=pat+"$"+text;
        auto z=z_algo(total);
        bool f=true;
        for(i=0; i<z.size(); i++)
        {
            if(z[i]==pat.size())
            {
                cout<<i-pat.size()<<" ";
                f=false;
            }
        }
        if(!f)cout<<endl;
        if(f)cout<<-1<<endl;
    }
    return 0;
}
