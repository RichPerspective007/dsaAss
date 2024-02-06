/*
7. Write a menu driven program in C or C++ to perform the following operations on single linked
list.
    (a) insert a node at the beginning of the list.
    (b) insert a node at the end of the list.
    (c) delete a node from the beginning of the list.
    (d) delete a node at the end of the list.
    (e) display the whole list.

    8. (d) search an element x in the list.
    (e) reverse the list.
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int val){
            value = val;
            next = NULL;
        }
};

class MySLL{
    public:
        Node* head;
        MySLL(){
            head = NULL;
        }
        void insertBeg(int val){
            if (head == NULL){
                head = new Node(val);
            }
            else{
                Node* newNode = new Node(val);
                newNode->next = head;
                head = newNode;
            }
            cout <<"\n"<< val << " inserted at the beginning of the list.\n";
        }
        void insertEnd(int val){
            if (head == NULL){
                head = new Node(val);
            }
            else{
                Node* curr = head;
                Node* newNode = new Node(val);
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
            cout <<"\n"<< val << " inserted at the end of the list.\n";
        }
        void delBeg(){
            if (head == NULL){
                cout << "\nThe list is empty. Nothing to delete.\n";
            }
            else{
                head = head->next;
                cout << "\nSuccess.First node of the list deleted.\n";
            }
        }
        void delEnd(){
            if (head == NULL){
                cout << "\nThe list is empty. Nothing to delete.\n";
            }
            else if(head->next == NULL){
                delBeg();
            }
            else{
                Node* curr = head;
                while (curr->next->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = NULL;
                cout << "\nSuccess.Last node of the list deleted.\n";
            }
        }
        void display(){
            if (head==NULL){
                cout << "\nThe list is empty, nothing to display.\n";
                return;
            }
            Node* curr = head;
            cout << "\nThe values in the list are: ";
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
                cout << "\nList is empty.\n";
                return;
            }
            else if (head->next == NULL){
                cout << "\nThere is only 1 element in the list. So reverse operation is unnecessary.\n";
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
                cout << "\nThe list has been reversed.\n";
            }
        }
};

int main(){
    MySLL sllist = MySLL();
    cout << "Operations on Single Linked List:\n\t- 0. Exit.\n\t- 1. Insert a node at the beginning of the list.\n\t- 2. Insert a node at the end of the list.\n\t- 3. Delete a node from the beginning of the list.\n\t- 4. Delete a node at the end of the list.\n\t- 5. Display the whole list.\n\t- 6. Search by value in the list.\n\t- 7. Reverse the list.\n\nPlease enter your choice: ";
    int ch;
    cin >> ch;
    int item,found;

    while (ch)
    {
        switch (ch)
        {
        case 0:
            break;
        
        case 1:
            cout << "\nPlease enter the value you want to add to the list: ";
            cin >> item;
            sllist.insertBeg(item);
            break;

        case 2:
            cout << "\nPlease enter the value you want to add to the list: ";
            cin >> item;
            sllist.insertEnd(item);
            break;

        case 3:
            sllist.delBeg();
            break;

        case 4:
            sllist.delEnd();
            break;

        case 5:
            sllist.display();
            break;

        case 6:
            cout << "\nPlease enter the value you want search in the list: ";
            cin >> item;
            found = sllist.searchByVal(item);
            if (found>=0){
                cout <<"\n"<< item << " found at position " << found << " in the list.\n";
            }
            else{
                cout <<"\n"<< item << " not found in the list.\n";
            }
            break;

        case 7:
            sllist.reverseOriginalList();
            break;

        default:
            cout << "\nWrong input. Please select only 1 of the given operation codes 0-5.\n";
            break;
        }
        cout << "\nPlease enter your next choice of operation: ";
        cin >> ch;
    }
    cout << "\nAll Single Linked List operations done and program execution complete. Thank you.\n";
    return 0;
}