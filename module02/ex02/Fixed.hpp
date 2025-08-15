/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 03:32:37 by msakata           #+#    #+#             */
/*   Updated: 2025/08/15 23:30:10 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed は固定小数点（8ビットの fractional bits）
// 内部値 _fixed_point_value は int 型で保持
// 比較・算術演算子は内部値を利用して実装
// 加算/減算は _fixed_point_value 同士を直接足し引き
// 乗算/除算は一旦 float に変換して計算してから Fixed に戻す
// インクリメント/デクリメントは _fixed_point_value を ±1 する（1 が最小単位 ε）

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
		
		Fixed(const int value);
		Fixed(const float value);

		float toFloat() const;
		int toInt() const;

		int getRawBits() const;
		void setRawBits(int const raw);

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// なぜ、preはvoid でpostはint?
		// pre-increment と post-increment の違い
		// pre-increment（前置）
		// 値を先にインクリメントして、その 更新後の自分自身 を返す。
		// 戻り値は 参照（Fixed&）で、自分自身を直接返せる。
		// 無駄なコピーを避けられるので高速。
		Fixed &operator++();    // pre-increment
		// post-increment（後置）
		// 値をインクリメントする 前の状態 を返す。
		// int のダミー引数は ただの区別用（値は使わない）。
		// 更新前のオブジェクトを返すため、一時オブジェクトのコピーが必要なので 戻り値は値渡し（Fixed）。
		// ダミー引数とは？
		// 意味：「実際には使わないけど、関数のシグネチャを区別するためだけに存在する引数」。
		// 後置インクリメント（a++）と前置インクリメント（++a）を区別するために、
		// C++のルールで 後置にはint型のダミー引数 を付けることになっている。
		// 呼び出し側は何も渡さないし、関数内でも普通は使わない。
		Fixed operator++(int);  // post-increment
		Fixed &operator--();    // pre-decrement
		Fixed operator--(int);  // post-decrement

		// 二種類で何が違うのか？
		// min / max の二種類のオーバーロード
		// 引数が const の場合、非const参照にはバインドできないので、両方のバージョンを用意しておく必要がある。
		// なぜstatic?ー＞main.cpp側で解説
		// 課題にも「static member function」と書いてあるので static にします。
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

// なぜ、クラスに含めない？
// メンバ関数にしてしまうと 左辺がFixedのときしか使えなくなる。
// フリー関数（クラス外の関数）にすると、
// std::cout << myFixed;
// という形で 左辺がostream、右辺がFixed の場合にも動作する。
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif