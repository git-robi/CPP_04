#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "-------- Testing Abstract Class --------" << std::endl;
    // This won't compile because Animal is abstract:
    //Animal test;  
    //Animal* test = new Animal();

    std::cout << "-------- Testing Polymorphism --------" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\nDog sound: ";
    dog->makeSound();
    std::cout << "Cat sound: ";
    cat->makeSound();

    std::cout << "\n-------- Testing Destructors --------" << std::endl;
    delete dog;  // Should call Dog destructor then Animal destructor
    delete cat;  // Should call Cat destructor then Animal destructor

    return 0;
}