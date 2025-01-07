/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:38:12 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/07 00:12:43 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):AForm("PresidentialPardonForm",25, 5),_target(target)
{
    std::cout << "Presidential default Pardon Form has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
{
    std::cout << "Presidential Pardon Form created, source: " << copy.getName() << std::endl;
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Pardon form deleted :" << this->getName();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
    std::cout << this->getName() << "received data from " << copy.getName() << std::endl;
    if(this == &copy)
        return (*this);
    return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
    if(bureaucrat.getGrade() < this->getGradeToExec())
        throw AForm::GradeTooLowException();
        
    else if(!this->getSign())
        throw AForm::FormNotSignedException();
    else
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
        
    
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *copy)
{
    std::string isSigned = copy->getSign() ? "is signed." : "is not signed";
    out << "Name: " << copy->getName() << std::endl;
    out << "Sign rank: " << copy->getGradeToSign() << std::endl;
    out << "Execute rank: " << copy->getGradeToExec() << std::endl;
    return (out);
}
