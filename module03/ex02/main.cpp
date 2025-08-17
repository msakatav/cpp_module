/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:11:53 by msakata           #+#    #+#             */
/*   Updated: 2025/08/18 01:03:30 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "---- ClapTrap Test ----" << std::endl;
    ClapTrap c1("Clappy");
    c1.attack("enemy");
    c1.beRepaired(3);
    c1.takeDamage(5);

    std::cout << "\n---- ScavTrap Test ----" << std::endl;
    ScavTrap s1("Scavy");
    s1.attack("enemy");
    s1.guardGate();

    std::cout << "\n---- FragTrap Test ----" << std::endl;
    FragTrap f1("Fraggy");
    f1.attack("enemy");
    f1.highFivesGuys();

    std::cout << "\n---- Destructor chaining ----" << std::endl;
    return 0;
}