/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:40:19 by msakata           #+#    #+#             */
/*   Updated: 2025/07/30 06:19:39 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: first_name(), last_name(), nickname(), phone_number(), darkest_secret()
{}

void Contact::set_first_name(const std::string &fn)
{
	first_name = fn;
}

void Contact::set_last_name(const std::string &ln)
{
	last_name = ln;
}

void Contact::set_nickname(const std::string &nn)
{
	nickname = nn;
}

void Contact::set_phone_number(const std::string &pn)
{
	phone_number = pn;
}

void Contact::set_darkest_secret(const std::string &ds)
{
	darkest_secret = ds;
}

std::string Contact::get_first_name() const
{
	return first_name;
}
std::string Contact::get_last_name() const
{
	return last_name;
}
std::string Contact::get_nickname() const
{
	return nickname;
}
std::string Contact::get_phone_number() const
{
	return phone_number;
}
std::string Contact::get_darkest_secret() const
{
	return darkest_secret;
}

void Contact::display_contact() const
{
	std::cout << "First Name:     " << first_name << std::endl;
	std::cout << "Last Name:      " << last_name << std::endl;
	std::cout << "Nickname:       " << nickname << std::endl;
	std::cout << "Phone Number:   " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
