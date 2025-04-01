/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:03:45 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/01 12:03:59 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* templates[4];

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const &other);
        MateriaSource& operator=(MateriaSource const &other);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
