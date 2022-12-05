#pragma once;
#include <iostream>
#include <assert.h>
#include "Sequence.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sort.h"

using namespace std;

void testDynamicArray() {
    int initArr1[] = {1, 2, 3, 4, 5};
    DynamicArray<int> arr1(initArr1, 5);
    assert(arr1.Get(0) == 1);
    assert(arr1.Get(3) == 4);
    assert(arr1.Get(4) == 5);
    assert(arr1.GetSize() == 5);
    arr1.Resize(6);
    arr1.Set(0, 0);
    arr1.Set(5, 5);
    assert(arr1.GetSize() == 6);
    assert(arr1.Get(0) == 0);
    assert(arr1.Get(5) == 5);
}

void testLinkedList() {
    int initArr1[] = {1, 2, 3, 5};
    int initArr2[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7};
    LinkedList<int> list1(initArr1, 4);
    assert(list1.Get(0) == 1);
    assert(list1.GetFirst() == 1);
    assert(list1.Get(2) == 3);
    assert(list1.Get(3) == 5);
    assert(list1.GetLast() == 5);
    assert(list1.GetLength() == 4);
    list1.Prepend(0);
    list1.Append(6);
    list1.InsertAt(-1, 0);
    list1.InsertAt(7, 7);
    list1.InsertAt(4, 5);
    assert(list1 == LinkedList<int>(initArr2, 9));
}

void testLinkedListSequence() {
    int initArr1[] = {1, 2, 3, 5};
    int initArr2[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7};
    LinkedListSequence<int> seq1(initArr1, 4);
    assert(seq1 == LinkedListSequence<int>(seq1));
    assert(seq1.Get(0) == 1);
    assert(seq1.GetFirst() == 1);
    assert(seq1.Get(2) == 3);
    assert(seq1.Get(3) == 5);
    assert(seq1.GetLast() == 5);
    assert(seq1.GetSize() == 4);
    seq1.Prepend(0);
    seq1.Append(6);
    seq1.InsertAt(-1, 0);
    seq1.InsertAt(7, 7);
    seq1.InsertAt(4, 5);
    assert(seq1 == LinkedListSequence<int>(initArr2, 9));
}

void testArraySequence() {
    int initArr1[] = {1, 2, 3, 4, 5};
    ArraySequence<int> arr1(initArr1, 5);
    assert(arr1.Get(0) == 1);
    assert(arr1.Get(3) == 4);
    assert(arr1.Get(4) == 5);
    assert(arr1.GetSize() == 5);
    arr1.Append(6);
    assert(arr1.Get(5) == 6);
    arr1.Prepend(0);
    assert(arr1.GetSize() == 7);
    assert(arr1.Get(0) == 0);
    assert(arr1.Get(6) == 6);
}

void BubbleSortTest() {
    ArraySequence<int> *sequence = new ArraySequence<int>();
    sequence->Append(2);
    sequence->Append(7);
    sequence->Append(3);
    sequence->Append(5);
    sequence->Append(6);
    sequence->Append(1);
    sequence->Append(4);
    sequence->Append(8);
    sequence->Append(9);
    BubbleSort(sequence, asc);
    assert(sequence->Get(0) == 1);
    assert(sequence->Get(1) == 2);
    assert(sequence->Get(2) == 3);
    assert(sequence->Get(3) == 4);
    assert(sequence->Get(4) == 5);
    assert(sequence->Get(5) == 6);
    assert(sequence->Get(6) == 7);
    assert(sequence->Get(7) == 8);
    assert(sequence->Get(8) == 9);
    delete sequence;
}

void CocktailSortTest() {
    ArraySequence<int> *sequence = new ArraySequence<int>();
    sequence->Append(2);
    sequence->Append(7);
    sequence->Append(3);
    sequence->Append(5);
    sequence->Append(6);
    sequence->Append(1);
    sequence->Append(4);
    sequence->Append(8);
    sequence->Append(9);
    CocktailSort(sequence, asc);
    assert(sequence->Get(0) == 1);
    assert(sequence->Get(1) == 2);
    assert(sequence->Get(2) == 3);
    assert(sequence->Get(3) == 4);
    assert(sequence->Get(4) == 5);
    assert(sequence->Get(5) == 6);
    assert(sequence->Get(6) == 7);
    assert(sequence->Get(7) == 8);
    assert(sequence->Get(8) == 9);
    delete sequence;
}

void SelectionSortTest() {
    ArraySequence<int> *sequence = new ArraySequence<int>();
    sequence->Append(2);
    sequence->Append(7);
    sequence->Append(3);
    sequence->Append(5);
    sequence->Append(6);
    sequence->Append(1);
    sequence->Append(4);
    sequence->Append(8);
    sequence->Append(9);
    SelectionSort(sequence, asc);
    assert(sequence->Get(0) == 1);
    assert(sequence->Get(1) == 2);
    assert(sequence->Get(2) == 3);
    assert(sequence->Get(3) == 4);
    assert(sequence->Get(4) == 5);
    assert(sequence->Get(5) == 6);
    assert(sequence->Get(6) == 7);
    assert(sequence->Get(7) == 8);
    assert(sequence->Get(8) == 9);
    delete sequence;
}

