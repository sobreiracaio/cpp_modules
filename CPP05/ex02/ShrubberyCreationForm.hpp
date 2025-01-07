/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:16:02 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/07 22:05:36 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : virtual public AForm {
  private:
    std::string const _target;
    ShrubberyCreationForm();
    
  public:
    ShrubberyCreationForm(std::string const target);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    ~ShrubberyCreationForm();
    
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
    
    std::string getTarget (void) const;
    
    virtual void execute(Bureaucrat const &bureaucrat) const;
   
    
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *copy);