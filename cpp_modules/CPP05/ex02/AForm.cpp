/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:14 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/03 20:44:27 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm (void):_name("default"), _isSigned(false),_reqGradeToSign(150),_reqGradeToExec(150)
{
    std::cout << "Default constructor called." << std::endl;
}

AForm::AForm (std::string name, int reqGradeToSing, int reqGradeToExec):_name(name),_isSigned(false), _reqGradeToSign(reqGradeToSing), _reqGradeToExec(reqGradeToExec)
{
    std::cout << "Parameter construction called" << std::endl;
    this->_checkGrade(this->getGradeToSign(), this->getGradeToExec());
}

AForm::AForm(const AForm &copy):_name(copy.getName()), _isSigned(getSign()), _reqGradeToSign(getGradeToSign()), _reqGradeToExec(getGradeToExec())
{
    std::cout << "Copy constructor called. Source: " << copy.getName() << std::endl; 
    *this = copy;
}

AForm::~AForm(void)
{
    std::cout << "Destructor called. AForm: " << this->getName() << " has been destroyed." << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
    std::cout << "Assignation operator called. " << this->getName() << "is receiving attributes from " << copy.getName() << std::endl;
    if(this == &copy)
        return (*this);
    return (*this); 
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getSign(void)
{
    return(this->_isSigned);
}

int AForm::getGradeToSign(void) const
{
    return (this->_reqGradeToSign);
}

int AForm::getGradeToExec(void) const
{
    return (this->_reqGradeToExec);
}

void AForm::_checkGrade(int reqGradeToSign, int reqGradeToExec)
{
    if(reqGradeToSign < 1 || reqGradeToExec < 1)
        throw AForm::GradeTooHighException();
    else if (reqGradeToSign > 150 || reqGradeToExec > 150)
        throw AForm::GradeTooLowException();
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    else if(this->getSign() == false)
    {
        this->_isSigned = true;
        std::cout << "Bureaucrat named " << bureaucrat.getName() << " rank: " << bureaucrat.getGrade() << " has signed form: " << this->getName() << "." << std::endl;
    }
    else
        std::cout << "This form is already signed." << std::endl;
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, AForm *copy)
{
    std::string signStatus = copy->getSign() ? "YES" : "NO";
    out << "**** FORM REPORT ****" << std::endl;
    out << "Signed: " << signStatus << std::endl;
    out << "Grade required to sign: " << copy->getGradeToSign() << std::endl;
    out << "Grade required to execute: " << copy->getGradeToExec() << std::endl;
    return (out);
    
}