#include <iostream>
using namespace std;
 
int main()
{
    int A[] = { 3,1, 3,5,4,6,7,10,9 };
    int n = sizeof(A) / sizeof(A[0]);
    
    int temp[n];
    for (int i = 0; i < n; ++i)
    {
        temp[i] =0;
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n-1;j++)
      {
          if(A[j]>A[j+1])
          {
              int temp;
              temp = A[j];
              A[j] = A[j+1];
              A[j+1] = temp;
          }
      }
    }
    for (int z=0;z<n;z++)
    {
            if(A[z]==A[z+1])
            {
                cout<<"\nRepeated is"<<A[z];
            }
    }
    for (int i = 1; i <= n; i++)
    {
        if((A[i-1]) == i)
             temp[i-1] = 1;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if(temp[i] == 0)
        {
            cout<<"\nMissing is"<<i+1;
        }
             
    }
     return 0;
}