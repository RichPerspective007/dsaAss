/*
Write a program in C or C++ to sort a given array using selection sort algorithm. Show
the number of comparison required for a given input.
*/
#include <iostream>
using namespace std;

void printArr(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << "  ";
    }
}
int main(){
    int n;
    int* arr;
    cout << "\nPlease enter the number of elements in the array: ";
    cin >> n;
    arr = new int[n];
    
    cout << "\nPlease enter the elements of the array (integer):\n";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    cout << "\nThe entered array is: ";
    printArr(arr,n);

    int ch;
    cout << "\nPlease enter 1 for ascending order sort or 2 for descending order sort: ";
    cin >> ch;
    if (ch!=1 && ch!=2){
        cout << "\nNone of the correct options chosen. So defaulting to ascending order sort.\n";
        ch=1;
    }
    else if (ch==1)
    {
        cout << "\nComing right up!! The array sorted in ascending order is: ";
    }
    else{
        cout << "\nComing right up!! The array sorted in descending order is: ";
    }
    
    int temp,comparisons = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            switch (ch)
            {
            case 1:
                if (arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
                break;
            
            case 2:
                if (arr[i] < arr[j]){
                    temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
                break;

            default:
                break;
            }
        }
    }
    printArr(arr,n);
}