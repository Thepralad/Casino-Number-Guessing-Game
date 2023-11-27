#include <iostream>
#include <random>
#include <algorithm>

class GuessTheNumber{
public:
    void run();

private:
    int balance = 100;
    int* generateRandomArray();
    int choice();
    int gameplay();

};

int* GuessTheNumber::generateRandomArray() {
    std::random_device rd;
    std::mt19937 gen(rd());

    int frequencies[6] = {0};

    for (int i = 0; i < 6; ++i) {
        std::uniform_int_distribution<> distribution(1, 10);
        frequencies[i] = distribution(gen); 
    }


    int totalElements = 0;
    for (int i = 0; i < 6; ++i) {
        totalElements += frequencies[i];
    }

  
    int* resultArray = new int[totalElements];
    int currentIndex = 0;

    for (int i = 1; i <= 6; ++i) {
        for (int j = 0; j < frequencies[i - 1]; ++j) {
            resultArray[currentIndex++] = i;
        }
    }

   
    std::shuffle(resultArray, resultArray + totalElements, gen);

    return resultArray;
}

int GuessTheNumber::choice(){
    int inputNumber;
    bool validInput = false;
    do {
        std::cout << "Try your luck! (1 - 6): ";
        std::cin >> inputNumber;
        if(inputNumber >  1 && inputNumber < 6){
            validInput = true;
        }
        else {
            std::cout << "\033[1;31mInvalid Input!\033[0m\n";
            validInput = false;
        }

    } while(!validInput);
    return inputNumber;
}

int GuessTheNumber::gameplay(){
    
}

int main(){
    
}
