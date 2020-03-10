#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

void heapify(int[], int, int);
void heapSort(int[], int);
void printArray(int[], int);

int main() {
  char* corf = new char[10]; //Console or file
  //  Heap heap = Heap();
  
  cout << "Enter from File or Console? (F/C)" << endl;
  cin >> corf;
  cin.clear();
  cin.ignore(999,'\n');
  if (strcmp(corf, "F") == 0) {
    cout << "Please enter the file path:" << endl;
    
  }
  else if (strcmp(corf, "C") == 0) {
    //char* numberset = new char[100];
    //cout << "Please enter the number set separated by spaces:" << endl;
    //cin.get(numberset, 100);
    //cin.clear();
    //cin.ignore(999, '\n');
    //parseHeap(numberset); //Parses the expression into individual nodes so that it can be sorted into the binary tree
    int numberset[] = {1, 2, 4, 5, 2, 3, 1};
    int arrayLength = sizeof(numberset)/sizeof(numberset[0]);
    //heapSort(numberset, arrayLength);
    printArray(numberset, arrayLength);
    //Algorithm Start
    heapSort(numberset, arrayLength);
    heapSort(numberset[], arrayLength);
    
    //Algorithm End
    printArray(numberset, arrayLength);
  } else {
    cout << "Invalid input" << endl;
  }
  
}

void heapify(int arr[], int n, int i) //Heapify  
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

void heapSort(int arr[], int length) {
  
}

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
