/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:40 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/19 20:01:29 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called." << std::endl;
    this->type = "Dog";
    this->_brain = new Brain;
}

Dog::Dog(Dog const &copy) : Animal (copy)
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->_brain = NULL;
    *this = copy;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog &Dog::operator=(Dog const &copy)
{
    std::cout << "Dog assigment operator called" << std::endl;
    if(this == &copy)
        return (*this);
    this->type = copy.getType();
    delete this->_brain;
    this->_brain = new Brain(*copy._brain);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << " does: Woof woof!" << std::endl;
}
