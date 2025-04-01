/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:52:53 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/01 11:52:56 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----------------- BASIC TEST ---------------" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n----------------- DIRECT OBJECT TEST ---------------" << std::endl;
    Dog normalDog;
    Cat normalCat;
    normalDog.makeSound();  // Should bark
    normalCat.makeSound();  // Should meow

    std::cout << "\n----------------- ARRAY TEST ---------------" << std::endl;
    const Animal* animals[4] = { new Dog(), new Cat(), new Dog(), new Cat() };
    for(int i = 0; i < 4; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << "\n----------------- WRONG ANIMAL TEST ---------------" << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wcat = new WrongCat();
    std::cout << wcat->getType() << " " << std::endl;
    wcat->makeSound();  // Will output WrongAnimal sound due to no virtual
    wrong->makeSound();

    std::cout << "\n----------------- CLEANUP TEST ---------------" << std::endl;
    delete meta;
    delete j;
    delete i;
    delete wrong;
    delete wcat;
    for(int i = 0; i < 4; i++) {
        delete animals[i];
    }

    return 0;
}
