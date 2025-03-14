/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:38:12 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/14 16:21:04 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):AForm("RobotomyRequestForm",72, 45),_target(target)
{
    std::cout << "Robotomy default Request Form has been created, target: " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy):AForm("RobotomyRequestForm",72, 45),_target(copy.getTarget())
{
    std::cout << "Robotomy Request Form created, source: " << copy.getName() << std::endl;
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy request form deleted :" << this->getName() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    std::cout << this->getName() << "received data from " << copy.getName() << std::endl;
    if(this == &copy)
        return (*this);
    return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
    if(bureaucrat.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
        
    else if(!this->getSign())
        throw AForm::FormNotSignedException();
    else
    {
        static int Attempt = 0;
        std::cout << "Bzzzzzbzzzzzbzzzzz..." << std::endl;
        
        if(Attempt++ % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully!" << std::endl;
        else
            std::cout <<"Shhhh something went wrong...Robotomy failed."<< std::endl;
        
    }
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *copy)
{
    std::string isSigned = copy->getSign() ? "is signed." : "is not signed";
    out << "Name: " << copy->getName() << std::endl;
    out << "Sign rank: " << copy->getGradeToSign() << std::endl;
    out << "Execute rank: " << copy->getGradeToExec() << std::endl;
    return (out);
}
