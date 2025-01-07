/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:31:13 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/02 21:06:10 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void proceed(std::string msg)
{
    std::cout << msg << std::endl;
    std::cout << "Press ENTER to proceed." << std::endl;
    std::cin.ignore();
}

int main(void)
{
    proceed("Test 1 - Bureaucrat not skilled enough to sign a form.");
    Bureaucrat *parameter = NULL;
    try
    {
        parameter = new Bureaucrat("John", 120);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << parameter << std::endl;
       
    Form *form = new Form("Parameter Form", 119, 118);

    try
    {
        parameter->signForm(*form);
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << form << std::endl;
    
    proceed("Test 2 - Grade will be incremented");
    parameter->incrementGrade();
    std::cout << parameter << std::endl;

    try
    {
        parameter->signForm(*form);
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << form << std::endl;
    

    
    
  
    
}