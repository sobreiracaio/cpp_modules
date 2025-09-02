/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caio <caio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:49:39 by crocha-s          #+#    #+#             */
/*   Updated: 2025/09/02 13:39:34 by caio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::list<int>	list;
	std::deque<int>	deque;
	double			listTime;
	double			dequeTime;
	
	try
	{
		if (!isValidInput(av) || ac == 1)
			throw std::runtime_error(ERROR);
		++av;
		printBefore(av);
		sortList(list, av, listTime);
		sortDeque(deque, av, dequeTime);
		printListAfter(list);
		// printDequeAfter(deque);
		std::cout << "Time to process a range of " << list.size() << " elements with std::list  : " << listTime << " miliseconds" << std::endl;
		std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << dequeTime << " miliseconds" << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}