/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:53:52 by crocha-s          #+#    #+#             */
/*   Updated: 2025/02/24 18:27:49 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <climits>
#include <stdexcept>

#define WHITE	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define CLEAR   "\033c"


class BitcoinExchange {
    
    private:
        std::string _fileName;
        std::string _rawData;
        std::vector<std::string> _parsedData;
    public:
        BitcoinExchange(std::string file);
        //BitcoinExchange(const BitcoinExchange &copy);
        ~BitcoinExchange();
        //BitcoinExchange &operator=(BitcoinExchange const &source);
        
        void readFromFile();
        //std::vector<std::string> parseAndPopulate();
    
};

