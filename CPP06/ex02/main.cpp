/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:48:37 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/03 19:20:22 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base(){};
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

void proceed(std::string msg)
{
    std::cout << msg << std::endl;
    std::cout << "Press ENTER to proceed." << std::endl;
    std::cin.ignore();
}

Base *generate(void)
{
    int randomNum = std::rand() % 3;
    
    switch (randomNum)
    {
    case 0:
        std::cout << "Instance A created." << std::endl;
        return (new A());
    case 1:
        std::cout << "Instance B created." << std::endl;
        return (new B());
    case 2:
        std::cout << "Instance C created." << std::endl;
        return (new C());
    default:
        return (NULL);
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Its an A class." << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "Its a B class." << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "Its a C class." << std::endl;
    else
        std::cout << "Unrecognizable class." << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Its an A class." << std::endl;
        return;
    }
    catch(const std::exception& e){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Its an B class." << std::endl;
        return;
    }
    catch(const std::exception& e){}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Its an C class." << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cout << "Unrecognizable class." << std::endl; 
    }
    
}

int main (void)
{
    { 
        proceed("Identifying from Pointer test:");
        Base *base;
        for(int i = 0; i < 5; i++)
        {
            base = generate();
            std::cout << "Base Address:" << base << std::endl;
            std::cout << "Base Type: ";
            identify(base);
            std::cout << std::endl;
            delete base;
        }
    }
    {
        proceed("Identifying from Reference test:");
        Base *base;
        for(int i = 0; i < 5; i++)
        {
            base = generate();
            std::cout << "Base Address:" << base << std::endl;
            std::cout << "Base Type: ";
            identify(*base);
            std::cout << std::endl;
            delete base;
        }
    }
    {
		proceed("Unknown type test:");

		Base *nullClass = NULL;
		Base emptyClass;

		std::cout << "Null Pointer Class address: " << nullClass << std::endl;
		std::cout << "Base type: ";
		identify(nullClass);

		std::cout << std::endl;
		std::cout << "Empty Class address: " << &emptyClass << std::endl;
		std::cout << "Base type: ";
		identify(emptyClass);
        
        delete nullClass;		
	}
        
    
}