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
        slots[i] = NULL;
    for (int i = 0; i < 100; i++)
        floor[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        slots[i] = NULL;
    for (int i = 0; i < 100; i++)
        floor[i] = NULL;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] != NULL)
            delete slots[i];
    }
    for (int i = 0; i < 100; i++)
    {    
        if (floor[i] != NULL)
            delete floor[i];
    }
}

Character::Character(Character const &other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.slots[i] != NULL)
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = NULL;
    }
    for (int i = 0; i < 100; i++)
    {
        if (other.floor[i] != NULL)
            floor[i] = other.floor[i]->clone();
        else
            floor[i] = NULL;
    }
}

Character& Character::operator=(Character const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (slots[i] != NULL)
            {
                delete slots[i];
                slots[i] = NULL;
            }
        }
        for (int i = 0; i < 100; i++)
        {
            if (floor[i] != NULL)
            {
                delete floor[i];
                floor[i] = NULL;
            }
        }
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (other.slots[i] != NULL)
                slots[i] = other.slots[i]->clone();
            else
                slots[i] = NULL;
        }
        for (int i = 0; i < 100; i++)
        {
            if (other.floor[i] != NULL)
                floor[i] = other.floor[i]->clone();
            else
                floor[i] = NULL;
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
    if (m == NULL)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] == NULL)
        {
            slots[i] = m;
            return;  // Exit after equipping
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || slots[idx] == NULL)
        return;
        
    int i = 0;
    while(i < 100)
    {
        if (floor[i] == NULL)
        {
            floor[i] = slots[idx];
            slots[idx] = NULL;
            return;
        }
        i++;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && slots[idx] != NULL)
        slots[idx]->use(target);
}
