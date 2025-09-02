/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caio <caio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:49:47 by crocha-s          #+#    #+#             */
/*   Updated: 2025/09/02 13:40:17 by caio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// --------------------------------------- common functions ---------------------------------------

bool isValidNumber(std::string const &in)
{
	double nb = std::atof(in.c_str());

	if (in.empty() || (in.find_first_not_of(VALID_SET) != std::string::npos)
		|| nb < 0 || nb > (double)INT_MAX)
		return (false);
	return (true);	
}

bool isValidInput(char **av)
{
	for (int i = 1; av[i]; i++)
		if (!isValidNumber(av[i]))
			return (false);
	return (true);
}

void printBefore(char **av)
{
	std::cout << "Before:\t";
	for (int i = 0; av[i]; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
}

// --------------------------------------- list functions ---------------------------------------

void fillList(std::list<int> &list, char **av)
{
	for (int i = 0; av[i]; i++)
		list.push_back(std::atoi(av[i]));
}

void listInsert(std::list<int> &sorted, int const &nb)
{
	std::list<int>::iterator it;

	for (it = sorted.begin(); it != sorted.end(); it++)
	{
		if (*it > nb)
		{
			sorted.insert(it, nb);
			return ;
		}
	}
	sorted.insert(it, nb);
}

void listInsertionSort(std::list<int> &list)
{
	std::list<int> sorted;

	while (!list.empty())
	{
		int nb = list.front();
		list.pop_front();
		listInsert(sorted, nb);
	}
	list.swap(sorted);
}

void listMergeInsertionSort(std::list<int> &list)
{
	if (list.size() <= LIMITER)
	{
		listInsertionSort(list);
		return ;
	}
	std::list<int> left, right;
	int middle = list.size() / 2;
	for (int i = 0; i < middle; i++)
	{
		left.push_back(list.front());
		list.pop_front();
	}
	right = list;

	listMergeInsertionSort(left);
	listMergeInsertionSort(right);

	list.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(list));

}

void sortList(std::list<int> &list, char **av, double &time)
{
	clock_t start = clock();

	fillList(list, av);
	listMergeInsertionSort(list);

	clock_t end = clock();
	time = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
}

void printListAfter(std::list<int> &list)
{
	std::list<int>::const_iterator it;

	std::cout << "After:\t";
	for (it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// --------------------------------------- deque functions ---------------------------------------

void fillDeque(std::deque<int> &deque, char **av)
{
	for (int i = 0; av[i]; i++)
		deque.push_back(std::atoi(av[i]));
}

void printDequeAfter(std::deque<int> &deque)
{
	std::deque<int>::const_iterator it;

	std::cout << "After:\t";
	for (it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void dequeInsert(std::deque<int> &sorted, int const &nb)
{
	std::deque<int>::iterator it;

	for (it = sorted.begin(); it != sorted.end(); it++)
	{
		if (*it > nb)
		{
			sorted.insert(it, nb);
			return ;
		}
	}
	sorted.insert(it, nb);
}

void dequeInsertionSort(std::deque<int> &deque)
{
	std::deque<int> sorted;

	while (!deque.empty())
	{
		int nb = deque.front();
		deque.pop_front();
		dequeInsert(sorted, nb);
	}
	deque.swap(sorted);
}

void dequeMergeInsertionSort(std::deque<int> &deque)
{
	if (deque.size() <= LIMITER)
	{
		dequeInsertionSort(deque);
		return ;
	}
	std::deque<int> left, right;
	int middle = deque.size() / 2;
	for (int i = 0; i < middle; i++)
	{
		left.push_back(deque.front());
		deque.pop_front();
	}
	right = deque;

	dequeMergeInsertionSort(left);
	dequeMergeInsertionSort(right);

	deque.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(deque));
}

void sortDeque(std::deque<int> &deque, char **av, double &time)
{
	clock_t start = clock();

	fillDeque(deque, av);
	dequeMergeInsertionSort(deque);

	clock_t end = clock();
	time = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
}