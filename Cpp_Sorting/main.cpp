#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

void print_arr(const int* const arr, const int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T, size_t N>
void print_arr_std(const std::array<T, N>& const arr_std) {
	for (int i = 0; i < N; ++i) { // N or arr_std.size()
		std::cout << arr_std[i] << " ";
	}
	std::cout << std::endl;
}

void print_vec(const std::vector<int>& const vec) {
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

int find_ind_min_arr(const int* const arr, const int size) {
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

//template<typename T, size_t N>
//int find_ind_min_arr_std(const std::array<T, N>& const arr_std) {
//	int ind_min = 0;
//	int val_min = arr_std[0];
//	for (int i = 0; i < N; ++i) {
//		if (arr_std[i] < val_min) {
//			val_min = arr_std[i];
//			ind_min = i;
//		}
//	}
//	return ind_min;
//}

int find_ind_min_vec(const std::vector<int>::iterator vec_begin, const std::vector<int>::iterator vec_end) {
	int ind_min = 0;
	int val_min = *vec_begin;
	int i = 0;
	for (std::vector<int>::iterator it = vec_begin; it != vec_end; ++it) {
		if (*it < val_min) {
			val_min = *it;
			ind_min = i;
		}
		++i;
	}
	return ind_min;
}

void selection_sort_arr(int* arr, const int size) {
	int ind_min;
	for (int i = 0; i < size; ++i) {
		ind_min = find_ind_min_arr(&arr[i], size - i) + i; // (&arr[i], size - i) means we are passing a subarray of arr from indices i -> size
		swap(arr[i], arr[ind_min]);
	}
}

void selection_sort_vec(std::vector<int>& vec) {
	int ind_min;
	for (int i = 0; i < vec.size(); ++i) {
		ind_min = find_ind_min_vec(vec.begin() + i, vec.end()) + i;
		swap(vec[i], vec[ind_min]);
	}
}

void insertion_sort_arr(int* arr, int size) {
	int ind_last_sorted = 0;
	for (int i = 1; i < size; ++i) {
		for (int j = ind_last_sorted; j >= 0; --j) {
			int ind_new = i - (ind_last_sorted - j);
			if (arr[ind_new] < arr[j]) {
				swap(arr[j], arr[ind_new]);
			}
		}
		++ind_last_sorted;
	}
}

void insertion_sort_vec(std::vector<int>& vec) {
	int ind_last_sorted = 0;
	for (int i = 1; i < vec.size(); ++i) {
		for (int j = ind_last_sorted; j >= 0; --j) {
			int ind_new = i - (ind_last_sorted - j);
			if (vec[ind_new] < vec[j]) {
				swap(vec[ind_new], vec[j]);
			}
		}
		++ind_last_sorted;
	}
}

void bubble_sort_arr(int* arr, int size) {
	int ind_last_sorted = size;
	bool is_sorted = false;
	while (!is_sorted) {
		is_sorted = true;
		for (int i = 0; i < ind_last_sorted - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				is_sorted = false;
			}
		}
		--ind_last_sorted;
	}
}

void bubble_sort_vec(std::vector<int>& vec) {
	int ind_last_sorted = vec.size();
	bool is_sorted = false;
	while (!is_sorted) {
		is_sorted = true;
		for (int i = 0; i < ind_last_sorted - 1; ++i) {
			if (vec[i] > vec[i + 1]) {
				swap(vec[i], vec[i + 1]);
				is_sorted = false;
			}
		}
		--ind_last_sorted;
	}
}

void merge_arr(int* arr, int* left, int* right, int size) {
	int ind_left = 0;
	int ind_right = 0;
	int ind_arr = 0;
	int size_left = size / 2;
	int size_right = size - size_left;
	while (ind_left < size_left && ind_right < size_right) {
		if (left[ind_left] < right[ind_right]) {
			arr[ind_arr] = left[ind_left];
			++ind_left;
		}
		else {
			arr[ind_arr] = right[ind_right];
			++ind_right;
		}
		++ind_arr;
	}
	while (ind_left < size_left) {
		arr[ind_arr] = left[ind_left];
		++ind_left;
		++ind_arr;
	}
	while (ind_right < size_right) {
		arr[ind_arr] = right[ind_right];
		++ind_right;
		++ind_arr;
	}
}

void merge_sort_arr(int* arr, int size) {
	if (size < 2)
		return;
	int size_left = size / 2;
	int size_right = size - size_left;
	int* left = new int[size_left];
	int* right = new int[size_right];
	std::copy(arr, arr + size_left, left);
	std::copy(arr + size_left, arr + size, right);

	merge_sort_arr(left, size_left);
	merge_sort_arr(right, size_right);
	merge_arr(arr, left, right, size);

	delete[] left;
	delete[] right;
}

void merge_vec(std::vector<int>& vec, std::vector<int>& left, std::vector<int>& right) {
	int ind_left = 0;
	int ind_right = 0;
	int ind_vec = 0;
	while (ind_left < left.size() && ind_right < right.size()) {
		if (left[ind_left] < right[ind_right]) {
			vec[ind_vec] = left[ind_left];
			++ind_left;
		}
		else {
			vec[ind_vec] = right[ind_right];
			++ind_right;
		}
		++ind_vec;
	}
	while (ind_left < left.size()) {
		vec[ind_vec] = left[ind_left];
		++ind_left;
		++ind_vec;
	}
	while (ind_right < right.size()) {
		vec[ind_vec] = right[ind_right];
		++ind_right;
		++ind_vec;
	}
}

void merge_sort_vec(std::vector<int>& vec) {
	int size = vec.size();
	if (size < 2)
		return;
	int size_left = vec.size() / 2;
	int size_right = size - size_left;
	std::vector<int> left, right;
	left.assign(vec.begin(), vec.begin() + size_left); // merge sort is not in-place
	right.assign(vec.begin() + size_left, vec.end());
	merge_sort_vec(left);
	merge_sort_vec(right);
	merge_vec(vec, left, right);
}

int partition_arr(int* arr, int size, int ind_low, int ind_high) {
	int ind_pivot = ind_high;
	int val_pivot = arr[ind_pivot];
	int ind_partition = ind_low;
	for (int i = ind_low; i < ind_high; ++i) { // from ind_low -> ind_high - 1 (don't want to reach ind_pivot = ind_high)
		if (arr[i] < val_pivot) {
			swap(arr[ind_partition], arr[i]);
			++ind_partition;
		}
	}
	swap(arr[ind_partition], arr[ind_pivot]);
	return ind_partition;
}

int partition_rand_arr(int* arr, int size, int ind_low, int ind_high) {
	int ind_pivot = rand() % size + ind_low; // random int from ind_low -> ind_high
	swap(arr[ind_high], arr[ind_pivot]);
	return partition_arr(arr, size, ind_low, ind_high);
}

void quick_sort_arr_helper(int* arr, int size, int ind_low, int ind_high) {
	if (ind_low < ind_high) {
		int ind_partition = partition_rand_arr(arr, size, ind_low, ind_high);
		int size_left = ind_partition - ind_low;
		int size_right = size - size_left - 1;
		quick_sort_arr_helper(arr, size_left, ind_low, ind_partition - 1);
		quick_sort_arr_helper(arr, size_right, ind_partition + 1, ind_high);
	}
}

void quick_sort_arr(int* arr, int size) {
	quick_sort_arr_helper(arr, size, 0, size - 1);
}

int main() {
	srand(69);

	int test_arr[] = { 5, 27, 1, 7, -1, 2, 27, 9, 7, 3, 6 };
	int size = sizeof(test_arr) / sizeof(test_arr[0]);
	//std::array<int, 7> test_arr_std{ 5, 1, 7, 2, 9, 3, 6 };
	std::vector<int> test_vec{ 5, 1, 7, 2, 9, 3, 6 };

	print_arr(test_arr, size);
	//print_arr_std(test_arr_std);
	print_vec(test_vec);

	quick_sort_arr(test_arr, size);
	//quick_sort_vec(test_vec);

	print_arr(test_arr, size);
	print_vec(test_vec);

	std::cin.get();
}