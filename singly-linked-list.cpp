#include <iostream>
using namespace std;
struct Node {
   int data;
    Node *next;
};

struct Node *head = NULL, *p, *temp;

void insertfront(int new_data) {
   struct Node *new_node = new Node; //create empty node
   new_node->data = new_data;
   new_node->next = NULL;
   if (head == NULL){
        head = new_node;
   }
   else{
        new_node->next = head;
        head = new_node;
   }
}

void deleteFront(){
    if (head == NULL)  //empty list
        return;
    else{
        p = head;
        head = head->next;
        p->next = NULL; //unlink before deleting
        delete p;
    }
}

void deleteLast(){
    if (head == NULL) //empty list
        return;
    else if (head->next == NULL){ //if it contains one element only
        delete head;
        head = NULL;
    }
    else{ //more than one elements
        p = head;
        while (p->next->next != NULL){
            p = p->next;
        }
        delete p->next;
        p->next = NULL;
    }
}

void insertlast(int item){
    struct Node *new_node = new Node;
    new_node->data = item;
    new_node->next = NULL;
    if (head == NULL){ //if empty
        head = new_node;
    }
    else {
        p = head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = new_node;
    }
}

void insertAfter(int key, int item){
    if (head == NULL) return;
    else{
        bool found = false;
        p = head;
        while (p != NULL){
            if (p->data == key){
                found = true;
                break;
            }
            p = p->next;
        }
        if (found){
            struct Node *new_node = new Node;
            new_node->data = item;
            new_node->next = p->next;
            p->next = new_node;
        }
        else {
            cout << "key not found\n";
        }
    }
}

void display() {
    cout<<"The linked list is: ";
    p = head;
    if (head == NULL) cout << "empty\n";
    else {
       while (p != NULL) {
          cout<< p->data <<" ";
          p = p->next;
       }
    }
}

void update(int key, int item){
    p = head;
    bool found = false;
    while(p != NULL){
        if (p->data == key){
            found = true;
            break;
        }
        p = p->next;
    }
    if (found){
        p->data = item;
    }
    else {
        cout<<"key not found :(\n";
    }
}

void search(int key){
    p = head;
    int index = 0;
    bool found = false;
    while(p != NULL){ //to look for a key on the last node...
        if (p->data == key){
            found = true;
            break;
        }
        p = p->next;
        index++;
    }
    if (found){
        cout << "key " << key << " found at index " << index << "\n" ;
    }
    else {
        cout<<"key not found :(\n";
    }
}

int main() {

    insertfront(5);
    insertlast(6);
    insertAfter(6,8);
    insertfront(21);
    insertlast(7);
    deleteFront();
    deleteLast();
    update(8,7);
    search(6);
    display();

}
