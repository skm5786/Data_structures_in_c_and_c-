#include <iostream>
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
   void insertafter(node* p,int x){
       node *q=getnode();
       if (p==NULL) {
           cout<<"void insertion"<<endl;
           exit(1);
       }
       else
       {
           q->info=x;
           q->next=p->next;
           p->next=q;
       }
    }
   void insertbeg(node **list,int x){
        node *p=getnode();
        p->info=x;
        p->next=*list;
        *list=p;
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
int lengthofLL(node * list){
    node* q=list;
    int m=1;
    while (q->next!=NULL) {
        m++;
        q=q->next;
    }
    return m;
}
void inssub(node** l1,int i1,node** l2, int i2,int len){
    int m;
    int ll1=lengthofLL(*l1);
    int ll2=lengthofLL(*l2);
    if (i1>ll1+1) {
        cout<<"error"<<endl;
        return;
    }
    if (i2+len-1>ll2) {
        cout<<"error"<<endl;
        return;
    }
    if (i1<1||i2<1) {
        cout<<"error"<<endl;
        return;
    }
    node*q=*l2;
    node*p=*l1;
    for(int i=0;i<i2;i++){
        q=q->next;
    }
    for(int i=0;i<i1;i++){
        p=p->next;
    }
    for(int i=0;i<len;i++){
        m=q->info;
        q=q->next;
        insertafter(p, m);
        p=p->next;
    }
}
int main(){
    node* list=NULL;
    node* list2=NULL;
    insertbeg(&list,1);
    insertbeg(&list,2);
    insertbeg(&list,3);
    insertbeg(&list,4);
    insertbeg(&list,5);
    insertbeg(&list,6);
    insertbeg(&list,7);
    insertbeg(&list,8);
    insertbeg(&list,9);
    insertbeg(&list,10);
    insertbeg(&list,11);
//    cout<<list->info;
    printlist(list);
    node* q=list;
    for(int i=0;i<5;i++){
        q=q->next;
    }
    insertafter(q, 63);
    printlist(list);
    insertbeg(&list2,11);
    insertbeg(&list2,22);
    insertbeg(&list2,33);
    insertbeg(&list2,44);
    insertbeg(&list2,55);
    insertbeg(&list2,66);
    insertbeg(&list2,77);
    insertbeg(&list2,88);
    insertbeg(&list2,99);
    insertbeg(&list2,100);
    insertbeg(&list2,111);
    printlist(list2);
    inssub(&list, 4, &list2, 5, 3);
    printlist(list);
    printlist(list2);
    return 0;
}
