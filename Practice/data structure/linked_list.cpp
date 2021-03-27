#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node* head = NULL;
void insert(int x){
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
}

Node* insert(Node* head, int x){
     Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    return head;
}
void insert(Node** head, int x){
    Node* newNode = new Node(x);
    newNode->next = *head;
    *head = newNode;
    //return head;
}
void print(Node* head){
    Node* tempNode = head;
    while(tempNode!=NULL){
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}
void print(){
    Node* tempNode = head;
    while(tempNode!=NULL){
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void insert_at(int pos, int data){
    Node* new_node = new Node(data); 
    if(pos == 1){
        new_node->next = head; 
        head = new_node; 
        return;  
    }
    Node* temp_node = head; 
    for(int i = 0; i < pos - 2; i++){
        temp_node = temp_node->next; 
    }
    new_node->next = temp_node->next;  
    temp_node->next = new_node;
}

void delete_at(int pos){
    if(pos == 1){
        Node* temp_node = head; 
        head = head->next; 
        delete(temp_node);
        return;  
    }
    Node* temp_node = head; 
    for(int i = 0; i < pos - 2; i++){
        temp_node = temp_node->next; 
    }
    Node* del_node = temp_node->next; 
    temp_node->next = temp_node->next->next; 
    free(del_node); 
}

void reverse(){
    Node *temp = head, *prev = NULL, *current = head, *next; 
    while(current != NULL){
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    }
    head = prev;
}
void print_recursive(Node* head){
    if(head == NULL) return;
    printf("%d ", head->data);
    print_recursive(head->next); 
}
void print_recursive_reverse(Node* head){
    if(head == NULL) return;
    print_recursive_reverse(head->next); 
    printf("%d ", head->data);
    
}
void reverse_recursive(Node* p){
    if(p->next == NULL){
        head = p; 
        return;
    }
    reverse_recursive(p->next); 
    p->next->next = p; 
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert_at(2, 1);
    insert_at(1, 4); 
    print();
    reverse();
    print(); 
    delete_at(1);
    print();

    Node* h = NULL;
    h = insert(h, 1);
    h = insert(h, 2);
    h = insert(h, 3);
    print(h);

    Node* hh = NULL;
    insert(&hh, 1);
    insert(&hh, 2);
    insert(&hh, 3);
    print(hh);

    return 0;
}
