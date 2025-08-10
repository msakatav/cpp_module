/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 03:57:30 by msakata           #+#    #+#             */
/*   Updated: 2025/08/10 21:37:21 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
	: type(type)
{}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &new_type)
{
	type = new_type;
}