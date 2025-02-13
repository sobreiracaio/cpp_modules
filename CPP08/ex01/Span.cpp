/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:21:42 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/13 19:46:35 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():_N(0){}

Span::Span(unsigned int number):_N(number){}

Span::Span(Span const &copy)
{
    *this = copy;
}

Span::~Span(){};

Span &Span::operator=(Span const &source)
{
    if(this == &source)
        return (*this);
    this->_N = source.getN();
    this->_integers = source.getStorage();
    
    return (*this);
}

unsigned int Span::getN() const
{
    return (this->_N);
}

std::vector<int> Span::getStorage() const
{
    return (this->_integers);
}

void Span::addNumber(int number)
{
    if(this->getStorage().size() >= this->getN())
        throw Span::MaxCapacityException();
    this->_integers.push_back(number);
}

int Span::shortestSpan()
{
    if(this->getStorage().size() <= 1)
    {
        throw Span::InsufficientIntegersException();
        return (-1);
    }
    
    std::vector<int> temp = this->getStorage();
    std::sort(temp.begin(), temp.end());

    int distance = temp[1] - temp[0];
    for(unsigned int i = 1; i < temp.size(); i++)
    {
        if(temp[i] - temp [i - 1] <= distance)
            distance = temp[i] - temp[i - 1];
    }
    return (distance);
    
}

int Span::longestSpan()
{
    if(this->getStorage().size() <= 1)
    {
        throw Span::InsufficientIntegersException();
        return (-1);
    }
    
    std::vector<int> temp = this->getStorage();
    std::vector<int>::iterator min = std::min_element(this->_integers.begin(), this->_integers.end());
    std::vector<int>::iterator max = std::max_element(this->_integers.begin(), this->_integers.end());
    
    return (*max - *min);
}

int generateNumbers(void)
{
    return (rand() % 10000);
}

void Span::fillData()
{
    this->_integers.resize(this->_N);
	std::generate(this->_integers.begin(), this->_integers.end(), &generateNumbers);
	std::sort(this->_integers.begin(), this->_integers.end());
}

const char* Span::MaxCapacityException::what() const throw()
{
	return ("Storage is full!");
}

const char* Span::InsufficientIntegersException::what() const throw()
{
	return ("Insufficient data to calculate the span (distance)!");
}

std::ostream &operator<<(std::ostream &out, Span const &span)
{
	out << std::endl << "Contents: ";
	for (unsigned int i = 0; i < span.getStorage().size(); i++)
	{
		out << BLUE << span.getStorage()[i] << WHITE;
		if (i < span.getStorage().size() - 1)
			out << " ";
	}
    out << std::endl << "Size is: " << BLUE <<span.getN() << WHITE << std::endl;
	return (out);
}