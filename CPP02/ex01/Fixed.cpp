/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:41:55 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/23 19:40:52 by crocha-s         ###   ########.fr       */
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
    std::cout << "Int constructor called." << std::endl;
    this->_value = intNbr * (1 << Fixed::_bits);
}

Fixed::Fixed(const float floatNbr)
{
    std::cout << "Float constructor called." << std::endl;
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

std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return (out);
}

int  Fixed::getRawBits()const
{
    
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}


float Fixed::toFloat(void)const
{
    return ((float)this->_value / (float)(1 << Fixed::_bits));
}

int Fixed::toInt(void)const
{
    return (this->_value / (1 << Fixed::_bits));
}