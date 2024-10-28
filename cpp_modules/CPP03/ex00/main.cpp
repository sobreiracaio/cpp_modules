/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:53:23 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/28 17:54:24 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printStatus(ClapTrap *trap)
{
    std::cout << *trap << std::endl;
}

void triggerTrap(ClapTrap *trap, std::string enemy, unsigned int dmgTaken, unsigned int amoutRep)
{
    std::cout << "-------------------------- "<<trap->getName()<<" --------------------------" << std::endl;
    while(trap->endGame() == false)
    {
        trap->attack(enemy);
        printStatus(trap);
        trap->takeDamage(dmgTaken);
        printStatus(trap);
        if(trap->endGame() == true)
            break;
        trap->beRepaired(amoutRep);
        printStatus(trap);
        if(trap->endGame() == true)
            break;
    }
    std::cout << "--------------------------FINISH--------------------------" << std::endl << std::endl;
}

int main(void)
{
    ClapTrap trap;
    ClapTrap trap2("Trap 1");
    ClapTrap trap3(trap2);

    triggerTrap(&trap, "enemy 1", 5, 5);
    triggerTrap(&trap2, "enemy 1", 9, 2);
    triggerTrap(&trap3, "enemy 1", 2, 3);
    
}