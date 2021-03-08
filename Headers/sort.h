#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <vector>

std::ostream & operator<<(std::ostream &out, std::vector<int> numbers);

class Sorted {
private:
    std::vector<int> copy(std::vector<int> &numbers);
    void exch(std::vector<int> &numbers, int a, int b);
    bool less(int a, int b);
    void merge_sort(std::vector<int> &a, int lo, int mid, int hi);
    void merge_sort(std::vector<int> &numbers, int lo, int hi);
    int quick_partition(std::vector<int> &numbers, int lo, int hi);
    void quick_sort(std::vector<int> &numbers, int lo, int hi);
public:
    std::vector<int> selection_sort(std::vector<int> numbers);  // 选择排序
    std::vector<int> insert_sort(std::vector<int> numbers);     // 插入排序
    std::vector<int> bubble_sort(std::vector<int> numbers);     // 冒泡排序
    std::vector<int> shell_sort(std::vector<int> numbers);      // 希尔排序
    std::vector<int> merge_sort(std::vector<int> numbers);      // 归并排序
    std::vector<int> quick_sort(std::vector<int> numbers);      // 快速排序
    
};

#endif // SORT_H_