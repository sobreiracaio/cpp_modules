/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:14:47 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/04 18:36:05 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

bool checkNumber(std::string &input);
bool checkSignals(std::string &input);
void calculate(std::string const &input, std::stack<int> &stack);
void addNb(std::string const &input, std::stack<int> &stack);
void rpn(std::string const &input);
