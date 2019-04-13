#include <iostream>
#include "Sort.h"

using namespace std;

bool check_quick(QuickSort *quick_sort) {
	// check the result of quick sort algorithm
	int checkIndex=0;
	for (int i = 0; i < quick_sort->size-1; i++) {
		checkIndex += (quick_sort->arr[i + 1] - quick_sort->arr[i]>=0)?0:1;
	}
	return checkIndex==0?true:false;
}
bool check_merge(MergeSort *merge_sort) {
	// check the result of merge sort algorithm
	int checkIndex = 0;
	for (int i = 0; i < merge_sort->size - 1; i++) {
		checkIndex += (merge_sort->arr[i + 1] - merge_sort->arr[i] >= 0) ? 0 : 1;
	}
	return checkIndex == 0 ? true : false;
}

bool check_insertion(InsertionSort *insertion_sort) {
	// check the result of insertion sort algorithm
	int checkIndex = 0;
	for (int i = 0; i < insertion_sort->size - 1; i++) {
		checkIndex += (insertion_sort->arr[i + 1] - insertion_sort->arr[i] >= 0) ? 0 : 1;
	}
	return checkIndex == 0 ? true : false;
}

bool check_stooge(StoogeSort *stooge_sort) {
	// check the result of stooge sort algorithm
	int checkIndex = 0;
	for (int i = 0; i < stooge_sort->size - 1; i++) {
		checkIndex += (stooge_sort->arr[i + 1] - stooge_sort->arr[i] >= 0) ? 0 : 1;
	}
	return checkIndex == 0 ? true : false;
}

bool check_heap(HeapSort *heap_sort) {
	// check the result of heap sort algorithm
	int checkIndex = 0;
	for (int i = 0; i < heap_sort->size - 1; i++) {
		checkIndex += (heap_sort->arr[i + 1] - heap_sort->arr[i] >= 0) ? 0 : 1;
	}
	return checkIndex == 0 ? true : false;
}

int main(int argc, char *argv[]) {
	double *input_array;
	int n;
	cin >> n;
	
	input_array = new double[n];
	for (int i = 0;i < n;i++) {
		input_array[i] = (double)(rand() % 10000);
	}
	// QuickSort
	QuickSort *quick_sort = new QuickSort();
	
	quick_sort->set(input_array, n);
	quick_sort->run();
	quick_sort->print_time();

	if (check_quick(quick_sort)) {
		cout << "QuickSort is validated" << endl << endl;
	}
	delete quick_sort;


	// MergeSort
	MergeSort *merge_sort = new MergeSort();
	merge_sort->set(input_array, n);
	merge_sort->run();
	merge_sort->print_time();

	if (check_merge(merge_sort)) {
		cout << "MergeSort is validated" << endl << endl;
	}
	delete merge_sort;


	// InsertionSort
	InsertionSort *insertion_sort = new InsertionSort();
	insertion_sort->set(input_array, n);
	insertion_sort->run();
	insertion_sort->print_time();

	if (check_insertion(insertion_sort)) {
		cout << "InsertionSort is validated" << endl << endl;
	}
	delete insertion_sort;


	// StoogeSort
	StoogeSort *stooge_sort = new StoogeSort();
	stooge_sort->set(input_array, n);
	stooge_sort->run();
	stooge_sort->print_time();
	if (check_stooge(stooge_sort)) {
		cout << "StoogeSort is validated" << endl<<endl;
	}
	delete stooge_sort;
	

	// HeapSort
	HeapSort *heap_sort = new HeapSort();
	heap_sort->set(input_array, n);
	heap_sort->run();
	heap_sort->print_time();

	if (check_heap(heap_sort)) {
		cout << "HeapSort is validated" << endl;
	}
	delete heap_sort;

	delete[] input_array;
	return 0;
}