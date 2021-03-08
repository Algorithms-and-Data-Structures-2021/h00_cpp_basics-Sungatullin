#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if ((*lhs != 0) || (*rhs != 0)){
        int t = *lhs;
        *lhs = *rhs;
        *rhs = t;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if ((num_rows > 0) && (num_cols > 0)){
        int **arr = new int *[num_rows];
        for (int row_index = 0; row_index < num_rows; row_index++) {
            arr[row_index] = new int[num_cols];
        }
        for (int row_index = 0; row_index < num_rows; row_index++) {
            for (int column_index = 0; column_index < num_cols; column_index++) {
                arr[row_index][column_index] = init_value;
            }
        }
        return arr;
    }
    return nullptr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if ((num_rows > 0) && (num_cols > 0) && (arr_2d_source != nullptr) && (arr_2d_target != nullptr)){
        for (int i = 0; i < num_rows; i++){
            for (int j = 0; j < num_cols; j++){
                arr_2d_target[i][j] = arr_2d_source[i][j];
            }
        }
        return true;
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int i = 0; i < arr.size()/2; i++){
        int x = arr[i];
        arr[i] = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = x;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if ((arr_begin != nullptr) && (arr_end != nullptr)){
        int size_ = arr_end - arr_begin;
        for (int i = 0; i <= size_ / 2; i++){
            swap_args(arr_begin, arr_end);
            arr_begin++;
            arr_end--;
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if ((arr != nullptr) && (size > 0)){
        int *max;
        max = &arr[0];
        for (int i = 0; i < size; i++) {
            if (arr[i] > *max) {
                max = &arr[i];
            }
        }
        return max;
    }
    return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> odd_numbers;
    for (int & i : arr){
        if (abs(i % 2) == 1){
            odd_numbers.push_back(i);
        }
    }
    return odd_numbers;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> common_array;
    for (int i : arr_a){
        for (int j : arr_b){
            if (j == i){
                common_array.push_back(i);
            }
        }
    }
    return common_array;
}
