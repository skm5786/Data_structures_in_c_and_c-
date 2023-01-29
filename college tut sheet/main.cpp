//Suppose there are two linked list as follows:
//A: 15,10,5,23,50
//B: 2,7, 18, 34, 70
//Create a third linked list from these such that it should contain data as follows:
//C: 15,2,10,7,5,18,23,34,50,70
//Create two single linked list. Add only common elements in both list to third list.
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
void printlist(node *list){
    node *p=list;
    while (p!=NULL) {
        cout<<p->info<<" ";
        p=p->next;
    }
    cout<<endl;
    free(p);
}
void insertbeg(node **list,int x){
     node *p=getnode();
     p->info=x;
     p->next=*list;
     *list=p;
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
void swap(node *a,node *b){
    int temp=a->info;
    a->info=b->info;
    b->info=temp;
}
void bubblesort(node * start){
    int swapped;
        node *ptr;
        if (start == NULL)
            return;
      
        do            //loop for number of passes
        {
            swapped = 0;
            ptr = start;
      
            while (ptr->next != NULL)    //loop for swapping
            {
                if (ptr->info > ptr->next->info)
                {
                    swap(ptr, ptr->next);
                    swapped = 1;
                }
                ptr = ptr->next;
            }
        }
        while (swapped);
    }
void addatevenpos(node *list){
    int a=0;
    cout<<"number you want to add\n";
    cin>>a;
    node *p=list;
    for(int i=0;p!=NULL;i++){
        if (i%2!=0) {
            p->info=p->info+a;
        }
        p=p->next;
    }
    free(p);
}
node *commonlist(node *llista,node*llistb){
    node *p=llista;
    node *q=llistb;
    node *llistc = nullptr;
    for(int i=0;q!=NULL;i++,p=p->next,q=q->next){
        insertend(&llistc, p->info);
        insertend(&llistc, q->info);
    }
    return llistc;
}
int main()
{
    int lista[]={15,10,5,23,50};
    int listb[]={2,7,18,34,70};
    node *llista = nullptr;
    node *llistb = nullptr;
    for(int i=4;i>=0;i--){
        insertbeg(&llista, lista[i]);
        insertbeg(&llistb, listb[i]);
    }
    node *llistc=commonlist(llista,llistb);
    printlist(llista);
    printlist(llistb);
    printlist(llistc);
    bubblesort(llistc);
    printlist(llistc);
    addatevenpos(llistc);
    printlist(llistc);
    return 0;
}

