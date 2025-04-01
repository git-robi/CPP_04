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
        templates[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL)
            delete templates[i];
    }
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i] != NULL)
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (templates[i] != NULL)
            {
                delete templates[i];
                templates[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other.templates[i] != NULL)
                templates[i] = other.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == NULL)
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
        if (templates[i] != NULL && templates[i]->getType() == type)
            return templates[i]->clone();  // Create a new copy of the template
    }
    return NULL; 
}
