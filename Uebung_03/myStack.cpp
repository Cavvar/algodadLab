#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define SIZE 50

using namespace std;

bool areParenthesesBalanced(string input);

class Stack{
private:
    int stackSize;
    int topIndex;
    char myStack[SIZE];
    char* stackPointer = myStack;

public:
    Stack(int n){
        stackSize = n;
        topIndex = -1;
    }

    int getStackSize(){
        return stackSize;
    }

    int getTopIndex(){
        return topIndex;
    }

    void setTopIndex(int element){
        topIndex = element;
    }

    int size(){
        return getTopIndex() + 1;
    }

    bool isEmpty(){
        if(getTopIndex() < 0){
            return true;
        }else{
            return false;
        }
    }

    char peek(){
        if(isEmpty() == true){
            cout << "StackEmptyException" << endl;
            exit(1);
        }
        return *(stackPointer + getTopIndex());
    }

    char pop(){
        if(isEmpty() == true){
            cout << "StackEmptyException" << endl;
            exit(1);
        }
        char element = *(stackPointer + getTopIndex());
        *(stackPointer + getTopIndex()) = 0;
        setTopIndex(getTopIndex() - 1);
        return element;
    }

    void push(char element){
        if(size() == getStackSize()){
            cout << "StackFullException" << endl;
            exit(1);
        }
        setTopIndex(getTopIndex() + 1);
        *(stackPointer + getTopIndex()) = element;
    }

};

int main(int argc, char** argv){
    string input = argv[1];
    if(areParenthesesBalanced(input)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }

    return 0;
}

bool areParenthesesBalanced(string input){
    Stack pda(input.length());

    for(int index = 0; index < input.length(); index++){
        char currentValue = input[index];
        if(currentValue == '('){
            pda.push(currentValue);
        }else if(currentValue == ')'){
            if(pda.isEmpty()){
                return false;
            }else{
                pda.pop();
            }
        }
    }

    return pda.isEmpty() ? true:false;
}
