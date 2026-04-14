
/*1.A.1 Contiguous memory allocation means elements are stored in adjacent memory locations next to each other.
       Arrays use contiguious memory allocation so the computer can calculate the address of any
       element using a simple formula (base Address + Index * Size). This provides big O(1)
       constant-time access, meaning you can jump directly to any element instantly. */

/*1.A.2 A memory leak occurs when a program allocates memory on the heap using the new keyword but doesnt delete it.
       If you create a dynamic array inside a function using int* arr = new int[10]; but return from the function without
       calling delete[] arr; that memory remains allocated until the program ends.*/

/*1.A.3 Fixed-size or static arrays have their size determined at compile time and are allocated on stack.
        dynamic arrays are allocated on the heap at runtime using new keyword.
        Fixed size matters because stack memory is limited and the size cannot be changed once the program is executed
        this can lead to wasted space or memory overflows.*/

/*1.A.4 Array access is O(1) because the memory is contiguous. the CPU uses pointers to jump to the exact memory address of any index.
        In a Linked List elements are SCATTERED in memory and each node only knows the address of the next one.
        To find the nth elemen you start at the head and traverse each node sequentially, making it O(n).*/


/*2.A.1 Bubble Sort works by repeatedly going through the list comparing elements and swapping them if they are in the wrong order.
        In each round the largest unsorted element is set to its correct position at the end of the array.
        It is called 'Bubble' sort because the larger values gradually move toward the end of the list, much like bubbles rising to the surface of water.*/

/*2.A.2 Time Complexity:
       Best Case: O(n^2), but O(n) if an optimization flag is used.
       Average Case: O(n^2)
       Worst Case: O(n^2)
       If the array is already sorted and an optimization flag is used the algorithm will complete only one round, detect that no swaps occurred,
       and terminate immediately, resulting in O(n) complexity.*/

/*2.A.3 Comparison:
       1) Bubble Sort repeatedly swaps adjacent elements while Selection Sort finds the minimum element and swaps it once per pass.
       2) Selection Sort is preferred over Bubble Sort because it performs fewer swaps (O(n) swaps vs O(n^2) swaps).
       3) Selection Sort is chosen when write operations are expensive.
        Bubble Sort may be chosen for its simplicity or when an array is almost sorted
*/

/*3.A.1 The prerequisite condition for Binary Search is that the array must be SORTED (ascending or descending).
        This condition matters because the algorithm relies on the logic that if the search key is smaller than the middle element
        it must be in the left half, and if it is larger, it must be in the right half. If the array is unsorted this logic fails. */

/*3.A.2 Dry-run on {2, 5, 8, 12, 16, 23, 38, 45} with key = 23:
       Step 1: low=0, high=7, mid=(0+7)/2 = 3. arr[3]=12. (12 < 23, so low = mid + 1 = 4)
       Step 2: low=4, high=7, mid=(4+7)/2 = 5. arr[5]=23. (23 == 23, Key Found!)*/

/*3.A.3 Binary Search is faster because it uses a divide and conquer approach.
       Linear Search: O(n) - You might have to check every single element.
       Binary Search: O(log n) - You eliminate half of the remaining elements with every single comparison.
       If you are looking for a word in a physical dictionary, Linear Search is reading every page from the start. Binary Search is opening the book in
       the middle and instantly ignoring half the pages repeating until you find the word.*/

/*4.A.1 Big O notation describes the upper bound of the growth rate of an algorithm's execution time as the input size increases.
        We use it instead of seconds because seconds depend on hardware . Big O provides a hardware independent way to measure efficiency.*/

/*4.A.2 Commute to University.
       - Big Omega (Best Case): Every traffic light is green, and there’s no traffic. the minimum time you could possibly take.
       - Big O (Worst Case): Every light is red, there’s an accident, and it’s raining. the maximum time you’ll ever take; you won't be slower than this.
       - Big Theta (Tight Bound): On an average day, it consistently takes you 20-25 minutes. It describes the behavior when the best and worst cases are
         roughly the same.*/

/*4.A.3 Ranking from Fastest to Slowest: O(1) < O(log n) < O(n) < O(n log n) < O(n^2)*/

/*4.A.4 Space complexity measures the total amount of memory an algorithm uses relative to the input size.
        If a function creates a temporary array of size n, its space complexity is O(n) because the memory required grows linearly with the
       input size.*/

/*4.A.5 The student is incorrect. Asymptotic reasoning focuses on what happens as n becomes very large (near infinity).
        Even if a computer is 100x faster, an O(n^2) algorithm's time grows quadratically.
        Eventually, there will be a value of n where the O(n log n) algorithm—even on a slower computer—will be significantly faster than the O(n^2) algorithm on the fast computer.
*/


/*
Q5.A.1 A Singly Linked List is a linear data structure where each node contains data and a pointer to the next node in the sequence.
       Unlike an array which uses contiguous memory, a linked list uses non-contiguous memory.
       Nodes are scattered in the heap, and the list is held together by these pointers.
^/

/*5.A.2 Time Complexities:
       1) Insertion at Head: O(1). You only update the new node's next pointer and the head pointer.
       2) Insertion at Tail: O(n). You must traverse the entire list to find the last node.
       3) Deletion by Value: O(n). In the worst case the value is at the end or not present, requiring a full traversal to find it.
*/
/*5.A.3 If you remove a node without calling delete the memory remains allocated but the program no longer has a pointer to access it.
       This is called a "Memory Leak" You avoid it by using the 'delete' keyword on the pointer to the node after it has been unlinked from the list.
*/

