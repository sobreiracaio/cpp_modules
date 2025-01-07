/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:27:54 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/03 19:24:27 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void megaphone(char *s)
{
    while(*s)
        std::cout <<(char)toupper(*(s++));
}


int main(int argc, char **argv)
{
   
    if(argc > 1)
    {
        while(*(++argv))
            megaphone(*argv);
            
    }
     
    else
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
std::cout << std::endl;
}