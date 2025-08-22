/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:15:25 by msakata           #+#    #+#             */
/*   Updated: 2025/08/19 03:51:22 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal();

		// virtualにしていない。そもそもvirtualとは？
		/*「ポインタや参照で親クラスを指しているときでも、
		実際のオブジェクトの型に応じた関数が呼ばれるようにする」
		という仕組みを作るためのものです。
		これを 動的ポリモーフィズム (runtime polymorphism) と呼びます。
		*/
		void makeSound() const;
		std::string getType() const;
};

#endif