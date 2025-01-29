/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:40 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/18 19:15:31 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called." << std::endl;
    this->type = "Wrongdefault";
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
    std::cout << "WrongAnimal copy constructor called." << std::endl;
    *this = copy;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}

void WrongAnimal::setType(std::string newType)
{
    this->type = newType;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
    std::cout << "WrongAnimal assigment operator called" << std::endl;
    if(this == &copy)
        return (*this);
    this->type = copy.getType();
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "do: Grrrr... blblblbl..unidentified wronganimal." << std::endl;
}
