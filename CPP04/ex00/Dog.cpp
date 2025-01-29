/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:40 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/20 20:00:22 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called." << std::endl;
    this->type = "Dog";
}

Dog::Dog(Dog const &copy) : Animal (copy)
{
    std::cout << "Dog copy constructor called." << std::endl;
    *this = copy;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
    std::cout << "Dog assigment operator called" << std::endl;
    if(this == &copy)
        return (*this);
    this->type = copy.getType();
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "do: Woof woof!" << std::endl;
}
