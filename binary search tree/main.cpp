#include <iostream>
using namespace::std;
class node{
public:
    int info;
    node *left;
    node* right;
    node *father;
};
node *getnode(){
    node *p=new node;
    p->left=NULL;
    p->right=NULL;
    p->father=NULL;
    return p;
}
node *maketree(int x){
    node *p=getnode();
    p->info=x;
    return p;
}
void setleft(node *p,int x){
    if (p==NULL) {
        cout<<"void insertion"<<endl;
        return;
    }
    else if (p->left!=NULL){
        cout<<"invalid insertion"<<endl;
        return;
    }
    else{
        p->left=maketree(x);
        (p->left)->father=p;
    }
}
void setright(node *p,int x){
    if (p==NULL) {
        cout<<"void insertion"<<endl;
        return;
    }
    else if (p->right!=NULL){
        cout<<"invalid insertion"<<endl;
        return;
    }
    else{
        p->right=maketree(x);
        (p->right)->father=p;
    }
}
node *postion(node *tree,int num){
    node *p=tree;
    node *q=tree;
    while ((q!=NULL)) {
        p=q;
        if (num<(p)->info)
            q=p->left;
        else
            q=p->right;
        if (q==NULL) {
            break;
        }
    }
    return p;
}
void BSTmaker(node *tree,int a[],int n){
    int i;
    int num;
    for(i=1;i<n;i++){
        num=a[i];
        node *p=postion(tree,num);
 if (num<(p)->info)
            setleft(p, num);
        else
            setright(p, num);
    }
}
static int counte=0;
void intrav(node* tree){
    if (tree!=NULL) {
        intrav(tree->left);
        cout<<tree->info<<" ";
        counte++;
        intrav(tree->right);
    }
    else
        return;
}

node *searchnode(node *tree,int x){
    node *q;
    node *p=tree;
    while (p!=NULL) {
        if (p->info==x) {
            return p;
        }
        q=p;
    if(x<p->info)
        p=p->left;
        else
            p=p->right;
    }
    return p;
    }
node *predeccesor(node *m){
    node *p;
    p=m->left;
    if (p==NULL) {
        <#statements#>
    }
    while (p->right!=NULL) {
        p=p->right;
    }
    return p;
}

int main(){
    int a[]={12,34,65,54,66,43,75,753,252,34,42,46,343,43,31};
    int n=(sizeof(a)/sizeof(a[0]));
    node *tree=maketree(a[0]);
    BSTmaker(tree,a, n);
//    node *tree=maketree(2);
//    setleft(tree, 5);
//    setright(tree, 6);
//    setleft(tree->left, 7);
//    setright(tree->left, 8);
//    setleft(tree->right, 9);
//    setright((tree->right)->left, 11);
    intrav(tree);
    cout<<endl;
    node *m=searchnode(tree,252);
//    if (m==NULL) {
//        cout<<"invalidd";
//    }
//    else
    cout<<(m)->info;
    node*s=predeccesor(m);
    cout<<s->info;
    return 0;
    
}
