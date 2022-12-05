#pragma once;

#include <iostream>

using namespace std;

void MainMenu(){
    cout << "What do you want to do?\n";
    cout << "0 - Stop\n";
    cout << "1 - Read sequence\n";
    cout << "2 - Sort sequence\n";
    cout << "3 - Print sequence\n";
    cout << "4 - Test\n";
    cout << "5 - Print sort time\n";
    cout << "6 - Compare sorting (by time)\n";
};

void TypeSortMenu() {
    cout << "what order of elements do you want?\n";
    cout << "1 - by non - decreasing\n"; //по неубыванию
    cout << "2 - by non - increasing\n"; //по невозрастанию
}

void SortMenu() {
    cout << "What Sort do you want to choose?\n";
    cout << "1 - Bubble sort\n";
    cout << "2 - Cocktail sort\n";
    cout << "3 - Insertion sort\n";
    cout << "4 - Selection sort\n";
    cout << "5 - Counting sort\n";
    cout << "6 - Binary insertion sort\n";
    cout << "7 - Quick sort\n";
    cout << "8 - Shell sort\n";
}

void DataTypeMenu() {
    cout << "What data type you want?" << '\n';
    cout << "1 - int" << '\n';
    cout << "2 - float" << '\n';
    cout << "3 - complex" << '\n';
}

void InputTypeMenu() {
    cout << "What type of input you want?\n";
    cout << "1 - from keyboard\n";
    cout << "2 - random\n";
}

void RandomTypeMenu() {
    cout << "What size do you want?\n";
    cout << "1 - input from keyboard\n";
    cout << "2 - random\n";
}
