#include <iostream>
using namespace::std;
class Node{
public:
    int data;
    Node* next=nullptr;
};
class sll:protected Node{
    Node* top=nullptr;

public:
    bool empty(){
        if (top==nullptr) {
            return true;
        } else {
            return false;
        }
    }
    int pop(){
        int x;
        if (empty()) {
            cout<<"stack is underflowed"<<endl;
            exit(1);
        }
        Node *p=top;
        x=p->data;
        top=p->next;
        free(p);
        return x;
    }
    void push(int x){
        Node *p=new Node();
        p->data=x;
        p->next=top;
        top=p;
            }
};
int main(){
    sll a;
    int x=0,n;
    while (1) {
        cout<<"enter 1 to push an element"<<endl;
        cout<<"enter 2 to pop an element"<<endl;
        cout<<"enter 3 to exit"<<endl;
        cin>>x;
        
        switch (x) {
            case 1:
                cout<<"enter your element  ";
                cin>>n;
                a.push(n);
                cout<<n<<" is pushed on stack"<<endl;
                break;
            case 2:
                cout<<"popped element is: "<<a.pop()<<endl;
                break;
            case 3:
                exit(1);
                break;
            default:
                cout<<"invalid value entered"<<endl;
                break;
        }
    }
    return 0;
}
