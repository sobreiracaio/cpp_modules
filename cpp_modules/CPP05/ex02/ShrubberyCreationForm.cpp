/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:47:56 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/06 20:43:49 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target): AForm("ShrubberyCreationForm",145, 137),_target(target)
{
    std::cout << "Shrubbery Creation Form created: " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm("ShrubberyCreationForm",145, 137),_target(copy.getTarget())
{
    std::cout<<"Shrubbery Creation Form copy created, source: " << copy.getTarget() << std::endl;
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery Creation form has been destroyed: " << this->getTarget() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
    std::cout << "Shrubbery assignment operator called. " << this->getName() << "will receive data from "<< copy.getName() << "." << std::endl;
    if (this == &copy)
        return (*this);
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return(this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
    if(bureaucrat.getGrade() < this->getGradeToExec())
        throw Bureaucrat::GradeTooLowException();
    else if(!this->getSign())
        throw AForm::FormNotSignedException();
    else
    {
        std::ofstream file (this->getTarget().append("_shrubbery").c_str());

        for (int i = 0; i = 3; i++)
        {
            file << "    *    " << std::endl;
            file << "   ***   " << std::endl;
            file << "  *****  " << std::endl;
            file << " *******  " << std::endl;
            file << "    *  " << std::endl;
        }
        file.close();
    }
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *copy)
{
    std::string isSigned = copy->getSign() ? "is signed." : "is not signed";
    out << "Name: " << copy->getName() << std::endl;
    out << "Sign rank: " << copy->getGradeToSign() << std::endl;
    out << "Execute rank: " << copy->getGradeToExec() << std::endl;
    return (out);
}