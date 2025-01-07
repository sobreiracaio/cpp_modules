/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:25:16 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/17 15:43:29 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
    
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &copy);
        ~FragTrap();
        FragTrap &operator=(FragTrap const &copy);
        

        void highFivesGuys(void);
    
    protected:
        static const int startHP = 100;
        static const int startEnergy = 100;
        static const int startDmg = 30;
            
};