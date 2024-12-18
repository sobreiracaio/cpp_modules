/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:03:30 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/18 18:03:00 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal{
    
    private:
        
    public:
        Dog();
        Dog(Dog const &copy);
        Dog &operator=(Dog const &copy);
        ~Dog();
        void makeSound() const;
};

#endif