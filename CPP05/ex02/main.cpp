/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:31:13 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/09 18:23:26 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void proceed(std::string msg)
{
    std::cout << msg << std::endl;
    std::cout << "Press ENTER to proceed." << std::endl;
    std::cin.ignore();
}

int main(void)
{
    proceed("Test 1 - Bureaucrat not skilled enough to sign or execute a form.");
    Bureaucrat *john = new Bureaucrat("John", 149);
    AForm *sForm = new ShrubberyCreationForm("Joe");
    AForm * rForm = new RobotomyRequestForm("Charles");
    AForm *pForm = new PresidentialPardonForm("Mike");

    try
    {
        sForm->beSigned(*john);
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        sForm->execute(*john);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
   
    delete john;

    
    
  
    
}