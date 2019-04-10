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
	
	int pivot;


	// implement the following functions
	QuickSort() {
		// constructor
		size = 10;
		arr = new double[size];
		for (int i = 0;i < 10;i++) {
			arr[i] = i + 1;
		}
		
		seconds = 0;
	}

	~QuickSort() {
		// destructor
	}

	void run() {
		// sorting algorithm is applied
		// elapsed time is also recorded in seconds
		seconds = clock();



		seconds = clock() - seconds;
	}


	void set(double *arr, int size) {
		// new input array and its size are set
		this->size = size;
		this->arr = new double(size);


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
		for (int i = 0; i < size; i++) {
			cout << this->arr[i] << ", ";
		} 
		cout<<" "<< endl;
	}




	// implement the following functions
	MergeSort() {
		// constructor
		size = 10;
		arr = new double[size];
		for (int i = 0;i < size;i++) {
			arr[i] = (double)i + 1;
		}
		seconds = 0;
	}

	~MergeSort() {
		// destructor
		delete[] arr;

	}

	void run() {
		// sorting algorithm is applied
		// elapsed time is also recorded in seconds
		seconds = clock();

		this->q = floor((p + r) / 2);
		int n1=q-p+1;
		int n2=r-q;
		
		MergeSort* left = new MergeSort();
		MergeSort* right = new MergeSort();
		
		left->set(&arr[p,q], n1+1);
		right->set(&arr[q + 1, r], n2+1);
		left->arr[n1] = INFINITY;
		right->arr[n2] = INFINITY;

		if (p < r) {
			left->p = this->p;
			left->r = this->q;
			left->run();
			right->p = this->q+1;
			right->r = this->r;
			right->run();
		}

		int i = 0;
		int j = 0;
		for (int k = p; k < r; k++) {

			if (left->arr[i] <= right->arr[j]) {
				this->arr[k] = left->arr[i];
				i++;
			}
			else {
				this->arr[k] = right->arr[j];
				j++;
			}

		}
	
		seconds = clock() - seconds;

	}


	void set(double *arr, int size) {
		// new input array and its size are set
		this->size = size;
		this->arr = new double[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = arr[i];
		}
		p = 0;
		r = this->size-1;
		
	}

private:
	double *arr;
	int size;
	time_t seconds;
	int p;
	int r;
	int q;

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