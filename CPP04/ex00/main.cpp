/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:50:15 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/18 19:31:33 by crocha-s         ###   ########.fr       */
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
}

int main()
{
    proceed("\n## Constructing Animal objects ##");

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    proceed("\n## Correct animal test ##");

    std::cout << "Animal type is: " << meta->getType() << " and " << meta->getType() << "s ";
    meta->makeSound();
    std::cout << "Animal type is: " << j->getType() << " and " << j->getType() << "s " ;
    j->makeSound();
    std::cout << "Animal type is: " << i->getType() << " and " << i->getType() << "s " ;
    i->makeSound(); 
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    std::cout << "***********" <<std::endl;

    proceed("\n## Constructing wrong animal objects ##");

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongAnimal = new WrongCat();

    proceed("\n## Wrong Animal test ##");

    std::cout << "Animal type is: " << wrongMeta->getType() << " and " << wrongMeta->getType() << "s " ;
    wrongMeta->makeSound();
    std::cout << "Animal type is: " << wrongAnimal->getType() << " and " << wrongAnimal->getType() << "s " ;
    wrongAnimal->makeSound();
    
    delete wrongAnimal;
    delete wrongMeta;

    return (0);
}