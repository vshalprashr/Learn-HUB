//equal sum
#include<iostream>
using namespace std;
int t[5][10]={-1};

bool subset(int arr[],int sum,int n)
{
    if(n==0)
        return false;
    else if(sum == 0)
        return true;

    if(t[n][sum] != -1)
        return t[n][sum];

    if(arr[n-1]<=sum)
        return t[n][sum] = (subset(arr,sum-arr[n-1],n-1) || subset(arr,sum,n-1));
    else
        return t[n][sum] = subset(arr,sum,n-1);
}

int main()
{
    int arr[]={4,5,6,3};
    int sum =0;
    for(int i=0;i<4;i++)
        sum+=arr[i];

    cout<<subset(arr,sum/2,4);

}
