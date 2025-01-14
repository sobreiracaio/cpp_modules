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
#include "AForm.hpp"

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

