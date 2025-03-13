/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:26:58 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/02 16:15:45 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"

#define WHITE	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define CLEAR   "\033c"

#define NO 0
#define YES 1

class AForm;

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
        void _setGrade(int grade);
    public:
        Bureaucrat(void);
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat(void);

        Bureaucrat &operator=(Bureaucrat const &copy);

        std::string getName(void) const;
        int getGrade(void) const;
        
        void incrementGrade(void);
        void decrementGrade(void);

        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
            
        };

        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        
        void signForm(AForm &form);
        void executeForm(AForm &form) const;
                
};

std::ostream &operator<<(std::ostream &out, Bureaucrat *copy);

