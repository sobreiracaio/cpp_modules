/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:30:24 by crocha-s          #+#    #+#             */
/*   Updated: 2025/01/12 14:20:40 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

std::string searchAndReplace(std::string line, std::string searchFor, std::string replacement)
{
    size_t position = 0;
    while(1)
    {
        position = line.find(searchFor, position);
        if(position == std::string::npos)
            break;
        line.erase(position, searchFor.length());
        line.insert(position,replacement);
        position += replacement.length();
    }
    return (line);
}

int main (int argc, char **argv)
{
    std::string fileName;
    std::string searchFor;
    std::string replacement;
    std::fstream outFile;
    std::fstream file;
    
    
    if(argc != 4)
    {
        std::cout << "Error: Try './sed_is_for_loosers <filename> <arg1> <arg2>'." << std::endl;
        return (1);
    }
    
    
    fileName = argv[1];
    searchFor = argv[2];
    
    if(searchFor.empty())
        {
            std::cout << "Empty strings are not allowed." << std::endl;
            exit(1);
        }
        
    replacement = argv[3];
        
    file.open(fileName.c_str(), std::ios::in);
    
    if(file.is_open())
        {
            outFile.open((fileName + ".replacement").c_str(), std::ios::out);
            std::string line;
            while(std::getline(file, line))
            {
                line = searchAndReplace(line, searchFor, replacement);
                outFile << line << std::endl;
            }
            file.close();
            outFile.close();
        }
    else
        {
            std::cout << "Error opening file." << std::endl;
            file.close();
            // outFile.close();
            exit(1);
        }
    return (0);
}