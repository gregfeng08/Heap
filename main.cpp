#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

void heapify(int[], int, int);
void displayHeap(int[], int);
void printArray(int[], int);
void bottomUp(int[], int);


int main() {
  int maxHeap[100];
  int heapLength = 0;
  bool running = true;
  while(running) {
    char* corf = new char[10]; //Console or file
    char arr[100];
    fill_n(arr, 100, 0);
    char file[100];
    //  Heap heap = Heap();
    //Original attempt to use a separate heap class to do this project above
    cout << "Hi and welcome to HEAP, a program that takes in a set of numbers and sorts it into a max heap before displaying it!" << endl;
    cout << "Enter from File(F) or Console(C)? Another option is exit(E). (F/C)" << endl;
    cin.getline(corf, sizeof(corf));
    cin.clear(); //You have to press an enter here for some reason
    cin.ignore(999,'\n');
    if (strcmp(corf, "F") == 0) {
      cout<<"File Name?"<<endl;
      cin.getline(file, sizeof(file));
      ifstream fileStream; //Uses ifstream to read input from files, in this case, test.txt
      fileStream.open(file);
      if(fileStream){
	fileStream.getline(arr, sizeof(arr));
      }
      else{
	cout<<"File not found"<<endl;
      }
    }
    else if (strcmp(corf, "C") == 0) {
      cout << "Please enter the number set separated by spaces:" << endl;
      cin.get(arr, 100);
      cin.clear();
      cin.ignore(999, '\n');
      
      //int numberset[] = {1, 2, 4, 5, 2, 3, 1};
      //int arrayLength = sizeof(numberset)/sizeof(numberset[0]);
      
    }
    else if (strcmp(corf, "E") == 0) {
      cout << "Shutting down..." << endl;
      running = false;
    }
    else {
      cout << "Invalid input" << endl;
    }
    char* tok = strtok(arr, " ");
    while(tok) { //SPlits the numerical input separated by spaces into numbers 
      maxHeap[heapLength] = atoi(tok); //Implementation of tokenizers was suggested by Jason and Finn
      bottomUp(maxHeap, heapLength);
      tok = strtok(NULL, " ");
      heapLength++;
    }
    displayHeap(maxHeap, heapLength); //Uses displayHeap function to extract the numbers from the heap     
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

void bottomUp(int arr[], int length) { //Supposed to heapify the tree from bottom up recursively
  int parent = length/2; //This particular method implemented with help from Jason Z.
  if (arr[length]>arr[parent] && length > 0) { 
    swap(arr[length], arr[parent]);
    bottomUp(arr, parent);
  }
}

void printArray(int arr[], int n) //Still haven't figured out how to display the heap sideways
{ //Visual display function
  for (int i=0; i<n; ++i) 
    cout << arr[i] << " "; 
  cout << "\n"; 
} 

void displayHeap(int arr[], int length){ //Function that extracts numbers from the heap created in the array and sorts it from maximum to minimum
  int lengthHolder = length; //Tree removal function
  for(int i = 0; i<lengthHolder; i++){ //
    cout<<arr[0]<<" ";
    int last = arr[length-1];
    arr[0] = last;
    length--; //
    heapify(arr, length, 0);
  }
  cout << endl; //Spacer
}
