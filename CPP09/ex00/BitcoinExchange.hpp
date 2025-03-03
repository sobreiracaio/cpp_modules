/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:53:52 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/03 16:23:52 by crocha-s         ###   ########.fr       */
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


typedef struct data
        {
            std::tm date;
            float exchange_rate;
            float amount;
        }btcData;

bool checkDate(btcData &btc, std::string const &date);
bool checkValue(btcData &btc, std::string const &tmp);
std::vector<btcData> readDB(void);
int dateComparison(std::tm const &dbDate, std::tm const &refDate);
float exchangeResult(std::vector<btcData> const &database, btcData const &reference);
void readFromFile(std::vector<btcData> &btc, std::string const &filename);
