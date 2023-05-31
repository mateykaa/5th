#include "tasks.h"

// Функция для получения булевых значений переменной M1
std::vector<bool> getBooleanValues(int numBits) {
    std::vector<bool> booleanValues;
    int numCombinations = pow(2, numBits);

    std::cout << "Enter the Boolean values of the variable M1 (0 or 1) separated by a space: ";

    for (int i = 0; i < numCombinations; ++i) {
        int value;
        std::cin >> value;
        booleanValues.push_back(value == 1);
    }

    return booleanValues;
}

// Функция для отображения карты Карно для переменной M1
void printKarnaughMap(const std::vector<bool>& booleanValues) {
    int numRows = booleanValues.size() / 2;
    int numCols = 2;

    std::cout << "  M1" << std::endl;

    for (int i = 0; i < numRows; ++i) {
        std::cout << "-------" << std::endl;
        for (int j = 0; j < numCols; ++j) {
            std::cout << "|  " << booleanValues[i * numCols + j] << "  ";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "-------" << std::endl;
}


QVariantMap Task1(){
    int numBits = 1;
    QVariantMap task;
    std::vector<bool> booleanValues = getBooleanValues(numBits);
    printKarnaughMap(booleanValues);

    return task;
}


QVariantMap Task2(){

}


QVariantMap Task3(){

}


QVariantMap Task4(){

}


QVariantMap Task5(){

}

