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
int main()
{
    int lista[]={1,2,3,4,5,6,7,8};
    int listb[]={2,45,9,6,72,5,4,1};
    node *llista = nullptr;
    node *llistb = nullptr;
    node *llistc = nullptr;
    for(int i=7;i>=0;i--){
        insertbeg(&llista, lista[i]);
        insertbeg(&llistb, listb[i]);
    }
    for(node *p=llista;p!=NULL;p=p->next){
        for(node *q=llistb;q!=NULL;q=q->next){
            if (p->info==q->info) {
                insertbeg(&llistc, p->info);
            }
        }
    }
    printlist(llista);
    printlist(llistb);
    cout<<"common list:\n";
    printlist(llistc);
    return 0;
}
