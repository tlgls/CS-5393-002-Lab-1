#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;   
    int size;   
    int count;

public:
    DynamicArray(int arrSize) { // constructor
        size = arrSize; // total capacity of the array
        arr = new int[size];
        count = 0;
    }

    ~DynamicArray() { // deconstructor
        delete[] arr; // frees memory 
    }

    void insert(int element, int index) { // inserts element at given index
        if (count >= size) {
            cout << "Array is full. Cannot insert more elements." << endl;
            return;
        }
        if (index < 0 || index > count) {
            cout << "Invalid index." << endl;
            return;
        }
        for (int i = count; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        count++;
        cout << "Element inserted successfully." << endl;
    }

    void remove(int index) { // deletes element at given index
        if (count == 0) {
            cout << "Array is empty. Cannot delete elements." << endl;
            return;
        }
        if (index < 0 || index >= count) {
            cout << "Invalid index." << endl;
            return;
        }
        for (int i = index; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
        cout << "Element deleted successfully." << endl;
    }

    void search(int element) { // searches for specific element
        for (int i = 0; i < count; i++) {
            if (arr[i] == element) {
                cout << "Element " << element << " found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found." << endl;
    }

    void display() { // displays all elements
        if (count == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array (10, 25, 50): ";
    cin >> size;

    if (size != 10 && size != 25 && size != 50) {
        cout << "Invalid size. Please restart the program and enter 10, 25, or 50." << endl;
        return 1;
    }

    DynamicArray arr(size);

    cout << "Enter " << size << " numbers to populate the array:" << endl;
    for(int i = 0; i < size; i++){
        int num;
        cout << "Number for position " << i << ": ";
        cin >> num;
        arr.insert(num,i);
    }

    arr.display();

    arr.insert(15,1); // insert operation

    arr.display(); // displays after inserting 15 at index 1

    arr.search(15); // searches for 15 at index 1
    arr.search(20); // search for 20

    arr.remove(1); // deletes element at index 1

    arr.display(); // displays after deletion


    return 0;
}
