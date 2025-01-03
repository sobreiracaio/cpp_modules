/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:50:53 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/03 21:14:43 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_name("default"), _grade(150)
{
    std::cout <<"Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    
    std::cout <<"Parameter constructor called. Bureaucrat named " << this->getName();
    std::cout <<" was created and he/she is " << this->getGrade() << "º on rank." << std::endl;
    _setGrade(grade);
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
    this->_grade = copy.getGrade();
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::_setGrade(int grade)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

void Bureaucrat::incrementGrade(void)
{
    this->_setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
    this->_setGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high for the job.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low for the job.");
}

void Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form)
{
    form.execute(*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat *copy)
{
    out << "Bureaucrat named " << copy->getName() << " is grade " << copy->getGrade() << ".";
    return (out);
}
