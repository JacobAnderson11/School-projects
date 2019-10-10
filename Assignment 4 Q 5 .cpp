#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;
int numCompare;
int numSwap;

void ShellSort(vector <int>& num) {
	cout << "Starting shell sort: " << endl;
	int i, temp, flag = 1, numLength = num.size();
	int gap = numLength;
	bool insertionNeeded = false;
	int swapPos = 0;
	int key;

	while (true) {    // boolean flag (true when not equal to 0) 
		gap = (gap - 1) / 2;
		if (gap == 0)
			break;

		for (int k = 0; k < gap; k++) {
			for (int j = gap + k; j < numLength; j += gap) {
				key = num[j];

				insertionNeeded = false;
				for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right
					numCompare++;
					if (key < num[i]) {
						swapPos = i;
						num[i + gap] = num[i];
						insertionNeeded = true;
						numSwap++;
					}
					else
						break;
				}
				if (insertionNeeded) {
					num[swapPos] = key;    //Put key into its proper location
				}
			}
		}

	}
	cout << "The number of comparisons was: " << numCompare << endl;
	cout << "The number of swaps was: " << numSwap << endl;
	numCompare = 0;
	numSwap = 0;
	return;
}


void selection_sort(vector<int>& vec) {
	cout << "Starting selection sort: " << endl;
	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		
		for (int next = fill + 1; next != vec.size(); ++next) {
			numCompare++;
			if (vec[next] < vec[pos_min])
			{
				numSwap++;
				pos_min = next;
				
			}

		}
		if (fill != pos_min)
		{	
			swap(vec[pos_min], vec[fill]);
		}

	}
	cout << "The number of comparisons was: " << numCompare << endl;
	cout << "The number of swaps was: " << numSwap << endl;
	numCompare = 0;
	numSwap = 0;
}

