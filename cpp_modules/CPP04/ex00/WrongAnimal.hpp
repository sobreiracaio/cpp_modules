/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:31:35 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/18 19:15:15 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
    
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &copy);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(WrongAnimal const &copy);
        
        
        std::string getType() const;
        void setType (std::string newType);
        virtual void makeSound() const; 
        
    
};



#endif