/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 08:46:39 by msakata           #+#    #+#             */
/*   Updated: 2025/08/18 05:05:38 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << _name << " assigned." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hit_points <= 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack, it has no hit points left." << std::endl;
		return;
	}
	if (_energy_points <= 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack, it has no energy points left." << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "ScavTrap " << _name << " ferociously attacks " << target
		<< ", dealing " << _attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}