#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

void heapify(int[], int, int);
void heapSort(int[], int);
void printArray(int[], int);
void bottomUp(int[], int);

int main() {
  bool running = true;
  while(running) {
    char* corf = new char[10]; //Console or file
    char arr[100];
    //  Heap heap = Heap();
    
    cout << "Enter from File or Console? (F/C)" << endl;
    cin >> corf;
    cin.clear();
    cin.ignore(999,'\n');
    if (strcmp(corf, "F") == 0) {
      ifstream file; //fix
      file.open("test.txt");
      while(!file.eof()){
	file.getline(arr, sizeof(file));
      }
      
    }
    else if (strcmp(corf, "C") == 0) {
      char numberset[100];
      cout << "Please enter the number set separated by spaces:" << endl;
      cin.get(arr, 100);
      cin.clear();
      cin.ignore(999, '\n');
      
      //int numberset[] = {1, 2, 4, 5, 2, 3, 1};
      //int arrayLength = sizeof(numberset)/sizeof(numberset[0]);
      
    } else {
      cout << "Invalid input" << endl;
    }
    char* tok = strtok(arr, " ");
    
    
    
  }
}

void heapify(int arr[], int n, int i) //Heapify formula obtained from GeeksforGeeks website  
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

void bottomUp(int arr[], int length) { //Supposed to heapify the tree from bottom up
  int parent = length/2;
  if (arr[length]>arr[parent] && length > 0) {
    swap(arr[length], arr[parent]);
    bottomUp(arr[], parent);
  }
}

void heapSort(int arr[], int length) {
  
}

void printArray(int arr[], int n) //To be fixed 
{ 
  for (int i=0; i<n; ++i) 
    cout << arr[i] << " "; 
  cout << "\n"; 
} 
