/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:43:18 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 01:30:09 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain construcotr called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain class assigned" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int idx, const std::string &idea)
{
	if (idx < 0 || idx >= 100)
		return;
	ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
		return "";
	return ideas[idx];
}