#include<iostream>
using namespace std;
 
int Kadane(int a[], int size)
{
   int max_so_far = 0;
   int curr_max = 0;
 
   for (int i = 0; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
 
int main()
{
   int a[] =  {-2, -3, 4, -1, -1, 5, -4, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = Kadane(a, n);
   cout << "Maximum contiguous sum is " << max_sum;
   return 0;
}