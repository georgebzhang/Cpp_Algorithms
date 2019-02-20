#include <iostream>
#include <vector>

void print_arr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void print_vec(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int find_ind_min_arr(int* arr, int size) {
	int ind_min = 0;
	int val_min = arr[0];
	for (int i = 0; i < size; ++i) {
		if (arr[i] < val_min) {
			val_min = arr[i];
			ind_min = i;
		}
	}
	return ind_min;
}

int find_ind_min_vec(std::vector<int>& vec) {
	int ind_min = 0;
	int val_min = vec[0];
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] < val_min) {
			val_min = vec[i];
			ind_min = i;
		}
	}
	return ind_min;
}

void selection_sort_arr(int* arr, int size) {
	int ind_min;
	for (int i = 0; i < size; ++i) {
		ind_min = find_ind_min_arr(&arr[i], size - i) + i; // (&arr[i], size - i) means we are passing a subarray of arr from indices i -> size
		swap(arr[i], arr[ind_min]);
	}
}

void selection_sort_vec(std::vector<int>& vec) {
	int ind_min;
	for (int i = 0; i < vec.size(); ++i) {
		std::vector<int> sub_vec = vec
		ind_min = find_ind_min_vec(vec)
	}
}

int main() {
	int test_arr[] = { 5, 1, 7, 2, 9, 3, 6 };
	int size = sizeof(test_arr) / sizeof(test_arr[0]);

	std::vector<int> test_vec{ 5, 1, 7, 2, 9, 3, 6 };

	print_arr(test_arr, size);
	print_vec(test_vec);

	selection_sort_arr(test_arr, size);


	print_arr(test_arr, size);

	while (1);
}