#include <iostream>
using namespace::std;
void minor(int**,int**,int,int,int);
int determinant(int**,int);
int main(){
    int **arr;
    int n;
    cout<<"enter size of your matrix: ";
    cin>>n;
    arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"enter element: ";
            cin>>arr[i][j];
        }
    }
    int **b;
    b=new int*[n];
    for(int i=0;i<n;i++){
       b[i]=new int[n];
    }
    minor(arr, b, 1,1, n);
    cout<<"minor of a[1][0]is: "<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
void minor(int **a,int **b,int m,int n,int size){
    for(int i=0,k=0;k<size-1;i++){
        if (i!=m) {
            k++;
            for(int j=0,l=0;l<size-1;j++){
                if (i!=m||j!=n) {
                    b[k][l]=a[i][j];
                    l++;
                }
            }}
        }
    }

