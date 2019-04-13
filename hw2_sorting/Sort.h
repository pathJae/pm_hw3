#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <ctime>
using namespace std;
/*
Input : array, two address of array
Output : void
Fuction Description : swaping array elements
*/
void swap(double* (&A), int i, int j) {
	double temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

class QuickSort {
	
public:
	void print_time() const {
		cout << fixed;
		cout.precision(4);
		cout << "QuickSort : " << seconds << " sec" << endl;
	}
	// friend fuctinon
	friend bool check_quick(QuickSort*);

	QuickSort() : size(10), seconds(0){
		// constructor
		arr = new double[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	}

	~QuickSort() {
		// destructor
		delete[] arr;
	}

	void run() {
		begin = clock();
		qSort(arr, 0, size - 1);
		end = clock();
		seconds = (double)(end - begin) / CLOCKS_PER_SEC;
		if (returnIndex) {
			cout << "Terminated due to the time limit" << endl;
		}
	}

	/*
	Input : array, start pointer, end pointer
	Output : void
	Fuction Description : recursion fuction
	*/
	void qSort(double* arr,int start, int end) {
		if ((clock() - begin) >= 10000) {
			returnIndex = 1;
			return;
		}
		int partPoint = partition(arr, start, end);
		if (partPoint> start+1) {
			qSort(arr, start, partPoint -1);
		}
		if (partPoint < end) {
			qSort(arr, partPoint, end);
		}
	}
	/*
	Input :array, start, end pointer
	Output : partition pointer.
	Fuction Description : partioning fuction. 
	*/
	int partition(double * arr, int start, int end) {
		int pivot = arr[start];
		int i = start;
		int j = end;
		while (i <= j) {
			while (arr[i] < pivot) {
				i++;
			}
			while (arr[j] > pivot) {
				j--;
			}
			if (i <= j) {
				swap(arr, i, j);
				i++;
				j--;
			}
		} return i;
	}

	void set(double *arr, int size) {
		// new input array and its size are set
		this->size = size;
		this->arr = new double[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = arr[i];
		}
	}
private:
	double *arr;
	int size;
	double seconds;
	clock_t begin, end;
	int returnIndex;
};

////////////////////////////////////////////////////////////////////////
class MergeSort {
public:
	void print_time() const {
		cout << "MergeSort : " << seconds << " sec" << endl;
	}
	friend bool check_merge(MergeSort*);
	// implement the following functions
	MergeSort() {
		// constructor
		size = 10;
		arr = new double[size] {1,2,3,4,5,6,7,8,9,10};
		seconds = 0;
	}

	~MergeSort() {
		// destructor
		delete[] arr;
	}
	void run() {

		begin = clock();
		mergeSort(arr, 0, size - 1);
		end = clock();

		seconds = (double)(end - begin) / CLOCKS_PER_SEC;
		if (returnIndex) {
			cout << "Terminated due to the time limit" << endl;
		}
	}

	void mergeSort(double*arr, int p, int r) {
		if ((clock() - begin) >= 10000) {
			returnIndex = 1;
			return;;
		}
		if (p < r) {
			int q = floor((p + r) / 2);
			mergeSort(arr, p, q);
			mergeSort(arr, q + 1, r);
			merge(arr, p, q, r);
		}
	}

	void merge(double * arr, int p, int q, int r) {
	
		int n1 = q - p + 1;
		int n2 = r - q;

		double *left = new double[n1+1];
		double *right = new double[n2+1];

		for (int i = 0; i < n1; i++) {
			left[i] = arr[p + i ];
		}
		for (int i = 0; i < n2; i++) {
			right[i] = arr[q + i+1];
		}
		left[n1] = INFINITY;
		right[n2] = INFINITY;
		
		int i = 0;
		int j = 0;
		for (int k = p; k <= r; k++) {

			if (left[i] <= right[j]) {
				this->arr[k] = left[i];
				i++;
			}
			else {
				this->arr[k] = right[j];
				j++;
			}
		}
		delete[] left;
		delete[] right;
	}


	void set(double *arr, int size) {
		this->size = size;
		this->arr = new double[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = arr[i];
		}
	}
private:
	double *arr;
	int size;
	double seconds;
	clock_t begin, end;
	int returnIndex;
};
/////////////////////////////////////////////////////////////////////////////
class InsertionSort {
public:
	void print_time() const {
		cout << "InsertionSort : " << seconds << " sec" << endl;
	}
	friend bool check_insertion(InsertionSort*);

	// implement the following functions
	InsertionSort() {
		// constructor
		size = 10;
		arr = new double[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		seconds = 0;
	}

	~InsertionSort() {
		// destructor
		delete[] arr;
	}

	void run() {
		
		begin = clock();
		insertionSort(arr, size - 1);
		end = clock();

		seconds = (double)(end - begin) / CLOCKS_PER_SEC;
		if (returnIndex) {
			cout << "Terminated due to the time limit" << endl;
		}
	}

	void insertionSort(double * arr, int end) {	
		for (int i = 1; i <= end; i++) {
			if ((clock() - begin) >= 10000) {
				returnIndex = 1;
				return;
			}
			int pos = i;
			while (arr[pos - 1] > arr[pos]) {
				swap(arr, pos - 1, pos);
				pos--;
				if (pos <= 0) break;
			
			}
		}
	}

	void set(double *arr, int size) {
		this->size = size;
		this->arr = new double[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = arr[i];
		}
	}

private:
	double *arr;
	int size;
	double seconds;
	clock_t begin, end;
	int returnIndex;
};
/////////////////////////////////////////////////////////////////////////////
class StoogeSort {
public:
	void print_time() const {
		cout << "StoogeSort : " << seconds << " sec" << endl;
	}
	friend bool check_stooge(StoogeSort*);
	// implement the following functions
	StoogeSort() {
		// constructor
		size = 10;
		arr = new double[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		seconds = 0;
		returnIndex=0;
	}
	~StoogeSort() {
		// destructor
		delete[] arr;
	}
	void run() {
		
		begin = clock();
		stoogeSort(arr,0, size - 1);
		end = clock();
		seconds = (double)(end - begin) / CLOCKS_PER_SEC;
		if(returnIndex) {
			cout << "Terminated due to the time limit" << endl;
		}
	}
	void stoogeSort(double *arr, int start, int end) {
		if ((clock() - begin) >= 10000) {
				returnIndex = 1;
				return;
		}
		if (start >= end) return;
		else if (end - start == 1) {
			if (arr[start] > arr[end]) {
				swap(arr, start, end);
			}
		}
		else {
			int d = floor((end - start + 1) / 3);
			stoogeSort(arr, start, end - d);
			stoogeSort(arr, start + d, end);
			stoogeSort(arr, start, end - d);
		}

	}
	void set(double *arr, int size) {
		// new input array and its size are set
		this->size = size;
		this->arr = new double[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = arr[i];
		}
	}
private:
	double *arr;
	int size;
	double seconds;
	clock_t begin, end;
	int returnIndex;
};
/////////////////////////////////////////////////////////////////////////////
class HeapSort {
public:
	void print_time() const {
		cout << "HeapSort : " << seconds << " sec" << endl;
	}
	friend bool check_heap(HeapSort *);
	// implement the following functions
	HeapSort():size(10),seconds(0){
		// constructor
		arr = new double[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	}

	~HeapSort() {
		// destructor
		delete[] arr;
	}

	void run() {
		begin = clock();
		heapSort(arr);
		end = clock();

		seconds = (double) (end - begin) / CLOCKS_PER_SEC;
		if (returnIndex) {
			cout << "Terminated due to the time limit" << endl;
		}

	}
	void heapSort(double * arr) {
		buildMaxHeap(arr,this->size);
		int internalMax;
		for (int i = size; i > 0;i--) {
			if ((clock() - begin) >= 10000) {
				returnIndex = 1;
				return;
			}
			swap(arr, 0,i - 1);

			internalMax = floor(i-1 / 2);
			heapify(arr, 1,i-1);
		}
	}

	void buildMaxHeap(double *arr, int size) {
		int internalMax = floor(size / 2);
		for (int i = internalMax; i > 0;i--) {
			heapify(arr, i, size);
		}
	}
	void heapify(double* arr, int j, int heapSize) {
		int maxNode = maxAmong3(arr, j, heapSize);
		if(maxNode !=j) {
			swap(arr, j-1, maxNode-1);
			heapify(arr, maxNode, heapSize);
		}
	}

	int maxAmong3(double* arr, int parent, int heapSize) {
		int left = 2 * parent;
		int right = 2 * parent + 1;
		if (left > heapSize) {
			return parent;
		}
		else if (right > heapSize) {
			return(arr[parent-1] - arr[left-1] >= 0) ? parent : left;
		}
		else
		{
			return (arr[parent-1] - arr[left-1] >= 0) ? (arr[parent-1] - arr[right-1] >= 0 ? parent : right) : (arr[left-1] - arr[right-1] >= 0 ? left : right);
		}
	}
	void set(double *arr, int size) {
		// new input array and its size are set
		this->size = size;
		this->arr = new double[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = arr[i];
		}
	}


private:
	double *arr;
	int size;
	double seconds;
	clock_t begin, end;
	int returnIndex;
};

#endif