#include <iostream>

using namespace std;
/* <--- del for Q1
// Linear Search Function
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Max and Min
void findMaxMin(int arr[], int size, int &maxVal, int &minVal) {
    if (size <= 0) return;

    maxVal = arr[0];
    minVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
}

int main() {
    int arr1[10] = {4, 15, 7, 23, 1, 9, 42, 18, 6, 30};
    int size = 10;

    int key = 42;
    int resultIndex = linearSearch(arr1, size, key);

    if (resultIndex != -1) {
        cout << "Key " << key << " found at index: " << resultIndex << endl;
    } else {
        cout << "Key " << key << " not found." << endl;
    }

    int maxVal, minVal;
    findMaxMin(arr1, size, maxVal, minVal);

    cout << "Maximum value: " << maxVal << endl;
    cout << "Minimum value: " << minVal << endl;

    return 0;
}
*/ //<-- del for Q1


/* //del for q2

// print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort with counting
void bubbleSort(int arr[], int n, int &totalSwaps) {
    totalSwaps = 0;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
                totalSwaps++;
            }
        }

        cout << "After " << i + 1 << ": ";
        printArray(arr, n);

        if (!swapped) {
            cout << "No swaps occurred. Array is sorted.\n" << endl;
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int swapCount = 0;

    cout << "Original array: ";
    printArray(arr, n);
    cout << "\n" << endl;

    bubbleSort(arr, n, swapCount);

    cout << "\n" << endl;
    cout << "Sorted array: ";
    printArray(arr, n);

    cout << "Total number of swaps made: " << swapCount << endl;

    return 0;
}
*/ //<-- del for 2





/* // < ---del for q3

// Binary Search with counting
int binarySearch(int arr[], int size, int key, int &iterations) {
    int low = 0;
    int high = size - 1;
    iterations = 0;

    while (low <= high) {
        iterations++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int iterations;

    int key1 = 56;
    int result1 = binarySearch(arr, size, key1, iterations);

    if (result1 != -1) {
        cout << "Key " << key1 << " found at index: " << result1 << endl;
    } else {
        cout << "Key " << key1 << " not found." << endl;
    }
    cout << "Iterations used: " << iterations << endl << endl;

    int key2 = 100;
    int result2 = binarySearch(arr, size, key2, iterations);

    if (result2 != -1) {
        cout << "Key " << key2 << " found at index: " << result2 << endl;
    } else {
        cout << "Key " << key2 << " not found." << endl;
    }
    cout << "Iterations taken: " << iterations << endl;

    return 0;
}
*/ // <-- del for q3




/* //<-- del for q4
    // Q4
  // Derivation for nestedLoop:
   //- Outer loop runs n times.
   //- Inner loop runs n times for every outer iteration.
   //- Total operations = n * n = n^2.
   //- Time Complexity: O(n^2)

void nestedLoop(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }
    cout << "Nested loop operations: " << count << endl;
}


   //Derivation for singleLoop:
   //- Loop runs exactly n times.
   //- Total operations = n.
   //- Time Complexity: O(n)
   //Comparison: O(n) is significantly faster than O(n^2) as n grows.


void singleLoop(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
    }
    cout << "Single loop operations: " << count << endl;
}


   //Time Complexity Analysis:
   //- Outer loop picks each element of A (n iterations).
   //- Inner loop searches through B for that element (n iterations).
   //- Complexity: O(n * n) = O(n^2).

   //More efficient approach:
   //Sort array B first (O(n log n)) and use Binary Search for each element of A (O(log n)), leading to O(n log n) total.

bool checkElements(int A[], int B[], int n) {
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    int n = 100;
    nestedLoop(n);
    singleLoop(n);

    int A[] = {1, 2, 3};
    int B[] = {3, 2, 1};
    if (checkElements(A, B, 3)) {
        cout << "All elements of A exist in B." << endl;
    }

    return 0;
}
*/ //<-- del for q4



// Node structure
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insertion and Display
    void insertAtHead(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    //  Delete by value
    void deleteByValue(int val) {
        if (head == nullptr) {
            cout << "Value " << val << " not found (List empty)." << endl;
            return;
        }

        // Deleting the head node
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != val) {
            prev = current;
            current = current->next;
        }

        //  Value not found
        if (current == nullptr) {
            cout << "Value " << val << " not found in the list." << endl;
            return;
        }

        // Relink and delete
        prev->next = current->next;
        delete current;
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "Original List:" << endl;
    list.display();

    // Delete an existing value
    cout << "\nDeleting 20..." << endl;
    list.deleteByValue(20);
    list.display();

    // Attempt to delete a non-existing value
    cout << "\nAttempting to delete 100..." << endl;
    list.deleteByValue(100);
    list.display();

    return 0;
}


//https://github.com/zazakahub/dsa.git
