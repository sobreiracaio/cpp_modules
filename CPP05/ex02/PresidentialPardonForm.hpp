/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:57:26 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/06 22:26:42 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: virtual public AForm{
    private:
        const std::string _target;
        PresidentialPardonForm();

    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
        
        std::string getTarget() const;
        
        virtual void execute(Bureaucrat const &bureaucrat) const;
        
       
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *copy);
