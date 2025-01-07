/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:40 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/18 19:24:28 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called." << std::endl;
    this->type = "default";
}

Animal::Animal(Animal const &copy)
{
    std::cout << "Animal copy constructor called." << std::endl;
    *this = copy;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return(this->type);
}

void Animal::setType(std::string newType)
{
    this->type = newType;
}

Animal &Animal::operator=(Animal const &copy)
{
    std::cout << "Animal assigment operator called" << std::endl;
    if(this == &copy)
        return (*this);
    this->type = copy.getType();
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Grrrr... unidentified animal." << std::endl;
}
