#include<bits/stdc++.h>
using namespace std;
void MakeLPSArray(string pat,int M,int* lps)
{
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
void KMPSearch(string text,string pat)
{
    int N=text.size();
    int M=pat.size();
    int i=0,j=0,c=0;
    int lps[M];
    MakeLPSArray(pat,M,lps);
    while(i<N)
    {
        if(pat[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==M)
        {
            cout<<"pattern found at index: "<<i-j+1<<" ";
            j=lps[j-1];
            c=1;

        }
        else if(i<N && pat[j]!=text[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
    if(c==0)
        cout<<-1;
}
int main()
{
    int t,n,i,j;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s,ss;
        getline(cin,s);
        getline(cin,ss);
        KMPSearch(s,ss);
        cout<<endl;
    }
    return 0;
}
