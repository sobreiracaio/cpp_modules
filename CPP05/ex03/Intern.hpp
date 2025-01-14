/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:40:55 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/13 21:03:22 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern{
    private:

    public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    
    Intern &operator=(const Intern &copy);

    AForm *makeForm(std::string name, std::string target);

    
};

std::ostream &operator<<(std::ostream &out, Intern &copy);