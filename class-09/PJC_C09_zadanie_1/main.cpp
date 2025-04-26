# include <iostream>

struct Animal {
    auto virtual makeSound() -> void {}
};

struct Dog: Animal {
    auto makeSound() -> void override {
        std::cout << "Woof\n";
    }
};

struct Cat: Animal {
    auto makeSound() -> void override {
        std::cout << "Meow\n";
    }
};

auto makeSoundTwice(Animal& animal) {
    animal.makeSound();
    animal.makeSound();
}

auto main() -> int {
    auto dog = Dog();
    auto cat = Cat();

    makeSoundTwice(dog);
    makeSoundTwice(cat);
}
