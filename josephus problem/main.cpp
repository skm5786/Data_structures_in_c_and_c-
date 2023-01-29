#include <iostream>
using namespace::std;
class node{
public:
    string info;
    node *next=NULL;
};
void insert(node** circularlist,string name){
    node *p=new node;
    p->info=name;
    if (*circularlist==NULL) {
        *circularlist=p;
        (*circularlist)->next=*circularlist;
    }
    node *q=*circularlist;
    while (q->next!=*circularlist) {
        q=q->next;
    }
    q->next=p;
    p->next=*circularlist;
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
int delafter(node *p){
    node *q;
    if (p==NULL) {
        cout<<"void deletion"<<endl;
        return 1;
    }
    q=p->next;
    cout<<q->info<<endl;
    p->next=q->next;
    free(q);
    return 0;
}
int main(){
    string name;
    int n;
    cout <<"enter name"<<endl;
    cin>>name;
    node * clist=NULL;
    while (name!="end") {
        insert(&clist, name);
        cout <<"enter name"<<endl;
        cin>>name;
    }
    cout<<"enter number"<<endl;
    cin>>n;
    while (clist!=clist->next) {
        for(int i=1;i<n-1;i++){
            clist=clist->next;}
        cout<<"person removed: "<<endl;
            delafter(clist);
        clist=clist->next;
    }
    cout<<"last person left: "<<clist->info<<endl;
    return 0;
}
