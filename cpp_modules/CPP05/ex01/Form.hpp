/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:26:53 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/02 16:04:23 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucat.hpp"

class Form{
    
    private:
        const std::string _name;
        bool _isSigned;
        const int _reqGradeToSign;
        const int _reqGradeToExec;
        
        void _checkGrade(int reqGradeToSign, int reqGradeToExec);
        
    public:
        Form(void);
        Form(std::string name, bool isSigned, int reqGradeToSign, int reqGradeToExec);
        Form(const Form &copy);
        ~Form(void);

        Form &operator=(const Form &copy);
        
        std::string getName(void) const;
        bool getSign(void);
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;

        void beSigned(Bureaucrat &bureaucrat);

        class GradeIsTooHigh : std::exception{
            public:
            const char *what() const throw();
        };
        class GradeIsTooLow : std::exception{
            public:
            const char *what() const throw();
        };
        
    
        
};

std::ostream &operator<<(std::ostream &out, Form *source);

#endif