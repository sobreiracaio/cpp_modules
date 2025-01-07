/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:31:35 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/26 16:00:36 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
    
    protected:
        std::string type;
    public:
        Animal();
        Animal(Animal const &copy);
        virtual ~Animal();
        Animal &operator=(Animal const &copy);
        
        
        std::string getType() const;
        void setType (std::string newType);
        virtual void makeSound() const = 0 ; 
        
    
};



#endif