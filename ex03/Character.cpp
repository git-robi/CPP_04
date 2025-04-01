/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:00:47 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/01 12:00:51 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("default")
{
    for (int i = 0; i < 4; i++)
        slots[i] = nullptr;
    for (int i = 0; i < 100; i++)
        floor[i] = nullptr;
}

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        slots[i] = nullptr;
    for (int i = 0; i < 100; i++)
        floor[i] = nullptr;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] != nullptr)
            delete slots[i];
    }
    for (int i = 0; i < 100; i++)
    {    
        if (floor[i] != nullptr)
            delete floor[i];
    }
}

Character::Character(Character const &other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.slots[i] != nullptr)
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = nullptr;
    }
    for (int i = 0; i < 100; i++)
    {
        if (other.floor[i] != nullptr)
            floor[i] = other.floor[i]->clone();
        else
            floor[i] = nullptr;
    }
}

Character& Character::operator=(Character const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (slots[i] != nullptr)
            {
                delete slots[i];
                slots[i] = nullptr;
            }
        }
        for (int i = 0; i < 100; i++)
        {
            if (floor[i] != nullptr)
            {
                delete floor[i];
                floor[i] = nullptr;
            }
        }
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (other.slots[i] != nullptr)
                slots[i] = other.slots[i]->clone();
            else
                slots[i] = nullptr;
        }
        for (int i = 0; i < 100; i++)
        {
            if (other.floor[i] != nullptr)
                floor[i] = other.floor[i]->clone();
            else
                floor[i] = nullptr;
        }
    }
    return *this;
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (m == nullptr)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] == nullptr)
        {
            slots[i] = m;
            return;  // Exit after equipping
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || slots[idx] == nullptr)
        return;
        
    int i = 0;
    while(i < 100)
    {
        if (floor[i] == nullptr)
        {
            floor[i] = slots[idx];
            slots[idx] = nullptr;
            return;
        }
        i++;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && slots[idx] != nullptr)
        slots[idx]->use(target);
}
