/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:14 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/02 21:01:10 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form (void):_name("default"), _isSigned(false),_reqGradeToSign(150),_reqGradeToExec(150)
{
    std::cout << "Default constructor called." << std::endl;
}

Form::Form (std::string name, int reqGradeToSing, int reqGradeToExec):_name(name),_isSigned(false), _reqGradeToSign(reqGradeToSing), _reqGradeToExec(reqGradeToExec)
{
    std::cout << "Parameter construction called" << std::endl;
    this->_checkGrade(this->getGradeToSign(), this->getGradeToExec());
}

Form::Form(const Form &copy):_name(copy.getName()), _isSigned(getSign()), _reqGradeToSign(getGradeToSign()), _reqGradeToExec(getGradeToExec())
{
    std::cout << "Copy constructor called. Source: " << copy.getName() << std::endl; 
    *this = copy;
}

Form::~Form(void)
{
    std::cout << "Destructor called. Form: " << this->getName() << " has been destroyed." << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    std::cout << "Assignation operator called. " << this->getName() << "is receiving attributes from " << copy.getName() << std::endl;
    if(this == &copy)
        return (*this);
    return (*this); 
}

std::string Form::getName(void) const
{
    return (this->_name);
}

bool Form::getSign(void)
{
    return(this->_isSigned);
}

int Form::getGradeToSign(void) const
{
    return (this->_reqGradeToSign);
}

int Form::getGradeToExec(void) const
{
    return (this->_reqGradeToExec);
}

void Form::_checkGrade(int reqGradeToSign, int reqGradeToExec)
{
    if(reqGradeToSign < 1 || reqGradeToExec < 1)
        throw Form::GradeTooHighException();
    else if (reqGradeToSign > 150 || reqGradeToExec > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    else if(this->getSign() == false)
    {
        this->_isSigned = true;
        std::cout << "Bureaucrat named " << bureaucrat.getName() << " rank: " << bureaucrat.getGrade() << " has signed form: " << this->getName() << "." << std::endl;
    }
    else
        std::cout << "This form is already signed." << std::endl;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

std::ostream &operator<<(std::ostream &out, Form *copy)
{
    std::string signStatus = copy->getSign() ? "YES" : "NO";
    out << "**** FORM REPORT ****" << std::endl;
    out << "Signed: " << signStatus << std::endl;
    out << "Grade required to sign: " << copy->getGradeToSign() << std::endl;
    out << "Grade required to execute: " << copy->getGradeToExec() << std::endl;
    return (out);
    
}