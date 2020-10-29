/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
static int t[9][9];
using namespace std;


int LCSu(string a,string b,int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0)
            t[i][j] = 0;
        }
    }
    
    for(int i = 1; i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(a[i-1] == b[j-1] && i!=j)
            t[i][j] = t[i-1][j-1] + 1;
            
            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    
    return t[m][n];
}

int main()
{
    string s,a,b;
    
    cin>>s;
    a=s;
    b=s;
    
    int m = a.length();
    int n = b.length();
    
    cout<<LCSu(a,b,m,n);

    return 0;
}
