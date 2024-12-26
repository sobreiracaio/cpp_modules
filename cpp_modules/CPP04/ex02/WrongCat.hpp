/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:03:30 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/18 19:19:47 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    
    private:
        
    public:
        WrongCat();
        WrongCat(WrongCat const &copy);
        WrongCat &operator=(WrongCat const &copy);
        ~WrongCat();
        void makeSound() const;
};

#endif