/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:41:55 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/22 20:52:38 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called." << std::endl;
    this->_value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const Fixed &original)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = original;
}

Fixed::Fixed(const int intNbr)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->_value = intNbr * (1 << Fixed::_bits);
}

Fixed::Fixed(const float floatNbr)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->_value = roundf(floatNbr * (1 << Fixed::_bits));
}

Fixed& Fixed::operator=(Fixed const &original)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if(this == &original)
        return (*this);
    this->_value = original.getRawBits();
    return (*this);
}



int  Fixed::getRawBits()const
{
    std::cout << "getRawBits member function called." << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}


float Fixed::toFloat(void)
{
    return ((float)this->_value / (float)(1 << Fixed::_bits));
}

int Fixed::toInt(void)
{
    return (this->_value / (1 << Fixed::_bits));
}