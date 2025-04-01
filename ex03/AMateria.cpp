/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:00:22 by rgiambon          #+#    #+#             */
/*   Updated: 2025/04/01 12:00:24 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type){}


AMateria::AMateria(AMateria const &other) : type("") 
{
    (void)other;
}


AMateria& AMateria::operator=(AMateria const &other)
{
    (void)other;
    return *this;
}

AMateria::~AMateria(){}

void AMateria::use(ICharacter &)
{
}

std::string const&  AMateria::getType() const
{
    return type;
}
