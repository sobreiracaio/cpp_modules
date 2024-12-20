/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:50:15 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/20 21:17:11 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void proceed(std::string msg)
{
    std::cout << msg << std::endl;
    std::cout << "Press ENTER to proceed." << std::endl;
    std::cin.ignore();
    std::cout << std::endl;
}

int main()
{
    proceed("Array Test:");
    Animal *animals[4] = {new Dog, new Dog, new Cat, new Cat};
    
    for (int i = 0; i < 4; i++)
    {
        std::cout<< "Animal " << animals[i]->getType() << "has been destroyed." << std::endl;
        delete animals[i];
    }
    proceed("Shallow copy test:");
    {
        Dog original;
        {
            Dog copy = original;
            std::cout << "Copy address is: " << copy.getBrain() << std::endl;
        }
        std::cout << "Original address is: " << original.getBrain() << std::endl;
    }
    proceed("Deep copy test:");
    
    Dog *rex = new Dog;
    Dog *rexClone = new Dog(*rex);

    std::cout << "Rex address is: " << rex->getBrain() << std::endl;
    std::cout << "Rex clone address is: " << rexClone->getBrain() << std::endl;

    delete rex;
    delete rexClone;

    Cat *tom = new Cat;
    Cat *tomClone = new Cat(*tom);

    std::cout << "Tom address is: " << tom->getBrain() << std::endl;
    std::cout << "Tom clone address is: " << tomClone->getBrain() << std::endl;

    delete tom;
    delete tomClone;
    
    return (0);
}

