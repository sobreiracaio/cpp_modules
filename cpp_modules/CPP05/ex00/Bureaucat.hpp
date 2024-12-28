/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:26:58 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/28 19:47:51 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
        void _setGrade(int grade);
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
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
                
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &copy);

#endif