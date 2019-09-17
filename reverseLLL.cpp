/*
Developer: Hamed Mirlohi
Date: Sep16th 2019
In this C++ program, we are reversing any given Linked List. the O complexity
of following program is O(n)
*/

#include<iostream>

struct node
{
    int data;
    node* next;
};


node* build_LLL(node* head, const int d)
{
    if(head == nullptr)
    {
        head = new node;
        head->next = nullptr;
        head->data = d;
        return head;
    }
    
    node* tmp = head;
    head = new node;
    head->data = d;
    head->next = tmp;
    
    return head;
}

void display_LLL(const node* head)
{
    while(head != nullptr)
    {
        std::cout<<"data: "<<head->data<<std::endl;
        head = head->next;
    }
}

node* reverse_LLL(node* head)
{
    // if no node or single node exist, return head
    if(head == nullptr || head->next == nullptr)
        return head;
    // two node only exist
    if(head->next->next == nullptr)
    {
        node* current = head->next;
        current->next = head;
        head->next = nullptr;        
        return current;
    }
    // more than two nodes exists
    node* prev = head;
    node* current = head->next;
    node* forward = head->next->next;
    while(true)
    {
        current->next = prev;
        prev = current;
        current = forward;
        // forward pointing at the last node?
        if(forward->next == nullptr)
        {
            current->next = prev;
            // make first node pointing to null since its the last node
            head->next = nullptr;
            break;
        }
        forward = forward->next;
    }
    return current;
}


int main(void)
{
    node* head = nullptr;
    head = build_LLL(head, 10);
    head = build_LLL(head, 20);
    //head = build_LLL(head, 30);
    //head = build_LLL(head, 40);
    
    display_LLL(head);
    
    std::cout<<"Reversing: -------------------" << std::endl;
    
    
    head = reverse_LLL(head);
    display_LLL(head);
    
    
    
}