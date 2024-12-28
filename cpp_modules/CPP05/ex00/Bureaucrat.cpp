/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:50:53 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/28 17:10:45 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucat.hpp"

Bureaucrat::Bureaucrat(void):_name("default"), _grade(150)
{
    std::cout <<"Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout <<"Parameter constructor called. Bureaucrat named: " << this->getName();
    std::cout <<" was created and it is " << this->getGrade() << "º on rank." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    std::cout << "Copy constructor called, source: " << copy.getName() << std::endl;
    *this = copy;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat named " << this->getName() << " has been destroyed." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
    std::cout << "Bureaucrat assignment operator called." << std::endl;
    if(this == &copy)
        return (*this);
    this->_grade = copy._grade;
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void)
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
    this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
    this->_grade++;
}