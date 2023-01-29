#include <iostream>
#include <math.h>
using namespace::std;
class node{
public:
    int info;
    node* next;
};
node* getnode(){
    node *p=new node;
    p->next=NULL;
    return p;
}
void printlist(node *list){
    node *p=list;
    while (p!=NULL) {
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
    free(p);
}
void insertafter(node* p,int x){
    node *q=getnode();
    if (p==NULL) {
        cout<<"void insertion"<<endl;
        return;
    }
    else
    {
        q->info=x;
        q->next=p->next;
        p->next=q;
    }
 }
void insertend(node**list,int x){
    if (*list==NULL) {
        node*p=getnode();
        p->info=x;
        *list=p;
        return;
    }
        node*q=*list;
        while (q->next!=NULL) {
            q=q->next;
        }
        insertafter(q, x);
}
int integer_converter(node *list,int n){
    int x;
    int value=0;
    node*p=list;
    while (p!=NULL||n<0) {
        x=p->info;
        value=value+(x*(pow(10, n-1)));
        p=p->next;
        n--;
    }
    return value;
}
int main()
{
    int x,n;
    node* list=NULL;
    cout<<"enter number of elements in linked list "<<endl;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cout<<"enter elements one by one "<<endl;
        cin>>x;
        insertend(&list, x);
    }
    cout<<"your integer is:  ";
    int val=integer_converter(list,n);
    cout<<val<<endl;
    return 0;
}
