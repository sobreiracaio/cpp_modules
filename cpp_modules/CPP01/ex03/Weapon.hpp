/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:55:14 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/14 22:58:46 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
    
    public:
            Weapon();
            ~Weapon();
            const std::string getType();
            void setType(std::string newType);
            
    private:
            std::string _type;
    
};

#endif