/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:29:51 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/10 15:14:58 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <cstdlib>
#include <ctime>

#define SIZE 10
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define WHITE "\033[0m"

void proceed(std::string msg)
{
    std::cout << GREEN << msg << std::endl;
    std::cout << BLUE << "Press ENTER to proceed." << std::endl;
    std::cout << WHITE;
    std::cin.ignore();
}

void testMessage(std::string msg)
{
    std::cout << BLUE << msg << WHITE <<std::endl;
}


int main ()
{
   { 
        proceed("Seeding arrays for testing:");
        Array<int> slotArr(SIZE);
       
        int *a = new int[SIZE];

        srand(time(NULL));

        for(int i = 0; i < SIZE; i++)
        {
            const int randomNum = rand() % SIZE;
            slotArr[i] = randomNum;
            a[i]= randomNum;
        }
        testMessage("Checking values of Array and int*:");
        for (int i = 0; i < SIZE; i++)
		    {
			    if (slotArr[i] != a[i])
			    {
				    std::cerr  << RED <<"values don't match!!!" << std::endl;
				    return 1;
			    }
		    }
        std::cout << GREEN <<"OK" << std::endl;
        proceed("\nTesting copy constructor and assignment operator:");
        {
            Array<int> refArray = slotArr;
            Array<int> copy(refArray);
            
            testMessage("\nAfter copying before any modification:");
            std::cout << "Original: " << slotArr << std::endl;
            std::cout << "Assigned: " << refArray << std::endl;
            std::cout << "Copy:     " << copy << std::endl;
            testMessage("\nModifying values to test consistency: (modifying values shouldn't effect the other arrays)");
            copy[0] = 657;
            refArray[0]= 450;
            slotArr[0] = 255;
            std::cout << "Original: " << slotArr << std::endl;
            std::cout << "Assigned: " << refArray << std::endl;
            std::cout << "Copy:     " << copy << std::endl;
        }
        proceed("\nTesting try/catches:");
        try
        {
            testMessage("\nTrying to access and change value of an invalid index(negative): ");
            slotArr[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }

        try
        {
            testMessage("\nTrying to access and change value of an invalid index(positive): ");
            slotArr[SIZE] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED  << e.what() << WHITE << '\n';
        }
        delete [] a;
   }
   proceed("\nTesting empty and default Array constructors.");
   {
        Array<int> defaultArr;
        Array<int> emptyArr(0);
    
        try
        {
            testMessage("\nTrying to access index on a default array:");
            defaultArr[0] = 42;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';               
        }
        try
        {
            testMessage("\nTrying to access index on an empty array:");
            emptyArr[0] = 42;
        }
        catch(const std::exception& e)
        {
            std::cerr  << RED << e.what() << WHITE << '\n';               
        }
    }
   proceed("\nSame tests but now using string type:");
   {
       Array<std::string> filledArr(5);
       Array<std::string> defaultArr;
       Array<std::string> emptyArr(0);

       testMessage("Filling Array");
       filledArr[0] = "Lorem";
       filledArr[1] = "Ipsum";
       filledArr[2] = "dolor";
       filledArr[3] = "sit";
       filledArr[4] = "amet";
        
       std::cout << filledArr << std::endl;

        proceed("\nTesting copy constructor and assignment operator:");
        {
            Array<std::string> refArray = filledArr;
            Array<std::string> copy(refArray);
                
            testMessage("\nAfter copying before any modification:");
            std::cout << "Original: " << filledArr << std::endl;
            std::cout << "Assigned: " << refArray << std::endl;
            std::cout << "Copy:     " << copy << std::endl;
            testMessage("\nModifying values to test consistency: (modifying values shouldn't effect the other arrays)");
            copy[0] = "adipiscing";
            refArray[0]= "tempor";
            filledArr[0] = "magna";
            std::cout << "Original: " << filledArr << std::endl;
            std::cout << "Assigned: " << refArray << std::endl;
            std::cout << "Copy:     " << copy << std::endl;
        }
        proceed("\nTesting try/catches:");
        try
        {
            testMessage("Try to access an invalid index on defaultArr:");
            defaultArr[0] = "42";
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }

        try
        {
            testMessage("Try to access an invalid index on emptyArr:");
            emptyArr[0] = "42";
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }

        try
        {
            testMessage("Try to access an invalid index on filledArr:");
            defaultArr[-2] = "lorem";
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << WHITE << '\n';
        }
        proceed("Test with a const sized Array:");
        {
            Array<int> const constArr(5);
            try
            {
                testMessage("Trying to get the size of constArr:");
                std::cout << "Size is: " << constArr.size() << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << RED << e.what() << WHITE << '\n';
            }
        }
    }
    testMessage("**********END**********");
}