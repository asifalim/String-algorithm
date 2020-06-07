#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_function (string Z)
{
    int n = (int) Z.length();
    vector<int> F(n);
    F[0]=0;
    for (int i=1; i<n; ++i)
    {
        int j = F[i-1];
        while (j > 0 && Z[i] != Z[j])
            j = F[j-1];
        if (Z[i] == Z[j])  ++j;
        F[i] = j;
    }
    return F;
}
int main()
{
    int t,n,i,j,k=1;
    cin>>t;
    while(t--)
    {
        string s,ss,sss;
        cin>>s>>ss;
        n=ss.size()*2;
        int cn=0;
        sss+=(ss+"$"+s);
        vector<int>v;
        v=prefix_function(sss);
        //bool f=true;
        for(i=0; i<v.size(); i++)
        {
            if(v[i]==ss.size())
            {
                cn++;
                cout<<i-n<<" ";//for finding index
            }
        }
        cout<<"Case "<<k++<<": "<<cn<<endl;
    }
    return 0;
}
