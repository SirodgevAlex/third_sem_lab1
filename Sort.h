#pragma once

#include <iostream>
#include "Sequence.h"
#include "Map.h"
#include <map>
#include "Tree.h"
#include <vector>
#include <chrono>

using namespace std;

template<class T>
bool asc(T a, T b) { //по неубыванию
    return a <= b;
}

template<class T>
bool desc(T a, T b) { //по невозрастанию
    return a >= b;
}

template<class T>
void Swap(Sequence<T> *sequence, int i, int g) {
    T tmp = sequence->Get(i);
    sequence->Set(sequence->Get(g), i);
    sequence->Set(tmp, g);
}

template<class T>
Sequence<T> *BubbleSort(Sequence<T> *sequence, bool (*compare)(T, T)) {
    if (sequence->GetSize() <= 1) return sequence;
    int size = sequence->GetSize();
    for (int i = 0; i < size; i++) {
        for (int g = i + 1; g < size; g++) { //если с i + 1 начать, то в теории немного асимптотику улучшим
            if (compare(sequence->Get(g), sequence->Get(i)) == 1) {
                Swap(sequence, i, g);
            }
        }
    }
    return sequence;
}

template<class T>
Sequence<T> *CocktailSort(Sequence<T> *sequence, bool (*compare)(T, T)) {
    //if (sequence->GetSize() <= 1) return;
    int size = sequence->GetSize();
    int left = 0;
    int right = size - 1;
    int control = size - 1;
    do { //потестить
        for (int i = left; i < right; i++) {
            if (compare(sequence->Get(i + 1), sequence->Get(i)) == 1) {
                Swap(sequence, i, i + 1);
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (compare(sequence->Get(i), sequence->Get(i - 1)) == 1) {
                Swap(sequence, i, i - 1);
                control = i;
            }
        }
        left = control;
    } while (left < right);
    return sequence;
}

template<class T>
Sequence<T> *InsertionSort(Sequence<T> *sequence, bool (*compare)(T, T)) {
    if (sequence->GetSize() <= 1) return sequence;
    int size = sequence->GetSize();
    for (int i = 1; i < size; i++) {
        T tmp = sequence->Get(i);
        int g = i;
        while ((g > 0) and (compare(tmp, sequence->Get(g - 1)) == 1)) {
            sequence->Set(sequence->Get(g - 1), g);
            g--;
        }
        sequence->Set(tmp, g);
    }
    return sequence;
}
//O(n^2)

template<class T>
Sequence<T> *SelectionSort(Sequence<T> *sequence, bool (*compare)(T, T)) {
    if (sequence->GetSize() <= 1) return sequence;
    int size = sequence->GetSize();
    for (int i = 0; i < size - 1; i++) {
        int MinIndex = i;
        for (int g = i + 1; g < size; g++) {
            if (compare(sequence->Get(g), sequence->Get(MinIndex))) {
                MinIndex = g;
            }
        }
        if (MinIndex != i) {
            Swap(sequence, MinIndex, i);
        }
    }
    return sequence;
}
// O(n^2)

template<class T>
Sequence<T> *CountingSort(Sequence<T> *sequence, bool (*compare)(T, T)) {
    map<T, int> m;
    int size = sequence->GetSize();
    for (int i = 0; i < size; i++) {
        ++m[sequence->Get(i)];
    }
    typename map<T, int>::iterator it = m.begin();
    int counter = 0;
    if (compare(1, 2) == asc(1, 2))
        for (int i = 0; it != m.end(); it++) {
            while (it->second != 0) {
                sequence->Set(it->first, counter);
                counter++;
                it->second--;
            }
        }
    else {
        it = m.end();
        it--;
        for (int i = 0; it != m.end(); it--) {
            while (it->second != 0) {
                sequence->Set(it->first, counter);
                counter++;
                it->second--;
            }
        }
    }
    return sequence;
}

template<typename T>
int BinarySearch(Sequence<T> *sequence, T data, bool (*compare)(T, T)) {
    int l = -1;
    int r = sequence->GetSize();
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (compare(data, sequence->Get(mid)) == 1) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
//    if (compare(1, 2) == asc(1, 2)) return r;
//    else return l;
}

template<class T>
Sequence<T> *BinaryInsertionSort(Sequence<T> *sequence, bool (*compare)(T, T)) {
    int size = sequence->GetSize();
    ArraySequence<T> *newSequence = new ArraySequence<T>();
    for (int i = 0; i < size; i++) {
        int pos = BinarySearch(newSequence, sequence->Get(i), compare);
        if (newSequence->GetSize() == 0) {
            newSequence->Append(sequence->Get(i));
        } else {
            newSequence->InsertAt(sequence->Get(i), pos);
        }
    }
    for (int i = 0; i < size; i++) {
        sequence->Set(newSequence->Get(i), i);
    }
    delete newSequence;
    return sequence;
}

template<class T>
Sequence<T> *QuickSort(Sequence<T> *sequence, int first, int last, bool (*compare)(T, T)) {
    int l = first, r = last;
    T mid = sequence->Get((first + last) / 2);
    do {
        while (compare(mid, sequence->Get(l)) == 0) {
            l++;
        }
        while (compare(sequence->Get(r), mid) == 0) {
            r--;
        }
        if (l <= r) {
            if (compare(sequence->Get(l), sequence->Get(r)) == 0) {
                Swap(sequence, l, r);
            }
            l++;
            r--;
        }
    } while (l <= r);
    if (l < last) {
        QuickSort(sequence, l, last, compare);
    }
    if (first < r) {
        QuickSort(sequence, first, r, compare);
    }
    return sequence;
}

template<class T>
Sequence<T> *ShellSort(Sequence<T> *sequence, bool (*compare)(T, T)) {
    int size = sequence->GetSize();
    for (int i = size / 2; i > 0; i--) {
        for (int g = i; g < size; g++) {
            for (int k = g - i; k >= 0 && compare(sequence->Get(k + i), sequence->Get(k)) == 1; k -= i) {
                T cur = sequence->Get(k);
                sequence->Set(sequence->Get(k + i), k);
                sequence->Set(cur, k + i);
            }
        }
    }
    return sequence;
}

template<class T>
vector<std::chrono::duration<double>>
*SortTimes(Sequence<T> *AuxiliarySequence, vector<std::chrono::duration<double>> &SortingTimes, vector<string> &SortName,
           bool (*compare)(T, T)) {
    std::chrono::duration<double> elapsed_seconds;
    ArraySequence<T> *sequence = new ArraySequence<T>(AuxiliarySequence->GetSize());
    SortingTimes.clear();
    for (int i = 0; i < 8; i++) {
        for (int g = 0; g < AuxiliarySequence->GetSize(); g++) {
            sequence->Set(AuxiliarySequence->Get(g), g);
            //cout << sequence->Get(g) << ' ';
        }
        auto start = std::chrono::system_clock::now();
        if (i == 0) BubbleSort(sequence, compare);
        else if (i == 1) CocktailSort(sequence, compare);
        else if (i == 2) InsertionSort(sequence, compare);
        else if (i == 3) SelectionSort(sequence, compare);
        else if (i == 4) CountingSort(sequence, compare);
        else if (i == 5) BinaryInsertionSort(sequence, compare);
        else if (i == 6) QuickSort(sequence, 0, sequence->GetLength() - 1, compare);
        else ShellSort(sequence, compare);
        auto finish = std::chrono::system_clock::now();
        elapsed_seconds = finish - start;
//        for (int g = 0; g < AuxiliarySequence->GetSize(); g++) {
//            //sequence->Set(AuxiliarySequence->Get(g), g);
//            cout << sequence->Get(g) << ' ';
//        }
//        cout << SortName[i] << " elapsed time in milliseconds: "
//             << chrono::duration_cast<chrono::milliseconds>(elapsed_seconds).count()
//             << " ms" << endl;
        SortingTimes.push_back(elapsed_seconds);
    }
}