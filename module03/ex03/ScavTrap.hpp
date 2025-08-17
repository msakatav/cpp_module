/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 08:46:42 by msakata           #+#    #+#             */
/*   Updated: 2025/08/18 05:14:51 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// virtual publicとは？
// 仮想継承 (virtual inheritance) を意味します。
// 仮想継承された基底クラス（ClapTrap）の コンストラクタ呼び出しは一番下の派生クラス（DiamondTrap）が責任を持つ
class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		// DiamondTrapクラスで、attackをオーバーロードしているのに、virtualにしない理由は？
		// 今回の課題では 直接オブジェクトを使う想定 なので、動的バインディングは不要です
		// virtual にすると何が変わる？
		void attack(const std::string &target);
		void guardGate();
};

#endif