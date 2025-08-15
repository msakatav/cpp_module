/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:09:36 by msakata           #+#    #+#             */
/*   Updated: 2025/08/15 22:02:26 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _fixed_point_value;
		static const int _fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		
		// 新しいコンストラクタ
		Fixed(const int value);
		Fixed(const float value);
		
		float toFloat() const;
		int toInt() const;

		int getRawBits() const;
		void setRawBits(int const raw);
};

// 出力演算子オーバーロード?
// ostream とは？
// std::ostream は 出力ストリーム（Output Stream） のクラスです。
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif