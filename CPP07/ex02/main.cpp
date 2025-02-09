/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:29:51 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/09 14:57:03 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <cstdlib>
#include <ctime>

#define SIZE 10

void proceed(std::string msg)
{
    std::cout << msg << std::endl;
    std::cout << "Press ENTER to proceed." << std::endl;
    std::cin.ignore();
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
        std::cout << "Checking values of Array and int*:";
        for (int i = 0; i < SIZE; i++)
		    {
			    if (slotArr[i] != a[i])
			    {
				    std::cerr << "values don't match!!!" << std::endl;
				    return 1;
			    }
		    }
        std::cout << " OK" << std::endl;
        proceed("Testing copy constructor and assignment operator:");
        {
            Array<int> refArray = slotArr;
            Array<int> copy(refArray);
            
            std::cout << "\nAfter copying before any modification:" << std::endl;
            std::cout << "Original: " << slotArr << std::endl;
            std::cout << "Assigned: " << refArray << std::endl;
            std::cout << "Copy:     " << copy << std::endl;
            std::cout << "\nModifying values to test consistency: (modifying values shouldn't effect the other arrays)" << std::endl;
            copy[0] = 657;
            refArray[0]= 450;
            slotArr[0] = 255;
            std::cout << "Original: " << slotArr << std::endl;
            std::cout << "Assigned: " << refArray << std::endl;
            std::cout << "Copy:     " << copy << std::endl;
        }
        proceed("Testing try/catches:");
        try
        {
            std::cout <<"Trying to access and change value of an invalid index(negative): " << std::endl;
            slotArr[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            std::cout <<"\nTrying to access and change value of an invalid index(positive): " << std::endl;
            slotArr[SIZE] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete [] a;
   }
}