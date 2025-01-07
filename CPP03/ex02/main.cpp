/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:53:23 by crocha-s          #+#    #+#             */
/*   Updated: 2024/11/07 17:21:48 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void printStatus(FragTrap *trap)
{
    std::cout << *trap << std::endl;
}

void triggerTrap(FragTrap *trap, std::string enemy, unsigned int dmgTaken, unsigned int amoutRep)
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
        trap->highFivesGuys();
        if(trap->endGame() == true)
            break;
    }
    std::cout << "--------------------------FINISH--------------------------" << std::endl << std::endl;
}

int main(void)
{
    FragTrap trap;
    FragTrap trap2("Trap 1");
    FragTrap trap3(trap2);

    triggerTrap(&trap, "enemy 1", 5, 5);
    triggerTrap(&trap2, "enemy 1", 9, 2);
    triggerTrap(&trap3, "enemy 1", 2, 3);
    
}