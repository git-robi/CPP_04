/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:37 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/01 12:03:39 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        templates[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != nullptr)
            delete templates[i];
    }
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i] != nullptr)
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = nullptr;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (templates[i] != nullptr)
            {
                delete templates[i];
                templates[i] = nullptr;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.templates[i] != nullptr)
                templates[i] = other.templates[i]->clone();
            else
                templates[i] = nullptr;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == nullptr)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == nullptr)
        {
            templates[i] = m;
            return;
        }
    }
    delete m; 
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    // Look for a template matching the requested type
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != nullptr && templates[i]->getType() == type)
            return templates[i]->clone();  // Create a new copy of the template
    }
    return nullptr; 
}
