#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    catBrain = new Brain();
    std::cout << "Cat constructor called" << std::endl;   
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    catBrain = new Brain(*other.catBrain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete catBrain;
        catBrain = new Brain(*other.catBrain);
    }
    return *this;
}

Cat::~Cat()
{
    delete catBrain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "* meow meow *" << std::endl;
}