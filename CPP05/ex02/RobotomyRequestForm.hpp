/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:57:26 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/06 23:40:02 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: virtual public AForm{
    private:
        const std::string _target;
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
        
        std::string getTarget() const;
        
        virtual void execute(Bureaucrat const &bureaucrat) const;
        
       
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *copy);
