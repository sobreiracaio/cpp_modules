/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:03:30 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/20 19:12:22 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal{
    
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(Dog const &copy);
        Dog &operator=(Dog const &copy);
        virtual ~Dog();
        void makeSound() const;
        Brain *getBrain () const;
};

#endif