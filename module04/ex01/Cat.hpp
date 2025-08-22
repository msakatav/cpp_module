/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:03:17 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 01:19:23 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		/*
		派生クラス側で、virtualをつける人もいるがそれはどうして？
		可読性のため
		「この関数はオーバーライドされている」と読みやすくするために、派生クラス側でも virtual を書くことが多いです。
		古いC++の慣習
		C++98/03の時代は override キーワードがなかったので、「これ仮想だよ」と明示するために virtual を付けるのが一般的だった。
		C++11以降なら override を使うのがベスト
		*/
		void makeSound() const;

		void setIdea(int idx, const std::string &idea);
		std::string getIdea(int idx) const;
};

#endif
