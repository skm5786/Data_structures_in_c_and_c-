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
           return;
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
int deletebegin(node **list){
    if (*list==NULL) {
        cout<<"empty list\n";
        return -1;
    }
    int x;
    node* q=*list;
    *list=q->next;
    x=q->info;
    free(q);
    return x;
}
void insertpostion(node*list,int position,int x){
    node* q=list;
    int p=1;
    while (q->next!=NULL) {
        p++;
        q=q->next;
    }
    if (p<position) {
        cout<<"linked list limit exceeded\n"<<endl;
        return;
    }
     q=list;
    for(int i=0;i<position-2;i++){
        q=q->next;
    }
    insertafter(q, x);
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
int deleteafter(node* p){
    int x;
    if (p==NULL||p->next==NULL) {
        cout<<"void deletion"<<endl;
        return -1;
    }
    node* q=p->next;
        x=q->info;
        p->next=q->next;
        free(q);
    return x;
 }
int deleteend(node*list){
    int x;
    if (list==NULL) {
        cout<<"empty list\n";
        return -1;
    }
        node*q=list;
        while (q->next->next!=NULL) {
            q=q->next;
        }
    x=q->next->info;
    node*p=q->next;
    q->next=NULL;
    free(p);
    return x;
}
int deletepostion(node*list,int position){
    node* q=list;
    int x;
    int p=1;
    while (q->next!=NULL) {
        p++;
        q=q->next;
    }
    if (p<position) {
        cout<<"linked list limit exceeded\n"<<endl;
        return -1;
    }
    if (position==1) {
        x=deletebegin(&list);
        return x;
    }
     q=list;
    for(int i=0;i<position-2;i++){
        q=q->next;
    }
    x=q->next->info;
    deleteafter(q);
    return x;
}
int main(){
    node* list=NULL;
    int x=0,n,m;
    while (1) {
        cout<<"enter 1 to insert an element at end"<<endl;
        cout<<"enter 2 to insert an element at beginning"<<endl;
        cout<<"enter 3 to delete an element at end"<<endl;
        cout<<"enter 4 to delete an element at beginning"<<endl;
        cout<<"enter 5 to insert an element at given position"<<endl;
        cout<<"enter 6 to delete an element at given position"<<endl;
        cout<<"enter 7 to print list"<<endl;
        cout<<"enter 8 to exit"<<endl;
        cin>>x;
        switch (x) {
            case 1:
                cout<<"enter your element  ";
                cin>>n;
                insertend(&list, n);
                break;
            case 2:
                cout<<"enter your element  ";
                cin>>n;
                insertbeg(&list, n);
                break;
            case 3:
                cout<<"deleted element is: "<<deleteend(list)<<endl;
                break;
            case 4:
                cout<<"deleted element is: "<<deletebegin(&list)<<endl;
                break;
            case 5:
                cout<<"enter the position\n";
                cin>>m;
                cout<<"enter your element  ";
                cin>>n;
                insertpostion(list, m, n);
                break;
            case 6:
                cout<<"enter the position\n";
                cin>>m;
                cout<<"deleted element is: "<<deletepostion(list,m)<<endl;
                break;
            case 7:
                printlist(list);
                break;
            case 8:
                exit(1);
                break;
            default:
                cout<<"invalid value entered"<<endl;
                break;
        }
    }
    return 0;
}
