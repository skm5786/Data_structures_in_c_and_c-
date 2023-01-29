#include <iostream>
using namespace::std;
class Dnode{
public:
    int info;
    Dnode* left=NULL;
    Dnode* right=NULL;
};
int deletef(Dnode* p){
    int x;
    Dnode* q;
    Dnode *r;
    if (p==NULL) {
        cout<<"void deletion\n";
        return -1;
    }
    x=p->info;
    q=p->left;
    r=p->right;
    q->right=r;
    r->left=q;
    free(p);
    return x;
}
void insertright(Dnode **p,int x){
    Dnode* q=new Dnode;
    q->info=x;
    if (*p==NULL) {
        *p=q;
        return ;
    }
    else if ((*p)->right==NULL){
        (*p)->right=q;
        q->left=*p;
    }
    else{
        q->right=(*p)->right;
        q->left=*p;
        ((*p)->right)->left=q;
        (*p)->right=q;
    }
 
}
Dnode* insertleft(Dnode **p,int x){
    Dnode* q=new Dnode;
    q->info=x;
    if (*p==NULL) {
        *p=q;
        return NULL;
    }
    else if ((*p)->left==NULL){
        (*p)->left=q;
        q->right=*p;
    }
    else{
        q->left=(*p)->left;
        q->right=*p;
        ((*p)->left)->right=q;
        (*p)->left=q;
    }
    return q->left;
}
void printlist(Dnode *list){
    Dnode *p=list;
    while (p!=NULL) {
        cout<<p->info<<" ";
        p=p->right;
    }
    cout<<endl;
    free(p);
}
int main(){
    Dnode *list=NULL;
    insertright(&list, 1);
//    cout<<list->info;
    insertright(&list, 2);
//    cout<<list->info;
    insertright(&list, 3);
    insertright(&list, 4);
    insertright(&list, 5);
    insertright(&list, 6);
    insertleft(&list, 2);
    insertleft(&list, 3);
    insertleft(&list, 4);
    insertleft(&list, 5);
 insertleft(&list, 6);
    Dnode*p=list;
    Dnode*l=list;
    while (l->left!=NULL) {
        l=l->left;
    }
    while (p->right!=NULL) {
        p=p->right;
    }
    p->right=l;
    p=list;
//    deletef(p->left);
        do {
            cout<<p->info<<" ";
            p=p->right;
        }while(p!=list);
        cout<<endl;
    return 0;
}
