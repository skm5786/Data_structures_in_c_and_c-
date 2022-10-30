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
int main(){
    node* list=NULL;
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
    insertafter(q, 66);
    printlist(list);
    return 0;
}
