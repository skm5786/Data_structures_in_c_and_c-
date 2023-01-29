//queues using linked list
#include <iostream>
using namespace::std;
class Node{
public:
    int data;
    Node* next;
};
class qll:protected Node{
    Node* front=nullptr;
    Node* rear=nullptr;
public:
    bool empty(){
        if (front==nullptr) {
            return true;
        } else {
            return false;
        }
    }
    int remove(){
        Node* p=new Node();
        int x;
        if (empty()) {
            cout<<"queue is underflowed"<<endl;
            exit(1);
        }
            p=front;
            x= p->data;
            front=p->next;
        if (front==nullptr) {
            rear=nullptr;
        }
        delete p;
        return x;
    }
    void insert(int x){
        Node *p=new Node();
        p->data=x;
        p->next=nullptr;
        if (rear==nullptr) {
            front=p;
        } else{
            rear->next=p;}
            rear=p;
    }
};
int main(){
    qll a;
    int x=0,n;
    while (1) {
        cout<<"enter 1 to insert an element"<<endl;
        cout<<"enter 2 to remove an element"<<endl;
        cout<<"enter 3 to exit"<<endl;
        cin>>x;
        
        switch (x) {
            case 1:
                cout<<"enter your element  ";
                cin>>n;
                a.insert(n);
                break;
            case 2:
                cout<<"removed element is: "<<a.remove()<<endl;
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
