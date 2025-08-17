/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:11:53 by msakata           #+#    #+#             */
/*   Updated: 2025/08/17 08:44:22 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Red");
	ClapTrap b("Blue");

	a.attack("Blue");
	b.takeDamage(0);

	b.attack("Red");
	a.takeDamage(0);

	a.beRepaired(5);
	b.beRepaired(3);

	for (int i = 0; i < 12; i++)
		a.attack("Dummy");

	a.takeDamage(20);
	a.beRepaired(10);
}