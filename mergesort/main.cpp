#include <iostream>
using namespace::std;
void merge(int*,int,int,int);
void mergesort(int*,int,int);
int main(){
    int a[]={23,45,67,23,11,35,63,53,52,74,42,85,85,94,15};
    int n=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
void Merge(int *a,int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int b[n1];
    int c[n2];
    int i,j,k;
    for( i=0;i<n1;i++){
        b[i]=a[low+i];
    }
    for( j=0;j<n2;j++){
        c[j]=a[mid+1+j];
    }
    for( i=0,j=0,k=low;(i<n1)&&(j<n2);k++){
        if (b[i]<=c[j]) {
            a[k]=b[i];
            i++;
        }
        else{
            a[k]=c[j];
            j++;
        }
    }
    while (i<n1) {
        a[k]=b[i];
        i++;
        k++;
    }
    while (j<n2) {
        a[k]=c[j];
        j++;
        k++;
    }
}
void mergesort(int *a,int low, int high){
    if (low<high) {
        int mid=(low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}
