/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:31:13 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/12 23:32:15 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    proceed("Test 1 - Bureaucrat not skilled enough to sign a form.", GREEN, YES);
    Bureaucrat *parameter = NULL;
    try
    {
        parameter = new Bureaucrat("John", 120);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }

    std::cout << parameter << std::endl;
       
    Form *form = new Form("Parameter Form", 119, 118);

    try
    {
        parameter->signForm(*form);
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }

    std::cout << form << std::endl;
    std::cin.ignore();
    std::cout << CLEAR;
    proceed("Test 2 - Grade will be incremented", GREEN, YES);
    parameter->incrementGrade();
    std::cout << parameter << std::endl;

    try
    {
        parameter->signForm(*form);
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cerr << RED <<e.what() << WHITE << std::endl;
    }
    std::cout << form << std::endl;

    proceed("Trying to sign an already signed Form", GREEN, YES);
    parameter->signForm(*form);
    
    delete form;
    delete parameter;
    
    proceed("*****                END                *****", RED, NO);
}