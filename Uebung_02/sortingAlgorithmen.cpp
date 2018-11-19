#include <iostream>
#include <vector>

using namespace std;

void merge(int input[], int leftIndex, int middleIndex, int rightIndex);
void mergeSort(int input[], int leftIndex, int rightIndex);
void selectionSort(int input[], int size);
void insertionSort(int input[], int size);
void bubbleSort(int input[], int size);
void printArray(int input[], int size);

int main(int argc, char* argv[]) {
    string sort_type = string(argv[1]);
    int n = argc - 2;
    // do not count executable name or first argument
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i+2]);
    }

    cout << "Original list: ";
    printArray(arr, n);

    if(sort_type == "bubble"){
        bubbleSort(arr, n);
        cout << "Sorted list: ";
        printArray(arr, n);
    }else if(sort_type == "selection"){
        selectionSort(arr, n);
        cout << "Sorted list: ";
        printArray(arr, n);
    }else if(sort_type == "insertion"){
        insertionSort(arr, n);
        cout << "Sorted list: ";
        printArray(arr, n);
    }else if(sort_type == "merge"){
        mergeSort(arr, 0, n - 1);
        cout << "Sorted list: ";
        printArray(arr, n);
    }else{
        cout << "Sorry, " << sort_type << " sort is not implemented!" << endl;
    }


    delete [] arr;
    return 0;
}

void printArray(int input[], int size){
    cout << "[";
    for(int index = 0; index < size; index++){
         if(index == size - 1){
             cout << input[index];
         }else{
             cout << input[index] << ", ";
         }
    }
    cout << "]" << endl;
}

void mergeSort(int input[], int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int middleIndex = (leftIndex + rightIndex) / 2;
        mergeSort(input, leftIndex, middleIndex);
        mergeSort(input, middleIndex + 1, rightIndex);
        merge(input, leftIndex, middleIndex, rightIndex);
    }
}

void merge(int input[], int leftIndex, int middleIndex, int rightIndex){
    int leftHalfSize = middleIndex - leftIndex + 1;
    int rightHalfSize = rightIndex - middleIndex;
    int leftHalf[leftHalfSize];
    int rightHalf[rightHalfSize];

    for(int index = 0; index < leftHalfSize; index++){
        leftHalf[index] = input[leftIndex + index];
    }
    for(int index = 0; index < rightHalfSize; index++){
        rightHalf[index] = input[middleIndex + 1 + index];
    }
    int l = 0;
    int r = 0;
    int i = leftIndex;
    while(l < leftHalfSize && r < rightHalfSize){
        if(leftHalf[l] <= rightHalf[r]){
            input[i] = leftHalf[l];
            l = l + 1;
        }else{
            input[i] = rightHalf[r];
            r = r + 1;
        }
        i = i + 1;
    }

    while (l < leftHalfSize)
    {
        input[i] = leftHalf[l];
        l++;
        i++;
    }

    while (r < rightHalfSize)
    {
        input[i] = rightHalf[r];
        r++;
        i++;
    }
}

void selectionSort(int input[], int size){
    int minIndex = 0;
    for(int index = 0; index < size; index++){
        minIndex = index;
        for(int j = index + 1; j < size; j++){
            if(input[j] < input[minIndex]){
                minIndex = j;
            }
        }
        int temp = input[index] ;
        input[index]  = input[minIndex];
        input[minIndex]= temp;
    }
}

void insertionSort(int input[], int size){
    for(int index = 1; index < size; index++){
        int j = index;
        while(j > 0 && input[j - 1] > input[j]){
            int temp = input[j] ;
            input[j]  = input[j - 1];
            input[j - 1]= temp;
            j--;
        }
    }
}

void bubbleSort(int input[], int size){
    for(int index = 0; index < size; index++){
        for(int j = 0; j < size - index; j++){
            if(input[j] > input[j + 1]){
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}
