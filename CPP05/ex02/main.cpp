/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:31:13 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/14 16:21:36 by crocha-s         ###   ########.fr       */
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
    std::cout << "Press ENTER to proceed.\n" << std::endl;
    std::cin.ignore();
}

const std::string bureaucratName(void)
{
    std::string name;
    while(1)
    {
        std::cout << "Name your bureaucrat: " << std::endl;
        std::getline(std::cin, name);
        if(std::cin.eof())
			break;
        if(name.empty())
		{
			std::cout << "Bureaucrat must be named." << std::endl;
			continue;
		}
        else
            return (name);
    }
    return (name);
}
int bureaucratRank(void)
{
    int rank = 0;
    while(1)
    {
        std::cout << "Grade your bureaucrat: " << std::endl;
        std::cin >> rank;
        if(std::cin.eof())
			break;
        if(std::cin.fail())
		{
			std::cout << "Grade must have a valid number." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			rank = -1;
			continue;
		}            
        else
            return (rank);  
    }
    return (rank);
}

int main(void)
{
    proceed("Setting parameters:");
    const std::string name = bureaucratName();
    int rank = bureaucratRank();
    Bureaucrat *john = NULL;
    
    try
    {
        john = new Bureaucrat(name, rank);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    AForm *sForm = new ShrubberyCreationForm("Joe");
    AForm *rForm = new RobotomyRequestForm("Charles");
    AForm *pForm = new PresidentialPardonForm("Mike");

    proceed("\nTrying to sign and execute Shrubbery Creation Form:");
    
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
    catch(AForm::FormNotSignedException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    proceed("\nTrying to sign and execute Robotomy Request Form:");
    
     try
    {
        rForm->beSigned(*john);
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        rForm->execute(*john);
    }
    catch(AForm::FormNotSignedException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    proceed("\nTrying to sign and execute Presidential Pardon Form:");

     try
    {
        pForm->beSigned(*john);
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        pForm->execute(*john);
    }
    catch(AForm::FormNotSignedException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    delete john;
    delete sForm;
    delete pForm;
    delete rForm;
}