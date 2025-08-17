/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:11:53 by msakata           #+#    #+#             */
/*   Updated: 2025/08/17 09:24:08 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap test ===" << std::endl;
    ClapTrap clap("CLAPPY");
    clap.attack("enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== ScavTrap test ===" << std::endl;
    ScavTrap scav("SCAVVY");
    scav.attack("intruder");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n=== Destruction order ===" << std::endl;
    return 0;
}