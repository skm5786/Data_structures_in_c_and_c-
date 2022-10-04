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
    qll l;
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    cout<<l.remove()<<endl;
    cout<<l.remove()<<endl;
    return 0;
}
