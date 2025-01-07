/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:31:13 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/07 21:08:26 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
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
    proceed("Test 1 - Bureaucrat not skilled enough to execute a form.");
    Bureaucrat *john = new Bureaucrat("John", 149);
    ShrubberyCreationForm *sForm = new ShrubberyCreationForm("Joe");
    //RobotomyRequestForm * rForm = new RobotomyRequestForm("Charles");
    //PresidentialPardonForm *pForm = new PresidentialPardonForm("Mike");

    try
    {
        sForm->execute(*john);
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::FormNotSignedException &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    

    
    
  
    
}