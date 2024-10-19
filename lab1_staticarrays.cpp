#include <iostream> 
using namespace std; 

class StaticArray { 
private: 
    int arr[10];  
    int size; 

public:
    StaticArray() {
        size = 0; 
    }

    void insert(int element, int index) { // inserts element at given index
        if (size >= 10) {
            cout << "Array is full. Cannot insert more elements." << endl;
            return;
        }
        if (index < 0 || index > size) {
            cout << "Invalid index." << endl;
            return;
        } 
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element; // inserts new element
        size++;
        cout << "Element inserted successfully!" << endl;
    }

    void remove(int index) { // deletes element at given index
        if (size == 0) {
            cout << "Array is empty. Cannot delete elements." << endl;
            return;
        } // ensures if array is empty before attempting to delete an element 
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; // updates the size of the array
        cout << "Element deleted successfully." << endl;
    }

    void search(int element) { // searches for specific element
        for (int i = 0; i < size; i++) { // iterates over the array
            if (arr[i] == element) {
                cout << "Element " << element << " found at index " << i << endl; // prints index if element found
                return;
            } 
        }
        cout << "Element not found." << endl; // only prints if element is not found in array
    }

    void display() { // display all the elements in array
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        } // checks if array is empty 
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    StaticArray arr;

    int initialValues[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    
    for(int i = 0; i < 10; i++){
        arr.insert(initialValues[i], i);
    }

    arr.display(); // displays array before operations

    // trying insertion functions
    arr.insert(8, 0); // inserts 8 at index 0
    arr.insert(2, 1);  // inserts 2 at index 1
    arr.insert(15, 3); // inserts 15 at index 3

    arr.display(); // displays after insertion operations

    // search functions
    arr.search(2);  // searches for 2
    arr.search(25);  // searches for 25

    // remove functions
    arr.remove(1); // deletes element at index 1

    // displays after functions
    arr.display();

    return 0;
}
