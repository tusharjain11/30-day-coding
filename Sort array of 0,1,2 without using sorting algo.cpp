#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout<<"Enter the length of array";
    cin>>n;
    int A[n];
    cout <<"Enter array";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int xcount=0, ycount=0, zcount=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
        {xcount++;}
        else if(A[i]==1)
        {ycount++;}
        else if(A[i]==2)
        {zcount++;}
        else
        {cout<<"Invalid values entered";}
    }
    int j=0;
    while(xcount)
    {
        A[j]=0;
        j++;
        xcount--;
    }
    while(ycount)
    {
        A[j]=1;
        j++;
        ycount--;
    }
    while(zcount)
    {
        A[j]=2;
        j++;
        zcount--;
    }
    cout<<"Sorted array is";
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
    }
    return 0;
}