/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:55:37 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/01 11:55:39 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARRAY_SIZE 4

int main()
{
    std::cout << "Creating array of " << ARRAY_SIZE << " animals..." << std::endl;
    Animal* animals[ARRAY_SIZE];

    // Fill first half with Dogs
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        std::cout << "\nCreating Dog " << i + 1 << std::endl;
        animals[i] = new Dog();
    }

    // Fill second half with Cats
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        std::cout << "\nCreating Cat " << i - (ARRAY_SIZE / 2) + 1 << std::endl;
        animals[i] = new Cat();
    }

    // Test deep copy with one of the Dogs
    std::cout << "\n-------- Testing Deep Copy --------" << std::endl;
    Dog* dogCopy = new Dog(*(Dog*)animals[0]);  // Copy first dog
    
    // Modify original dog's brain
    ((Dog*)animals[0])->getBrain()->ideas[0] = "I love bones!";
    
    // Show that the copy remains unchanged
    std::cout << "Original dog's first idea: " << ((Dog*)animals[0])->getBrain()->ideas[0] << std::endl;
    std::cout << "Copied dog's first idea: " << dogCopy->getBrain()->ideas[0] << std::endl;
    
    delete dogCopy;  // Clean up the copy

    std::cout << "\n-------- Deleting Array --------" << std::endl;
    // Delete all animals
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "\nDeleting " << animals[i]->getType() << std::endl;
        delete animals[i];
    }

    return 0;
}
