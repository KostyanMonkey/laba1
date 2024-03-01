﻿#include <iostream>
#include <vector>

/*
Необходимо реализовать 3 любые сортировки массивов на выбор(обязательно - Quick Sort с рандомизированным выбором pivot элемента, 
следующие по выбору - Bubble Sort, Counting Sort, Bucket Sort, Insertion sort, Timsort, Selection sort, Merge sort, Radix sort, etc.) 
с использованием шаблонов.

Дедлайн - 1.03.24 23:59

При корректной реализации 3 сортировок ставится оценка 9. При корректной реализации 2

сортировок ставится оценка 6. При корректной реализации 1 сортировки ставится оценка 3.

Для получения оценки 10 необходимо подготовить отчёт, в котором будут произведены замеры времени работы ваших 
сортировок на массивах различных размеров(10,1000,1000000 и тд элементов). 
Как найти время? Пример приведён ниже, можно использовать любые другие инструменты, известные вам, найденные в литературе и тд.
Отчёт можно представить в excel, ipynb и тд. В отчёт, например, можно построить графики зависимости времени работы алгоритмов от количества
элементов в массиве.

Выполняется индивидуально.
*/



template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void BubbleSort(T& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j]) Swap(arr[i], arr[j]);
            
        }
    }
}


double Max(std::vector<double> a)
{
    double maximum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > maximum) maximum = a[i];
       
    }
    return maximum + 1;
}

template <typename T>
T CountingSort(T a)
{
    std::vector<double> indexis(Max(a));
    T output;
    for (int i = 0; i < a.size(); i++)
    {
        indexis[a[i]]++;
    }
    for (int i = 0; i < indexis.size(); i++)
    {   
        
        for (int j = 0; j < indexis[i]; j++)
        {
            output.push_back(i);
        }
    }
    return output;
}

template <typename T>
double RandPivot(T& a, int start, int end)
{
    Swap(a[rand() % (end - start + 1) + start], a[end]);
    return a[end];
}


template <typename T>
void QuickSort(T& a, int start, int end) 
{
    if (start < end) 
    {
        int pivot = RandPivot(a, start, end);
        int i = start - 1;

        for (int j = start; j < end; j++) 
        {
            if (a[j] < pivot) 
            {
                i++;
                Swap(a[i], a[j]);
            }
        }

        Swap(a[i + 1], a[end]);
        int pindex = i + 1;

        QuickSort(a, start, pindex - 1);
        QuickSort(a, pindex + 1, end);
    }
}


template <typename T>
void Create(T& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = rand() % 10;
    }
}

template <typename T>
void Print(T a)
{
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
}


int main() 
{
    srand(time(NULL));
    int n = 0;
    std::cin >> n;
    std::vector <double> arr(n);
    
    Create(arr);
    std::cout << "Not sorted" << std::endl;
    Print(arr);
    BubbleSort(arr);
    std::cout << std::endl << "Bubble Sort" << std::endl;
    Print(arr);

    Create(arr);
    std::cout << std::endl << "Not sorted" << std::endl;
    Print(arr);

    
    std::cout << std::endl << "Counting Sort" << std::endl;
    Print(CountingSort(arr));

    Create(arr);
    std::cout << std::endl << "Not sorted" << std::endl;
    Print(arr);
    std::cout << std::endl << "QuickSort" << std::endl;
    QuickSort(arr, 0, arr.size() - 1);
    Print(arr);
    

    return 0;
}



