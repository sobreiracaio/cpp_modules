/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:26:53 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/06 20:13:25 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    
    private:
        const std::string _name;
        bool _isSigned;
        const int _reqGradeToSign;
        const int _reqGradeToExec;
        
        void _checkGrade(int reqGradeToSign, int reqGradeToExec);
        
    public:
        AForm(void);
        AForm(std::string name, int reqGradeToSign, int reqGradeToExec);
        AForm(const AForm &copy);
        virtual ~AForm(void);

        AForm &operator=(const AForm &copy);
        
        std::string getName(void) const;
        bool getSign(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        void beSigned(Bureaucrat &bureaucrat);

        void virtual execute (Bureaucrat const &Bureaucrat) const = 0;

        class GradeTooHighException : std::exception{
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : std::exception{
            public:
                const char *what() const throw();
        };
        class FormNotSignedException : std::exception{
            public:
                const char *what() const throw();
        };
    
        
};

std::ostream &operator<<(std::ostream &out, AForm *source);

#endif