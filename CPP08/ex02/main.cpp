/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:42:36 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/18 23:26:56 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#define WHITE	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define CLEAR   "\033c"

#define NO 0
#define YES 1

void proceed(std::string msg, std::string color, bool has_enter)
{
    std::cout << color << msg << WHITE << std::endl;
    if(has_enter == YES)
    {
        std::cout << "Press " << GREEN << "ENTER " << WHITE << "to proceed."  << std::endl;
        std::cin.ignore();
    }
}

int main ()
{
    std::cout << CLEAR;
    proceed("MutantStack test:", BLUE, YES);
    {
        MutantStack<int> mstack;
        
        proceed("Inserting data in stack:", YELLOW, NO);
        proceed("Inserting 5, 23, 72 in this order...",GREEN,NO);
        mstack.push(5);
        mstack.push(23);
        mstack.push(72);
        std::cout << BLUE << "Contents are: " << WHITE;
        mstack.printContent();
        
        proceed("Using features: ", YELLOW, NO);
        proceed("Top value, Size and Pop: ", GREEN, NO);
        std::cout << BLUE << "Top value: "<< WHITE << mstack.top() << std::endl;
        std::cout << BLUE << "Size: "<< WHITE << mstack.size() << std::endl;
        proceed("Stack before pop:", BLUE, NO);
        std::cout << BLUE << "Contents are: " << WHITE;
        mstack.printContent();
        proceed("Popping first value...", YELLOW, NO);
        mstack.pop();
        proceed("Stack after pop:", BLUE, NO);
        std::cout << BLUE << "Contents are: " << WHITE;
        mstack.printContent();
        std::cout << BLUE << "Size: "<< WHITE << mstack.size() << std::endl;

        proceed("Inserting more data on stack:", YELLOW, NO);
        proceed("Inserting 59, 11, 87, 45 in this order...",GREEN,NO);

        mstack.push(59);
        mstack.push(11);
        mstack.push(87);
        mstack.push(45);
        std::cout << BLUE << "Contents are: " << WHITE; 
        mstack.printContent();
        
        proceed("Playing around with iterators:",GREEN,NO);

        MutantStack<int>::iter it = mstack.begin();
        
        proceed("Incrementing it by 1:",YELLOW,NO);
        std::cout << BLUE << "Value before increment: " << WHITE << *it << std::endl;
        it++;
        std::cout << BLUE << "Value after increment: " << WHITE << *it << std::endl;
        proceed("Decrementing it by 1:",YELLOW,NO);
        it--;
        std::cout << BLUE << "Value after decrement: " << WHITE << *it << std::endl;
        std::cout << BLUE << "Contents of mstack are: " << WHITE; 
        mstack.printContent();
        
        proceed("Creating a copy of mstack to a standard stack", BLUE, NO);
        std::stack<int> stack(mstack);

        MutantStack<int>::iter itE;
        std::cout << BLUE << "Contents of standart stack are: " << WHITE;
        std::cout << " { ";
        while(!stack.empty())
        {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << "}" << std::endl;
    }
    proceed("", WHITE, YES);
    std::cout << CLEAR;
    {
        proceed("Same test but with list:", BLUE, YES);
        std::list<int> list;
        
        proceed("Inserting data in the list:", YELLOW, NO);
        proceed("Inserting 5, 23, 72 in this order...",GREEN,NO);
        list.push_back(5);
        list.push_back(23);
        list.push_back(72);
        std::cout << BLUE << "Contents are: " << WHITE;
        printContent(list);

        proceed("Using features: ", YELLOW, NO);
        proceed("'Top value', Size and Pop: ", GREEN, NO);
        std::cout << BLUE << "Top value: "<< WHITE << list.back() << std::endl;
        std::cout << BLUE << "Size: "<< WHITE << list.size() << std::endl;
        proceed("Stack before pop:", BLUE, NO);
        std::cout << BLUE << "Contents are: " << WHITE;
        printContent(list);
        proceed("Popping first value...", YELLOW, NO);
        list.pop_back();
        proceed("Stack after pop:", BLUE, NO);
        std::cout << BLUE << "List contents are: " << WHITE;
        printContent(list);
        std::cout << BLUE << "Size: "<< WHITE << list.size() << std::endl;

        proceed("Inserting more data in the list:", YELLOW, NO);
        proceed("Inserting 59, 11, 87, 45 on this order...",GREEN,NO);

        list.push_back(59);
        list.push_back(11);
        list.push_back(87);
        list.push_back(45);
        std::cout << BLUE << "List contents are: " << WHITE; 
        printContent(list);

        proceed("Playing around with iterators:",GREEN,NO);

        std::list<int>::iterator it = list.begin();
        
        proceed("Incrementing it by 1:",YELLOW,NO);
        std::cout << BLUE << "Value before increment: " << WHITE << *it << std::endl;
        it++;
        std::cout << BLUE << "Value after increment: " << WHITE << *it << std::endl;
        proceed("Decrementing it by 1:",YELLOW,NO);
        it--;
        std::cout << BLUE << "Value after decrement: " << WHITE << *it << std::endl;
        std::cout << BLUE << "List contents are: " << WHITE; 
        printContent(list);
    }

    std::cout << RED << " \n********************* END ********************* " << std::endl;

}