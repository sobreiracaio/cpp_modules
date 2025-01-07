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

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongAnimal = new WrongCat();

    std::cout << j->getType();
    j->makeSound();
    std::cout << i->getType();
    i->makeSound(); 
    meta->makeSound();

    std::cout << wrongAnimal->getType();
    wrongAnimal->makeSound();
    wrongMeta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    delete wrongAnimal;
    delete wrongMeta;

    return (0);
}