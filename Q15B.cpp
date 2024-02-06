/*
Write a program to find the nth Fibonacci number using tail recursion.
*/
#include <iostream>
using namespace std;

int fibo_tail(int prev_val, int curr_val, int curr_term, int find_term){
    if (find_term == 1){
        return prev_val;
    }
    if (curr_term == find_term){
        return curr_val;
    }
    return fibo_tail(curr_val,prev_val+curr_val,++curr_term,find_term);
}

int main(){
    int n;
    cout << "\nPlease enter the term number for which the value of the Fibonacci series is required: ";
    cin >> n;

    cout << "\nThe value of term " << n << " of the Fibonacci series is: ";
    int val = fibo_tail(0,1,2,n);
    cout << val << "\n";
}