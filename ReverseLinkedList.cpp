#include<iostream>

using namespace std;

struct Node {
    int val ;
    Node * next;
};

void ReverseLinkedList(Node * head){

   Node * temp = head ;
   Node * forward = head->next;

    temp->next = nullptr;

   while(temp) {
        Node * another = forward->next;
        forward->next = temp;
        forward = another;
        temp = forward;
   }

   head = temp ;

}