/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:09:39 by msakata           #+#    #+#             */
/*   Updated: 2025/08/14 03:24:17 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
	: _fixed_point_value()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	// このコードは何をしている？
	// _fractional_bits は 小数部分のビット数（8ビット）。
	// value << _fractional_bits は、整数値を左に8ビットシフトします。
	// ８ビットぶんが、小数の情報になる。
	_fixed_point_value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	// roundfとは？
	// roundf は <cmath> の関数で、float 型の値を四捨五入して最も近い整数にします。
	_fixed_point_value = roundf(value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixed_point_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point_value = raw;
}

float Fixed::toFloat() const
{
	// << bit演算子
	// 具体例が欲しい
	return (float)_fixed_point_value / (1 << _fractional_bits);
}

int Fixed::toInt() const
{
	// 具体例が欲しい
	// これは戻してるだけ
	return _fixed_point_value >> _fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}