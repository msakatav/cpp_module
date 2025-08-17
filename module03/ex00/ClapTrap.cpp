/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:11:47 by msakata           #+#    #+#             */
/*   Updated: 2025/08/17 08:45:50 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap" << _name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hit_points(other._hit_points), 
	_energy_points(other._energy_points), _attack_damage(other._attack_damage)
{
	std::cout << "ClapTrap" << _name << " copied." << std::endl;
}

// なぜ*ではなく、&?
// 値返しだと「代入後にコピーコンストラクタ」が毎回呼ばれて非効率
// 言語仕様に沿った“設計上の慣習”
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	// この比較は何のためにある？
	// a._name = a._name; … 実害はないが無駄
	// 自己代入を防ぐため（特に動的メモリ管理があるクラスで重要）
	if (this != &other)
	{
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	std::cout << "ClapTrap " << _name << " assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hit_points <= 0)
	{
		//  動詞 leave（残す・置いていく） の過去分詞が left です。
		std::cout << "ClapTrap " << _name << " cannot attack, it has no hit points left." << std::endl;
		return;
	}
	if (_energy_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack, it has no energy points left." << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already destroyed." << std::endl;
		return;
	}
	_hit_points -= amount;
	// この処理好き↓
	if (_hit_points < 0)
		_hit_points = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage! (HP: " << _hit_points << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot be repaired, it's destroyed." << std::endl;
		return;
	}
	if (_energy_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair, it has no energy points left." << std::endl;
		return;
	}
	_hit_points += amount;
	_energy_points--;
	std::cout << "ClapTrap " << _name << " repairs itself, recovering "
		<< amount << " hit points! (HP: " << _hit_points << ")" << std::endl;
}