#include <iostream>
#include "Sort.h"
#include "Menu.h"
#include "Complex.h"
#include "Test.h"
#include "Sequence.h"
#include <ctime>
#include <chrono>
#include <vector>
#include <cmath>
#include "Draw.h"

using namespace std;
using namespace std::chrono;

//duration<milliseconds> sec;

template<typename T>
void RandomInput(int size, ArraySequence<T> &sequence) {
    delete sequence;
    *sequence = ArraySequence<T>(size);
    for (int i = 0; i < size; i++) {
        sequence->Set(rand(), i);
    }

}

template<typename T>
void Print(Sequence<T> *sequence) {
    int size = sequence->GetSize();
    for (int i = 0; i < size; i++) {
        cout << sequence->Get(i) << " ";
    }
    cout << '\n';
}

std::chrono::duration<double> elapsed_seconds;

template<typename T>
void Sorts(Sequence<T> *sequence, bool (*compare)(T, T)) {
    enum Sort {
        Bubble = 1,
        Cocktail = 2,
        Insertion = 3,
        Selection = 4,
        Counting = 5,
        BinaryInsertion = 6,
        Quick = 7,
        Shell = 8
    };
    int Sort;
    SortMenu();
    cin >> Sort;
    auto start = std::chrono::system_clock::now();
    switch (Sort) {
        case Bubble:
            BubbleSort(sequence, compare);
            break;
        case Cocktail:
            CocktailSort(sequence, compare);
            break;
        case Insertion:
            InsertionSort(sequence, compare);
            break;
        case Selection:
            SelectionSort(sequence, compare);
            break;
        case Counting:
            CountingSort(sequence, compare);
            break;
        case BinaryInsertion:
            BinaryInsertionSort(sequence, compare);
            break;
        case Quick:
            QuickSort(sequence, 0, sequence->GetSize() - 1, compare);
            break;
        case Shell:
            ShellSort(sequence, compare);
            break;
    }
    auto finish = std::chrono::system_clock::now();
    elapsed_seconds = finish - start;
}

vector<std::chrono::duration<double>> SortingTimes;
vector<string> SortName = {"BubbleSort", "CocktailSort", "InsertionSort", "SelectionSort", "CountingSort",
                           "BinaryInsertionSort", "QuickSort", "ShellSort"};

template<typename T>
void Mainfunc() {
    srand(time(NULL));
    ArraySequence<T> *sequence = new ArraySequence<T>();
    ArraySequence<T> *AuxiliarySequence = new ArraySequence<T>();
    int Command = 1;
    while (Command != 0) {
        MainMenu();
        cin >> Command;
        if (Command == 1) {
            InputTypeMenu();
            int InputType = 0;
            cin >> InputType;
            if (InputType == 1) {
                cout << "Please input size of sequence\n";;
                int size;
                cin >> size;
                delete sequence;
                sequence = new ArraySequence<T>();
                cout << "Input data\n";
                //sequence->ArraySequence();
                for (int i = 0; i < size; i++) {
                    T data;
                    cin >> data;
                    sequence->Append(data);
                }
            } else {
                RandomTypeMenu();
                int RandomType = 0;
                cin >> RandomType;
                if (RandomType == 1) {
                    int size;
                    cout << "Введите количество элементов пожалуйста\n";
                    cin >> size;
                    delete sequence;
                    sequence = new ArraySequence<T>(size);
                    for (int i = 0; i < size; i++) {
                        sequence->Set(rand(), i);
                    }
                } else {
                    int size = rand();
                    delete sequence;
                    *sequence = ArraySequence<T>(size);
                    for (int i = 0; i < size; i++) {
                        sequence->Set(rand(), i);
                    }
                }
            }
        } else if (Command == 2) {
            TypeSortMenu();
            int TypeSort;
            cin >> TypeSort;
            if (TypeSort == 1) {
                Sorts(sequence, asc);
            } else {
                Sorts(sequence, desc);
            }
        } else if (Command == 3) {
            Print(sequence);
        } else if (Command == 4) {
            Test();
        } else if (Command == 5) {
//            cout << "Last sort time is: " << sec.count() << '\n';
//
//            if (sec!= 0) {
//                cout << "Last sort time is: " << sec.count() << '\n';
//            } else {
//                cout << "You haven't sorted the array yet or time equal to zero(try a bigger size)\n";
//            }
            //std::chrono::duration<double> elapsed_seconds = finish - start;
            //std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            cout << "Elapsed time in nanoseconds: "
                 << chrono::duration_cast<chrono::milliseconds>(elapsed_seconds).count()
                 << " ms" << endl;
        } else if (Command == 6) {
            if (sequence->GetLength() == 0) cout << "Your sequence size is zero, please fill up it\n";
            else {
                for (int g = 0; g < sequence->GetLength(); g++) {
                    AuxiliarySequence->Append(sequence->Get(g));
                }
                SortTimes(AuxiliarySequence, SortingTimes, SortName, asc);
                for (int i = 0; i < SortName.size(); i++) {
                    cout << SortName[i] << " elapsed time in milliseconds: "
                         << chrono::duration_cast<chrono::milliseconds >(SortingTimes[i]).count()
                         << " ms" << endl;
                }
            }
        } else if (Command == 7) {
            draw<T>(SortName, asc);
        } else {
            sequence->~ArraySequence();
        }
    }
}

int main() {
    DataTypeMenu();
    int DataType = 0;
    cin >> DataType;
    cout << "first of all input sequence please" << '\n';
    if (DataType == 1) {
        Mainfunc<int>();
    } else if (DataType == 2) {
        Mainfunc<float>();
    } else if (DataType == 3) {
        //Mainfunc<Complex<int>>();
    }
}
