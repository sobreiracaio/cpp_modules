/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:40 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/18 19:23:38 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called." << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
    *this = copy;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
    std::cout << "WrongCat assigment operator called" << std::endl;
    if(this == &copy)
        return (*this);
    this->type = copy.getType();
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << " does: Mooooo!." << std::endl;
}
