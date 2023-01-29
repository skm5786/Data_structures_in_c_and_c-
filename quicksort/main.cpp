#include <iostream>
using namespace::std;
int position(int*,int,int);
void quicksort(int*,int,int);
void Swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(int *a,int start,int end){
    if (start<end) {
        int k=position(a, start, end);
        quicksort(a, start, k-1);
        quicksort(a, k+1, end);
    }
}
int position(int*a,int start,int end){   //retutn the position of pivot element
    int pivot=a[start];
    int i=start;
    int j=end+1;
    while (i<j) {
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if (i<j) {
            Swap(a+i,a+j);
        }
    }
    Swap(a+start, a+j);
    return j;
}

int main(){
    int a[]={23,45,67,23,11,35,63,53,52,74,42,85,94,15};
    int n=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
