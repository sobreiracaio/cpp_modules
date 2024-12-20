/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:50:15 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/20 19:50:04 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Dog.hpp"
// #include "Cat.hpp"
// #include "WrongCat.hpp"

// void proceed(std::string msg)
// {
//     std::cout << msg << std::endl;
//     std::cout << "Press ENTER to proceed." << std::endl;
//     std::cin.ignore();
//     std::cout << std::endl;
// }

// int main()
// {
//     proceed("Array Test:");
//     Animal *animals[4] = {new Dog, new Dog, new Cat, new Cat};
    
//     for (int i = 0; i < 4; i++)
//     {
//         std::cout<< "Animal " << animals[i]->getType() << "has been destroyed." << std::endl;
//         delete animals[i];
//     }
//     proceed("Shallow copy test:");
//     {
//         Dog original;
//         {
//             Dog copy = original;
//             std::cout << "Copy address is: " << copy.getBrain() << std::endl;
//         }
//         std::cout << "Original address is: " << original.getBrain() << std::endl;
//     }
//     proceed("Deep copy test:");
    
    // Dog *rex = new Dog;
    // Dog *rexClone = new Dog(*rex);

    // std::cout << "Rex address is: " << rex->getBrain() << std::endl;
    // std::cout << "Rex clone address is: " << rexClone->getBrain() << std::endl;

    // delete rex;
    // delete rexClone;

    // Cat *tom = new Cat;
    // Cat *tomClone = new Cat(*tom);

    // std::cout << "Tom address is: " << tom->getBrain() << std::endl;
    // std::cout << "Tom clone clone address is: " << tomClone->getBrain() << std::endl;

    // delete tom;
    // delete tomClone;
    
//     return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:24:39 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 16:16:58 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << "************************************" << std::endl << "*";
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << message;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << "*" << std::endl << "************************************" << std::endl << std::endl;
}

int main()
{
	titleHeader("ANIMAL ARRAY TEST");

	Animal	*animals[6] =
	{
		new Dog(), new Dog(), new Dog(),
		new Cat(), new Cat(), new Cat()
	};

	for (int i = 0; i < 6; i++)
	{
		std::cout << std::endl << "Destroy Animal " << i + 1 << std::endl;	
		delete animals[i];
	}
	pressEnter();

	titleHeader("BASIC COPY TEST");
	{
		Dog basic;
		{
			Dog tmp = basic;
			std::cout << std::endl << "Tmp's Brain Adress  : " << tmp.getBrain() << std::endl;
		}
		std::cout << std::endl << "Basic's Brain Adress: " << basic.getBrain() << std::endl;
	}
	pressEnter();

	titleHeader("CAT DEEP COPY TEST");
	Cat *original = new Cat();
	Cat *copy = new Cat(*original);

	std::cout << std::endl << "Original's Brain Adress: " << original->getBrain() << std::endl;
	
	delete original;
	
	std::cout << std::endl << "Copy's Brain Adress: " << copy->getBrain() << std::endl;
	
	delete copy;
	pressEnter();
	
	titleHeader("DOG DEEP COPY TEST");
	Dog *originalDog = new Dog();
	Dog *copyDog = new Dog(*originalDog);
	
	std::cout << std::endl << "Original's Brain Adress: " << originalDog->getBrain() << std::endl;
	
	delete originalDog;

	std::cout << std::endl << "Copy's Brain Adress: " << copyDog->getBrain() << std::endl;
	
	delete copyDog;
	pressEnter();
}