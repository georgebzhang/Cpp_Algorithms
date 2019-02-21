#include <iostream>
#include <array>
#include <vector>

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

int main() {
	int test_arr[] = { 5, 1, 7, 2, 9, 3, 6 };
	int size = sizeof(test_arr) / sizeof(test_arr[0]);
	//std::array<int, 7> test_arr_std{ 5, 1, 7, 2, 9, 3, 6 };
	std::vector<int> test_vec{ 5, 1, 7, 2, 9, 3, 6 };

	print_arr(test_arr, size);
	//print_arr_std(test_arr_std);
	print_vec(test_vec);

	selection_sort_arr(test_arr, size);
	selection_sort_vec(test_vec);

	print_arr(test_arr, size);
	print_vec(test_vec);

	std::cin.get();
}