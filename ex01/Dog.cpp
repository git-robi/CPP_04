/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:55:22 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/01 11:55:24 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    dogBrain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    dogBrain = new Brain(*other.dogBrain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete dogBrain;
        dogBrain = new Brain(*other.dogBrain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "* bark bark *" << std::endl;
}

Dog::~Dog()
{
    delete dogBrain;
    std::cout << "Dog destructor called" << std::endl;
}
