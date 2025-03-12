/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:31:13 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/12 23:37:33 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void proceed(std::string msg, std::string color, bool has_enter)
{
    std::cout << color << msg << WHITE << std::endl;
    if(has_enter == YES)
    {
        std::cout << "Press " << GREEN << "ENTER " << WHITE << "to proceed."  << std::endl;
        std::cin.ignore();
    }
}


const std::string bureaucratName(void)
{
    std::string name;
    while(1)
    {
        proceed("Name your bureaucrat: ", GREEN, NO);
        std::getline(std::cin, name);
        if(std::cin.eof())
			break;
        if(name.empty())
		{
			proceed("Bureaucrat must be named.", RED, NO);
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
        proceed("Grade your bureaucrat: ", GREEN, NO);
        std::cin >> rank;
        if(std::cin.eof())
			break;
        if(std::cin.fail())
		{
			proceed("Grade must have a valid number.", RED, NO);
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
    std::cout << CLEAR;
    proceed("Setting parameters:", GREEN, YES);
    const std::string name = bureaucratName();
    int rank = bureaucratRank();
    Bureaucrat *john = NULL;
    
    try
    {
        john = new Bureaucrat(name, rank);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    
    AForm *sForm = new ShrubberyCreationForm("Joe");
    AForm *rForm = new RobotomyRequestForm("Charles");
    AForm *pForm = new PresidentialPardonForm("Mike");

    std::cin.ignore();
    std::cout << CLEAR;
    proceed("\nTrying to sign and execute Shrubbery Creation Form:", GREEN, YES);
    
    try
    {
        sForm->beSigned(*john);
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    try
    {
        sForm->execute(*john);
    }
    catch(AForm::FormNotSignedException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    std::cout << sForm;
    std::cin.ignore();
    std::cout << CLEAR;
    proceed("\nTrying to sign and execute Robotomy Request Form:", GREEN, YES);
    
    try
    {
        rForm->beSigned(*john);
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    try
    {
        rForm->execute(*john);
    }
    catch(AForm::FormNotSignedException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    std::cout << rForm;
    std::cin.ignore();
    std::cout << CLEAR;
    proceed("\nTrying to sign and execute Presidential Pardon Form:", GREEN, YES);

    try
    {
        pForm->beSigned(*john);
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    try
    {
        pForm->execute(*john);
    }
    catch(AForm::FormNotSignedException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    std::cout << pForm;
    std::cin.ignore();
    delete john;
    delete sForm;
    delete pForm;
    delete rForm;

    proceed("*****                END                *****", RED, NO);
}