void InsertionSortTest() {
    ArraySequence<int> *sequence = new ArraySequence<int>();
    sequence->Append(2);
    sequence->Append(7);
    sequence->Append(3);
    sequence->Append(5);
    sequence->Append(6);
    sequence->Append(1);
    sequence->Append(4);
    sequence->Append(8);
    sequence->Append(9);
    InsertionSort(sequence, asc);
    assert(sequence->Get(0) == 1);
    assert(sequence->Get(1) == 2);
    assert(sequence->Get(2) == 3);
    assert(sequence->Get(3) == 4);
    assert(sequence->Get(4) == 5);
    assert(sequence->Get(5) == 6);
    assert(sequence->Get(6) == 7);
    assert(sequence->Get(7) == 8);
    assert(sequence->Get(8) == 9);
    delete sequence;
}

void CountingSortTest() {
    ArraySequence<int> *sequence = new ArraySequence<int>();
    sequence->Append(2);
    sequence->Append(7);
    sequence->Append(3);
    sequence->Append(5);
    sequence->Append(6);
    sequence->Append(1);
    sequence->Append(4);
    sequence->Append(8);
    sequence->Append(9);
    CountingSort(sequence, asc);
    assert(sequence->Get(0) == 1);
    assert(sequence->Get(1) == 2);
    assert(sequence->Get(2) == 3);
    assert(sequence->Get(3) == 4);
    assert(sequence->Get(4) == 5);
    assert(sequence->Get(5) == 6);
    assert(sequence->Get(6) == 7);
    assert(sequence->Get(7) == 8);
    assert(sequence->Get(8) == 9);
    delete sequence;
}

void BinaryInsertionSortTest() {
    ArraySequence<int> *sequence = new ArraySequence<int>();
    sequence->Append(2);
    sequence->Append(7);
    sequence->Append(3);
    sequence->Append(5);
    sequence->Append(6);
    sequence->Append(1);
    sequence->Append(4);
    sequence->Append(8);
    sequence->Append(9);
    BinaryInsertionSort(sequence, asc);
    assert(sequence->Get(0) == 1);
    assert(sequence->Get(1) == 2);
    assert(sequence->Get(2) == 3);
    assert(sequence->Get(3) == 4);
    assert(sequence->Get(4) == 5);
    assert(sequence->Get(5) == 6);
    assert(sequence->Get(6) == 7);
    assert(sequence->Get(7) == 8);
    assert(sequence->Get(8) == 9);
    delete sequence;
}

void QuickSortTest() {
    ArraySequence<int> *sequence = new ArraySequence<int>();
    sequence->Append(2);
    sequence->Append(7);
    sequence->Append(3);
    sequence->Append(5);
    sequence->Append(6);
    sequence->Append(1);
    sequence->Append(4);
    sequence->Append(8);
    sequence->Append(9);
    QuickSort(sequence, 0, sequence->GetSize() - 1, asc);
    assert(sequence->Get(0) == 1);
    assert(sequence->Get(1) == 2);
    assert(sequence->Get(2) == 3);
    assert(sequence->Get(3) == 4);
    assert(sequence->Get(4) == 5);
    assert(sequence->Get(5) == 6);
    assert(sequence->Get(6) == 7);
    assert(sequence->Get(7) == 8);
    assert(sequence->Get(8) == 9);
    delete sequence;
}

void ShellSortTest() {
    ArraySequence<int> *sequence = new ArraySequence<int>();
    sequence->Append(2);
    sequence->Append(7);
    sequence->Append(3);
    sequence->Append(5);
    sequence->Append(6);
    sequence->Append(1);
    sequence->Append(4);
    sequence->Append(8);
    sequence->Append(9);
    ShellSort(sequence, asc);
    assert(sequence->Get(0) == 1);
    assert(sequence->Get(1) == 2);
    assert(sequence->Get(2) == 3);
    assert(sequence->Get(3) == 4);
    assert(sequence->Get(4) == 5);
    assert(sequence->Get(5) == 6);
    assert(sequence->Get(6) == 7);
    assert(sequence->Get(7) == 8);
    assert(sequence->Get(8) == 9);
    delete sequence;
}

void Test() {
    testLinkedListSequence();
    cout << "Linked list sequence work correct\n";
    testDynamicArray();
    cout << "Dynamic array work correct\n";
    testLinkedList();
    cout << "Linked list work correct\n";
    testArraySequence();
    cout << "Array sequence work correct\n";
    BubbleSortTest();
    cout << "Bubble sort work correct\n";
    CocktailSortTest();
    cout << "Cocktail sort work correct\n";
    InsertionSortTest();
    cout << "Insertion sort work correct\n";
    SelectionSortTest();
    cout << "Selection sort work correct\n";
    CountingSortTest();
    cout << "Counting sort work correct\n";
    BinaryInsertionSortTest();
    cout << "Binary insertion work correct\n";
    QuickSortTest();
    cout << "Quick sort work correct\n";
    ShellSortTest();
    cout << "Shell sort work correct\n";
}