/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:03:14 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 01:55:24 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
// なぜ、ヒープ領域で確保している？
// 課題の仕様上でもあるし
// 普段感じるヒープ領域であることの利便性と同じ
	: brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
	: Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat class assigned." << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destrucotor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int idx, const std::string &idea)
{
	if (brain)
		brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const
{
	if (!brain)
		return "";
	return brain->getIdea(idx);
}