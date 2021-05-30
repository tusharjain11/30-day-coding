#include<bits/stdc++.h>
using namespace std;
#define loop(i,j,n) for(int i=(j);i<((int)n);i++)
int arr[1000][1000]={0};


void merge(int startrow,int endrow,int midrow,int startcolumn,int endcolumn,int midcolumn){
    // row merging 
    loop(r,startrow,endrow+1){
        int n1 = midcolumn - startcolumn + 1;
        int n2 = endcolumn - midcolumn;
        int L[n1], R[n2];
        loop(i,0,n1){
            L[i] = arr[r][startcolumn + i];
        }
        loop(j,0,n2){
            R[j] = arr[r][midcolumn + 1 + j];
        }
        int i = 0;
        int j = 0;
        int k = startcolumn;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[r][k] = L[i];
                i++;
            }
            else {
                arr[r][k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[r][k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[r][k] = R[j];
            j++;
            k++;
        }
    }



    // column merging 
    loop(c,startcolumn,endcolumn+1){
        int n1 = midrow - startrow + 1;
        int n2 = endrow - midrow;
        int L[n1], R[n2];
        loop(i,0,n1){
            L[i] = arr[startrow + i][c];
        }
        loop(j,0,n2){
            R[j] = arr[midrow + 1 + j][c];
        }
        int i = 0;
        int j = 0;
        int k = startrow;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k][c] = L[i];
                i++;
            }
            else {
                arr[k][c] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k][c] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k][c] = R[j];
            j++;
            k++;
        }
    }

}


int calculatemid(int a,int b){
    int c=a+(b-a)/2;
    return c;
}

void mergeSort(int startrow,int endrow,int startcolumn,int endcolumn){
    
    if(startrow>=endrow && startcolumn>=endcolumn){
        return;
    }
    int midrow=calculatemid(startrow,endrow);
    int midcolumn=calculatemid(startcolumn,endcolumn);
    mergeSort(startrow,midrow,startcolumn,midcolumn);
    mergeSort(midrow+1,endrow,startcolumn,midcolumn);
    mergeSort(startrow,midrow,midcolumn+1,endcolumn);
    mergeSort(midrow+1,endrow,midcolumn+1,endcolumn);
    merge(startrow,endrow,midrow,startcolumn,endcolumn,midcolumn);
}


int main(){
    int m,n;
    cin>>m>>n;
    loop(i,0,m){
        loop(j,0,n){
            cin>>arr[i][j];
        }
    }

    mergeSort(0,m-1,0,n-1);

    loop(i,0,m){
        loop(j,0,n){
            cout<<arr[i][j]<<" ";
        }
    }

    return 0;
}
