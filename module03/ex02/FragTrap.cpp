/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:24:47 by msakata           #+#    #+#             */
/*   Updated: 2025/08/18 01:01:17 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap " << _name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << _name << " assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructed." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_hit_points <= 0)
	{
		std::cout << "FragTrap " << _name << " cannot attack, it has no hit points left." << std::endl;
		return;
	}
	if (_energy_points <= 0)
	{
		std::cout << "FragTrap " << _name << " cannot attack, it has no energy points left." << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "FragTrap " << _name << " powerfully attacks " << target
		<< ", dealing " << _attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
}