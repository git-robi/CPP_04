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
        // Clean up existing templates
        for (int i = 0; i < 4; i++)
        {
            if (templates[i] != nullptr)
            {
                delete templates[i];
                templates[i] = nullptr;
            }
        }
        // Copy templates from other
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
        
    // Find first empty slot
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == nullptr)
        {
            templates[i] = m;  // Store the original materia
            return;
        }
    }
    // If we get here, all slots are full
    delete m;  // Clean up the passed materia if we couldn't store it
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    // Look for a template matching the requested type
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != nullptr && templates[i]->getType() == type)
            return templates[i]->clone();  // Create a new copy of the template
    }
    return nullptr;  // Return null if type not found
}