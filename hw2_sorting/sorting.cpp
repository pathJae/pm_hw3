#include <iostream>
#include "Sort.h"

using namespace std;

bool check_quick(QuickSort *quick_sort) {
	// check the result of quick sort algorithm

	return true;
}
bool check_merge(MergeSort *merge_sort) {
	// check the result of merge sort algorithm
	return true;
}

bool check_insertion(InsertionSort *insertion_sort) {
	// check the result of insertion sort algorithm
	return true;
}

bool check_stooge(StoogeSort *stooge_sort) {
	// check the result of stooge sort algorithm
	return true;
}

bool check_heap(HeapSort *heap_sort) {
	// check the result of heap sort algorithm
	return true;
}

int main(int argc, char *argv[]) {
	double *input_array;
	int n;
	cin >> n;
	
	// implement here
	// generate random numbers and apply each sorting algorithms
	input_array = new double[n];

	for (int i = 0;i < n;i++) {
		input_array[i] = (double)(rand() % 10000);
		//nput_array[i] =-i+n;
	}
	// QuickSort

	QuickSort *quick_sort = new QuickSort();
	// implement here
	
	quick_sort->set(input_array, n);
	quick_sort->run();
	quick_sort->print_time();

	if (check_quick(quick_sort)) {
		cout << "QuickSort is validated" << endl << endl;
	}
	delete quick_sort;


	// MergeSort
	MergeSort *merge_sort = new MergeSort();
	// implement here
	
	merge_sort->set(input_array, n);
	merge_sort->run();
	merge_sort->print_time();

	if (check_merge(merge_sort)) {
		cout << "MergeSort is validated" << endl << endl;
	}
	delete merge_sort;


	// InsertionSort
	InsertionSort *insertion_sort = new InsertionSort();
	// implement here


	if (check_insertion(insertion_sort)) {
		cout << "InsertionSort is validated" << endl << endl;
	}
	delete insertion_sort;

	// StoogeSort
	StoogeSort *stooge_sort = new StoogeSort();
	// implement here

	if (check_stooge(stooge_sort)) {
		cout << "StoogeSort is validated" << endl;
	}
	delete stooge_sort;


	// HeapSort
	HeapSort *heap_sort = new HeapSort();
	// implement here

	if (check_heap(heap_sort)) {
		cout << "HeapSort is validated" << endl;
	}
	delete heap_sort;


	return 0;
}