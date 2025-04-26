#include <iostream>
#include <vector>
#include <cmath>

auto greetings() -> void {
    auto name = std::string();

    std::cout << "Input your name: ";
    std::cin >> name;

    if(name == "Einstein") {
        std::cout << "I know you!";
    } else {
        std::cout << "Greetings";
    }
}

auto guessing() -> void {
    auto numberToGuess = std::rand();
    auto guessedNumber = -1;

    std::cout << numberToGuess << "\n";

    while(guessedNumber != numberToGuess) {
        std::cout << "Guess a number: ";
        std::cin >> guessedNumber;

        if(guessedNumber > numberToGuess) std::cout << "Too big. Try lower.\n";

        if(guessedNumber < numberToGuess) std::cout << "Too small. Try higher.\n";
    }

    std::cout << "Congratulations!";
}

auto isPrime(int number) -> bool {
    if(number < 2) return false;
    for(auto i = 2; i <= std::sqrt(number); i++) {
        if(number % i == 0) return false;
    }
    return true;
}

auto prime() -> void {
    std::cout << "Please input the number.\n";
    std::cout << "Type in a negative number to stop.\n";

    auto numbersToCheckForPrimality = std::vector<int>();

    auto number = 0;
    std::cin >> number;

    while(number >= 0) {
        numbersToCheckForPrimality.push_back(number);
        std::cin >> number;
    }

    for(auto element : numbersToCheckForPrimality) {
        if(isPrime(element)) {
            std::cout << element << " is prime.\n";
        }else {
            std::cout << element << " is not prime.\n";
        }
    }

}

auto main() -> int {

    // greetings();

    // guessing();

    // prime();
}
