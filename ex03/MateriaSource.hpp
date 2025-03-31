#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* templates[4];  // Storage for learned Materia templates

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const &other);
        MateriaSource& operator=(MateriaSource const &other);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif