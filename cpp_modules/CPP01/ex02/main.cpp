/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:54:36 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/14 22:04:57 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *strPtr = &string;
    std::string &strRef = string;

    std::cout << "Adresses of: " << std::endl;
    std::cout << "string: " << &string << std::endl;
    std::cout << "strPtr: " << strPtr << std::endl;
    std::cout << "strRef: " << &strRef << std::endl;

    std::cout << "Contents of: " << std::endl;
    std::cout << "string: " << string << std::endl;
    std::cout << "strPtr: " << *strPtr << std::endl;
    std::cout << "strRef: " << strRef << std::endl;
}