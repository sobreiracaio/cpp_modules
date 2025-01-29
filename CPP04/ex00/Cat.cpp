/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:40 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/18 19:23:04 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called." << std::endl;
    this->type = "Cat";
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called." << std::endl;
    *this = copy;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
    std::cout << "Cat assigment operator called" << std::endl;
    if(this == &copy)
        return (*this);
    this->type = copy.getType();
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "do: Meowwww." << std::endl;
}
