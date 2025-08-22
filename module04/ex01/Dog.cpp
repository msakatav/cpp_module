/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:03:20 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 01:42:32 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
	: Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		// newは何を渡している？
		// newに渡しているのは、Brainであり、
		// 同時にコピーコンストラクタを呼び出しているだけ
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog class assigned" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int idx, const std::string &idea)
{
	if (brain)
		brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const
{
	if (!brain)
		return "";
	return brain->getIdea(idx);
}