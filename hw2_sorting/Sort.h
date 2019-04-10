#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <ctime>

using namespace std;

class QuickSort {
public:
	void print_time() const {
		cout << "QuickSort : " << seconds << " sec" << endl;
	}
	

	// implement the following functions
	QuickSort() {
		// constructor
		size = 10;
		arr = new double[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		seconds = 0;
	}

	~QuickSort() {
		// destructor
		delete[] arr;
	}

	void run() {
		// sorting algorithm is applied
		// elapsed time is also recorded in seconds

		seconds = clock();
		quick(arr, 0, size-1);

		seconds = clock() - seconds;
	}
	void quick(double* arr,int start, int end) {
		if (start >= end) {
			return;
		}
		
		int pivot = end;
		int i = start;
		int j = pivot - 1;

		while (i <= j) { 
			while (i<=end && arr[i]<=arr[pivot]) {
				i++;
			}

			while (j>=start &&arr[j]>=arr[pivot]) { 
				j--;
			}

			if(i>j){
				swap(arr, i, pivot);
			}
			else {
				swap(arr, i, j);
			}

			quick(arr, start, i - 1);
			quick(arr, i + 1, end);
		}
	}

	void swap(double* &A, int i, int j) {
		double temp;
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
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
	time_t seconds;
};

class MergeSort {
public:
	void print_time() const {
		cout << "MergeSort : " << seconds << " sec" << endl;
	}

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
	}

	void mergeSort(double*arr, int p,int r) {
		
		if (p < r) {
			int q = floor((p + r) / 2);
			mergeSort(arr, p, q);
			mergeSort(arr, q + 1, r);
			merge(arr,p,q,r);
		}
	}
	void run() {
		// sorting algorithm is applied
		// elapsed time is also recorded in seconds
		seconds = clock();
		mergeSort(arr, 0, size-1);
		seconds = clock() - seconds;
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
	time_t seconds;
};

class InsertionSort {
public:
	void print_time() const {
		cout << "InsertionSort : " << seconds << " sec" << endl;
	}

	// implement the following functions
	InsertionSort() {
		// constructor
	}

	~InsertionSort() {
		// destructor
	}

	void run() {
		// sorting algorithm is applied
		// elapsed time is also recorded in seconds

	}


	void set(double *arr, int size) {
		// new input array and its size are set

	}

private:
	double *arr;
	int size;
	time_t seconds;
};

class StoogeSort {
public:
	void print_time() const {
		cout << "StoogeSort : " << seconds << " sec" << endl;
	}

	// implement the following functions
	StoogeSort() {
		// constructor
	}

	~StoogeSort() {
		// destructor

	}

	void run() {
		// sorting algorithm is applied
		// elapsed time is also recorded are seconds

	}


	void set(double *arr, int size) {
		// new input array and its size are set

	}


private:
	double *arr;
	int size;
	time_t seconds;
};

class HeapSort {
public:
	void print_time() const {
		cout << "HeapSort : " << seconds << " sec" << endl;
	}

	// implement the following functions
	HeapSort() {
		// constructor
	}

	~HeapSort() {
		// destructor

	}

	void run() {
		// sorting algorithm is applied
		// elapsed time is also recorded are seconds

	}


	void set(double *arr, int size) {
		// new input array and its size are set

	}


private:
	double *arr;
	int size;
	time_t seconds;
};

#endif