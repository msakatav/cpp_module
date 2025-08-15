/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 03:32:41 by msakata           #+#    #+#             */
/*   Updated: 2025/08/15 23:29:40 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: _fixed_point_value()
{}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_fixed_point_value = other._fixed_point_value;
	return *this;
}

Fixed::~Fixed()
{}

Fixed::Fixed(const int value)
{
	_fixed_point_value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
	_fixed_point_value = roundf(value * (1 << _fractional_bits));
}

float Fixed::toFloat() const
{
	return (float)_fixed_point_value / (1 << _fractional_bits);
}

int Fixed::toInt() const
{
	return _fixed_point_value >> _fractional_bits;
}

int Fixed::getRawBits() const
{
	return _fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	_fixed_point_value = raw;
}

bool Fixed::operator>(const Fixed &other) const
{
	return _fixed_point_value > other._fixed_point_value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _fixed_point_value < other._fixed_point_value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _fixed_point_value >= other._fixed_point_value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _fixed_point_value <= other._fixed_point_value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return _fixed_point_value == other._fixed_point_value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _fixed_point_value != other._fixed_point_value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result._fixed_point_value = _fixed_point_value + other._fixed_point_value;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result._fixed_point_value = _fixed_point_value - other._fixed_point_value;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	// そもそも　thisとは？なぜ必要？c言語にはないけど
	// ここで this->toFloat() は「今呼び出しているオブジェクトの toFloat()」を意味している。
	// toFloat() とだけ書いても動くけど、this を使うと「自分自身」を明示できる。
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	_fixed_point_value++;// 自分を直接インクリメント
	return *this;		 // 自分自身の参照を返す
}

Fixed Fixed::operator++(int)
{
	// 前の++関数と何が違う？またどうしてこのようなプログラムになる？
	Fixed tmp(*this);		// 更新前の自分をコピー
	_fixed_point_value++;	// 自分をインクリメント
	return tmp;				// 更新前のコピーを返す
}

Fixed &Fixed::operator--()
{
	_fixed_point_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_fixed_point_value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}