/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:31:13 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/30 19:55:33 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucat.hpp"

void proceed(std::string msg)
{
    std::cout << msg << std::endl;
    std::cout << "Press ENTER to proceed." << std::endl;
    std::cin.ignore();
    //std::cout << std::endl;
}

int main(void)
{
    proceed("#Basic test - default constructor#");
    Bureaucrat *defaultBureaucrat = NULL;
    try
    {
        defaultBureaucrat = new Bureaucrat ();
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << defaultBureaucrat << std::endl << std::endl;
    
    proceed("#Basic test - Increment rank test#");
    try
    {
        defaultBureaucrat->incrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << defaultBureaucrat << std::endl << std::endl;

    defaultBureaucrat->decrementGrade();

    proceed("#Basic test - decrement rank test (grade restored to default)#");

    try
    {
        defaultBureaucrat->decrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << defaultBureaucrat << std::endl << std::endl;

    defaultBureaucrat->incrementGrade();
    delete defaultBureaucrat;
    
    Bureaucrat *parameterBureaucrat = new Bureaucrat("Parameter", 1);
    proceed("#Basic test - increment rank test#");
    try
    {
        parameterBureaucrat->incrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << parameterBureaucrat << std::endl << std::endl;
    
    delete parameterBureaucrat;

    proceed("Invalid grade constructor test");

    Bureaucrat *invalidGrade = NULL;

    try
    {
        invalidGrade = new Bureaucrat("Invalid grade bureaucrat", 151);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << '\n';
    }
    
    delete invalidGrade;
    invalidGrade = NULL;
    try
    {
        invalidGrade = new Bureaucrat ("Invalid grade bureaucrat", 0);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << '\n';
    }
    
    delete invalidGrade;
    
  
    
}