void bubble_sort_improved(vector <int>& vec) {
	cout << "Starting bubble sort plus: " << endl;
	bool exchanges = false;
	for (int i = 1; i <= vec.size(); i++) {
		exchanges = false;
		for (int j = 0; j < vec.size() - i; j++) {
			numCompare++;
			if (vec[j + 1] < vec[j]) {
				numSwap++;
				swap(vec[j], vec[j + 1]);// swap elements
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
	cout << "The number of comparisons was: " << numCompare << endl;
	cout << "The number of swaps was: " << numSwap << endl;
	numCompare = 0;
	numSwap = 0;
}

void insertion_sort(vector <int>& num) {
	cout << "Starting insertion sort: " << endl;
	int i, j, key;
	bool insertionNeeded = false;

	for (j = 1; j < num.size(); j++) {
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--) { // larger values move right
			numCompare++;
			if (key < num[i]) {
				numSwap++;
				num[i + 1] = num[i];
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key;    //Put key into its proper location
	}
	cout << "The number of comparisons was: " << numCompare << endl;
	cout << "The number of swaps was: " << numSwap << endl;
	numCompare = 0;
	numSwap = 0;
}


void merge(vector<int>& array, vector<int>& result, int lowPointer, int highPointer, int upperBound) {

	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items

	while (lowPointer <= mid && highPointer <= upperBound) {
		numCompare++;
		if (array[lowPointer] < array[highPointer])
			result[j++] = array[lowPointer++];
		else
			result[j++] = array[highPointer++];
	}

	while (lowPointer <= mid)
	{
		numSwap++;
		result[j++] = array[lowPointer++];
	}

	while (highPointer <= upperBound)
	{
		numSwap++;
		result[j++] = array[highPointer++];
	}

	for (j = 0; j < n; j++) //copy the items from the temporary array to the original array
		array[lowerBound + j] = result[j];
}

void mergesort(vector<int>& array, vector<int>& result, int lowerBand, int upperBand) {
	int midpoint;
	if (lowerBand < upperBand) {
		midpoint = (lowerBand + upperBand) / 2;
		mergesort(array, result, lowerBand, midpoint); //merge sort the left half
		mergesort(array, result, midpoint + 1, upperBand); //merge sort the right half
		merge(array, result, lowerBand, midpoint + 1, upperBand);
	}
}

void mergeSort(vector<int>& array) {
	cout << "Starting Merge sort: " << endl;
	vector<int> result = array;
	mergesort(array, result, 0, array.size() - 1);
	cout << "The number of comparisons was: " << numCompare << endl;
	cout << "The number of swaps was: " << numSwap << endl;
	numCompare = 0;
	numSwap = 0;
}

int partition(int first, int last, vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.
	int up = first + 1;
	int down = last - 1;
	do {
		numCompare++;
		while ((up != last) && !(arr[first] < arr[up])) {
			++up;
		}
		while (arr[first] < arr[down]) {
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
			numSwap++;
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[down], arr[first]);
	return down;
}

void sort_median(vector<int>& arr, int first, int last) {

	bool exchanges = true;
	int middle = (first + last) / 2;
	if (arr[first] > arr[middle])
		swap(arr[first], arr[middle]), numCompare++;
	if (arr[middle] > arr[last])
		swap(arr[middle], arr[last]), numCompare++;
	if (arr[first] > arr[middle])
		swap(arr[first], arr[middle]), numCompare++ ;


	//swap the middle with the left 
	swap(arr[middle], arr[first]);
}

int partitionB(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.


	int up = first + 1;
	int down = last - 1;
	sort_median(arr, first, last - 1);
	int mid = first;
	do {
		numCompare++;
		while ((up != last - 1) && !(arr[mid] < arr[up])) {
			++up;
		}
		while (arr[mid] < arr[down]) {
			--down;
		}
		if (up < down) {
			numSwap++;
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[mid], arr[down]);

	return down;
}

void middle_quick_sort(int first, int last, std::vector<int>& arr) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partitionB(first, last, arr);

		// Sort the left half.
		middle_quick_sort(first, pivot, arr);

		// Sort the right half.
		middle_quick_sort(pivot + 1, last, arr);
	}
}

void middle_quick_sort_wrapper(vector<int>& arr) {
	cout << "Starting quick sort Plus: " << endl;
	middle_quick_sort(0, arr.size(), arr);
	cout << "The number of comparisons was: " << numCompare << endl;
	cout << "The number of swaps was: " << numSwap << endl;
	numCompare = 0;
	numSwap = 0;
}

void quick_sort(int first, int last, std::vector<int>& arr) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partition(first, last, arr);

		// Sort the left subarray.
		quick_sort(first, pivot, arr);

		// Sort the right subarray.
		quick_sort(pivot + 1, last, arr);
	}
}

void quick_sort_wrapper(vector<int>& arr) {
	cout << "Startng quick sort: " << endl;
	quick_sort(0, arr.size(), arr);
	cout << "The number of comparisons was: " << numCompare << endl;
	cout << "The number of swaps was: " << numSwap << endl;
	numCompare = 0;
	numSwap = 0;
}


vector<int> random_vector(size_t size) {
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(rand() % size); //put a random number between 0 and size
	return v1;
}

vector<int> sorted_vector(size_t size) {
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(i);
	return v1;
}

vector<int> reversed_vector(size_t size) {
	vector<int> v1;
	for (int i = size - 1; i >= 0; i--)
		v1.push_back(i);
	return v1;
}

int main() {

	cout << "Ascending vectors : " << endl;
	vector<int> v1 = sorted_vector(1000);
	bubble_sort_improved(v1);

	v1 = sorted_vector(1000);
	selection_sort(v1);

	v1 = sorted_vector(1000);
	insertion_sort(v1);

	v1 = sorted_vector(1000);
	ShellSort(v1);

	v1 = sorted_vector(1000);
	mergeSort(v1);

	v1 = sorted_vector(1000);
	quick_sort_wrapper(v1);

	v1 = sorted_vector(1000);
	middle_quick_sort_wrapper(v1);

	cout << "Decending vectors : " << endl;

	v1 = reversed_vector(1000);
	bubble_sort_improved(v1);

	v1 = reversed_vector(1000);
	selection_sort(v1);

	v1 = reversed_vector(1000);
	insertion_sort(v1);

	v1 = reversed_vector(1000);
	ShellSort(v1);

	v1 = reversed_vector(1000);
	mergeSort(v1);

	v1 = reversed_vector(1000);
	quick_sort_wrapper(v1);

	v1 = reversed_vector(1000);
	middle_quick_sort_wrapper(v1);
	
	cout << "Random vectors : " << endl;

	v1 = random_vector(1000);
	bubble_sort_improved(v1);

	v1 = random_vector(1000);
	selection_sort(v1);

	v1 = random_vector(1000);
	insertion_sort(v1);

	v1 = random_vector(1000);
	ShellSort(v1);

	v1 = random_vector(1000);
	mergeSort(v1);

	v1 = random_vector(1000);
	quick_sort_wrapper(v1);

	v1 = random_vector(1000);
	middle_quick_sort_wrapper(v1);

	return 0;
}
