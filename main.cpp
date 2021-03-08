#include <iostream>
#include <vector>
#include <queue>
#include "Headers/sort.h"

using namespace std;


int main()
{
    Sorted sortAlgo;
    // int numbers_i[] = {1, 7, 6, 10, 9};
    // int numbers_i[] = {2, 1, 4, 3};
    int numbers_i[] = {4, 5, 3, 6, 2, 1};
    vector<int> numbers_v(numbers_i, numbers_i + 6);
    cout << "原始数据: " << numbers_v << endl << endl;

    vector<int> select = sortAlgo.selection_sort(numbers_v);
    cout << "选择排序: " << select << endl << endl;;

    vector<int> insert = sortAlgo.insert_sort(numbers_v);
    cout << "插入排序: " << insert << endl << endl;

    vector<int> bubble = sortAlgo.bubble_sort(numbers_v);
    cout << "冒泡排序: " << insert << endl << endl;
    
    vector<int> shell = sortAlgo.shell_sort(numbers_v);
    cout << "希尔排序: " << insert << endl << endl;
    
    vector<int> merge = sortAlgo.merge_sort(numbers_v);
    cout << "归并排序: " << merge << endl << endl;

    vector<int> quick = sortAlgo.quick_sort(numbers_v);
    cout << "快速排序: " << quick << endl << endl;

    cout << endl;
    system("pause");
    return 0;
}