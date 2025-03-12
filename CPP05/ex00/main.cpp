/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:31:13 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/12 22:17:59 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void proceed(std::string msg, std::string color, bool has_enter)
{
    std::cout << color << msg << WHITE << std::endl;
    if(has_enter == YES)
    {
        std::cout << "Press " << GREEN << "ENTER " << WHITE << "to proceed."  << std::endl;
        std::cin.ignore();
    }
}

int main(void)
{
    std::cout << CLEAR;
    proceed("#Basic test - default constructor#", GREEN, YES);
    Bureaucrat *defaultBureaucrat = NULL;
    try
    {
        defaultBureaucrat = new Bureaucrat ();
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    
    std::cout << defaultBureaucrat << std::endl << std::endl;
    std::cin.ignore();
    std::cout << CLEAR;
    proceed("#Basic test - Increment rank test#", GREEN, YES);
    try
    {
        defaultBureaucrat->incrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    std::cout << defaultBureaucrat << std::endl << std::endl;

    defaultBureaucrat->decrementGrade();
    
    std::cin.ignore();
    std::cout << CLEAR;
    proceed("#Basic test - decrement rank test (grade restored to default = 150)#", GREEN, YES);
    try
    {
        defaultBureaucrat->decrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    
    std::cout << defaultBureaucrat << std::endl << std::endl;

    defaultBureaucrat->incrementGrade();
    delete defaultBureaucrat;
    
    
    std::cin.ignore();
    std::cout << CLEAR;
    proceed("#Basic test - increment rank test#", GREEN, YES);
    Bureaucrat *parameterBureaucrat = new Bureaucrat("Parameter", 1);
    try
    {
        parameterBureaucrat->incrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    
    std::cout << parameterBureaucrat << std::endl << std::endl;
    
    delete parameterBureaucrat;
    
    std::cin.ignore();
    std::cout << CLEAR;
    proceed("Invalid grade constructor test", GREEN, YES);
    Bureaucrat *invalidGrade = NULL;

    try
    {
        invalidGrade = new Bureaucrat("Invalid grade bureaucrat", 151);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    
    delete invalidGrade;
    invalidGrade = NULL;
    try
    {
        invalidGrade = new Bureaucrat ("Invalid grade bureaucrat", 0);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    
    delete invalidGrade;
    proceed("*****             END             *****", RED, NO);
    
    
}