#include <vector>
#include "../Headers/sort.h"

std::ostream & operator<<(std::ostream &out, std::vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl;
    return out;
}

std::vector<int> Sorted::copy(std::vector<int> &numbers) {
    std::vector<int> numbers_copy(numbers.size());
    for (int i = 0; i < numbers.size(); i++) {
        numbers_copy[i] = numbers[i];
    }
    return numbers_copy;
}

void Sorted::exch(std::vector<int> &numbers, int a, int b) {
    int flag = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = flag;
}

bool Sorted::less(int a, int b) {
    return a < b;
}

std::vector<int> Sorted::selection_sort(std::vector<int> numbers) {
    for (int i = 0; this->less(i, numbers.size()-1); i++) {
        int min = i;
        for (int j = i+1; this->less(j, numbers.size()); j++) {
            if (this->less(numbers[j], numbers[min])) {
                min = j;
            }
        }
        if (min != i) this->exch(numbers, i, min);
        std::cout << "第" << i << "次排序: " << numbers << std::endl;
    }
    return numbers;
}

std::vector<int> Sorted::insert_sort(std::vector<int> numbers) {
    for (int i = 0; i < numbers.size()-1; i++) {
        for (int j = i+1; j > 0; j--) {
            if (numbers[j] < numbers[j-1]) {
                int flag = numbers[j];
                numbers[j] = numbers[j-1];
                numbers[j-1] = flag;
            }
        }
        std::cout << "第" << i << "次排序: " << numbers << std::endl;
    }
    return numbers;
}

std::vector<int> Sorted::bubble_sort(std::vector<int> numbers) {
    for (int i = 0; i < numbers.size()-1; i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            if (numbers[i] > numbers[j]) {
                int flag = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = flag;
            }
        }
        std::cout << "第" << i << "次排序: " << numbers << std::endl;
    }
    return numbers;
}

std::vector<int> Sorted::shell_sort(std::vector<int> numbers) {
    int h = 1;

    while (h < numbers.size()/3) 
        h = 3*h + 1;
    while (h >= 1) {
        for (int i = h; i < numbers.size(); i++) {
            for (int j = i; j >= h && numbers[j] < numbers[j-h]; j -= h) {
                int flag = numbers[j];
                numbers[j] = numbers[j-h];
                numbers[j-h] = flag;
            }
            std::cout << "第" << h << "次排序: " << numbers << std::endl;
        }
        h = h/3;
    }
    return numbers;
}

void Sorted::merge_sort(std::vector<int> &a, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;

    std::vector<int> aux(a.size());
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    for (int k = lo; k <= hi; k++) {
        if      (i > mid)           a[k] = aux[j++];
        else if (j > hi)            a[k] = aux[i++];
        else if (aux[j] < aux[i])   a[k] = aux[j++];
        else                        a[k] = aux[i++];
    }
}

void Sorted::merge_sort(std::vector<int> &numbers, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(numbers, lo, mid);
    merge_sort(numbers, mid + 1, hi);
    merge_sort(numbers, lo, mid, hi);
    std::cout << "排序: " << numbers << std::endl;
}

std::vector<int> Sorted::merge_sort(std::vector<int> numbers) {
    std::vector<int> numbers_copy = copy(numbers);
    merge_sort(numbers_copy, 0, numbers_copy.size() - 1);
    return numbers_copy;
}

int Sorted::quick_partition(std::vector<int> &numbers, int lo, int hi) {
    int i = lo, j = hi + 1;
    int flag = numbers[lo];
    while (1) {
        while (this->less(numbers[++i], flag)) if (i == hi) break;
        while (this->less(flag, numbers[--j])) if (j == lo) break;
        if (i >= j) break;
        this->exch(numbers, i, j);
    }
    this->exch(numbers, lo, j);
    return j;
}

void Sorted::quick_sort(std::vector<int> &numbers, int lo, int hi) {
    if (lo >= hi) return;
    int j = quick_partition(numbers, lo, hi);
    quick_sort(numbers, lo, j - 1);
    quick_sort(numbers, j + 1, hi);
}

std::vector<int> Sorted::quick_sort(std::vector<int> numbers) {
    std::vector<int> numbers_copy = copy(numbers);
    quick_sort(numbers_copy, 0, numbers_copy.size() - 1);
    return numbers_copy;
}
