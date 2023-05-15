/*
Name       : Avijit Mondal
Department : Masters of Computer Applications(MCA)
College    : Dr. B. C. Engineering College , Durgapur
Level      : 1
Questionn  : Write a C or C++ code to implement quick sort, heap sort, shell sort, tree sort.
*/

#include <iostream>
#include <vector>
using namespace std;

// Quick sort implementation
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

// Heap sort implementation
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Shell sort implementation
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Tree sort implementation
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert(Node*& root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

void inOrder(Node* root, vector<int>& arr) {
    if (!root) {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

void treeSort(vector<int>& arr) {
    Node* root = NULL;
    for (int i = 0; i < arr.size(); i++) {
        insert(root, arr[i]);
    }
    arr.clear();
    inOrder(root, arr);
}

// Driver code
int main() 
{
    vector<int> arr;
	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(1);
	arr.push_back(9);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(8);
	arr.push_back(4);
	
	cout << "Before Sorting: ";
    for (int i = 0; i < arr.size(); i++) 
	{
    cout << arr[i] << " ";
	}

    // Quick sort
    quickSort(arr, 0, arr.size() - 1);
    cout << "\nQuick sort: ";
    for (int i = 0; i < arr.size(); i++) 
	{
    cout << arr[i] << " ";
	}

    cout << endl;

    // Heap sort
    heapSort(arr);
    cout << "Heap sort: ";
   for (int j = 0; j < arr.size(); j++) 
   	{
    cout << arr[j] << " ";
	}

    cout << endl;

    // Shell sort
    shellSort(arr);
    cout << "Shell sort: ";
    for (int j = 0; j < arr.size(); j++) 
   	{
    cout << arr[j] << " ";
	}

    cout << endl;

    // Tree sort
    treeSort(arr);
    cout << "Tree sort: ";
     for (int j = 0; j < arr.size(); j++) 
   	{
    cout << arr[j] << " ";
	}

    cout << endl;

    return 0;
}
