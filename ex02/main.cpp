/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:58:38 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/01 11:58:59 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    delete dog;
    delete cat;

    return 0;
}
