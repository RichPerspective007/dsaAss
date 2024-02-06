#include<iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;
        int priority;
        Node(int val){
            value = val;
            next = NULL;
            priority = NULL;
        }
};

class MySLL{
    public:
        Node* head;
        MySLL(){
            head = NULL;
        }
        void insertBeg(int val,int p = NULL){
            if (head == NULL){
                head = new Node(val);
            }
            else{
                Node* newNode = new Node(val);
                newNode->next = head;
                head = newNode;
            }
            if (p != NULL){
                head->priority = p;
            }
            //cout <<"\n"<< val << " inserted at the beginning of the list.\n";
        }
        Node* insertEnd(int val){
            if (head == NULL){
                head = new Node(val);
                return head;
            }
            else{
                Node* curr = head;
                Node* newNode = new Node(val);
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = newNode;
                return newNode;
            }
            //cout <<"\n"<< val << " inserted at the end of the list.\n";
        }
        void delBeg(){
            if (head == NULL){
                cout << "\nThe Queue is empty. Nothing to delete.\n";
            }
            else{
                head = head->next;
                cout << "\nSuccess. Dequeue operation successful.\n";
            }
        }
        Node* delEnd(){
            if (head == NULL){
                cout << "\nThe stack is empty. Nothing to delete.\n";
            }
            else if(head->next == NULL){
                delBeg();
                return head;
            }
            else{
                Node* curr = head;
                while (curr->next->next != NULL)
                {
                    curr = curr->next;
                }
                cout << "\nPopped "<< curr->next->value << " from the stack.\n";
                curr->next = NULL;
                return curr;
                //cout << "\nSuccess.Last node of the list deleted.\n";
            }
        }
        void display(){
            if (head==NULL){
                cout << "\nThe data structure is empty, nothing to display.\n";
                return;
            }
            Node* curr = head;
            //cout << "\nThe values in the list are: ";
            while (curr!=NULL)
            {
                cout << curr->value << "  ";
                curr = curr->next;
            }
        }
        int searchByVal(int x){
            if (head==NULL){
                return -1;
            }
            else{
                Node* curr = head;
                int pos = 1;
                while (curr!=NULL)
                {
                    if (curr->value == x){
                        return pos;
                    }
                    pos++;
                    curr = curr->next;
                }
                return -1;
            }
        }
        void reverseOriginalList(){
            if (head == NULL){
                //cout << "\nList is empty.\n";
                return;
            }
            else if (head->next == NULL){
                //cout << "\nThere is only 1 element in the list. So reverse operation is unnecessary.\n";
                return;
            }
            else{
                Node* newHead;
                Node* curr = head;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                newHead = curr;
                while (head->next->next != head)
                {
                    curr = head;
                    while (curr->next->next != NULL && curr->next->next->next != curr->next)
                    {
                        curr = curr->next;
                    }
                    curr->next->next = curr;
                }
                head->next = NULL;
                head = newHead;
                //cout << "\nThe list has been reversed.\n";
            }
        }
        void insertByPriority(int x,int p){
            if (head == NULL){
                Node* newNode = new Node(x);
                newNode->priority = p;
                head = newNode;
                return;
            }
            else if (head->priority < p)
            {
                insertBeg(x,p);
                return;
            }
            
            else{
                Node* curr = head;
                Node* newNode = new Node(x);
                newNode->priority = p;
                while (curr->next!=NULL)
                {
                    if (curr->priority >= p && curr->next->priority < p){
                        newNode->next = curr->next;
                        curr->next = newNode;
                        return;
                    }
                    curr = curr->next;
                }
                curr->next = newNode; //if lowest priority given
            }
            cout << "\nInsert operation successful.\n";
        }
};