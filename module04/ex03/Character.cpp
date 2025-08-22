/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 07:52:44 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 10:09:49 by msakata          ###   ########TOKYO.jp  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character(std::string const &name)
	: name(name)
{
	// なぜ、NULL?inventoryの中身はアドレス？
	// nullptr と NULLの違いは？
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(Character const &other)
	: name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			inventory[i] = NULL;
			if (other.inventory[i])
			{
				// ここの処理、= はアドレスだから、いいのか？ややこし... 
				// clone がどんな処理だっけ
				inventory[i] = other.inventory[i]->clone();
			}
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete inventory[i];
}

std::string const &Character::getName() const
{
	return name;
}

// このメソッドは何のためにある？
void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
		}
		return ;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
		return ;
	inventory[idx]->use(target);
}