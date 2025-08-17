/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:11:53 by msakata           #+#    #+#             */
/*   Updated: 2025/08/18 04:51:55 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d("Diamond");

	d.attack("enemy");
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();

	return 0;
}