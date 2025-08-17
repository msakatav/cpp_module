/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:24:51 by msakata           #+#    #+#             */
/*   Updated: 2025/08/18 05:07:36 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		// なぜ、こっちのattackは消した？
		// もし FragTrap にも attack を書いてしまうと？
		// 両方が候補に上がり、曖昧さ (ambiguity) が発生します。
		// C++ は「どの attack を使えばいいのか分からない」とコンパイルエラーになる
		void highFivesGuys(void);
};

#endif