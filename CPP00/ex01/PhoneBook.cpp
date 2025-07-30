/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:04:41 by msakata           #+#    #+#             */
/*   Updated: 2025/07/30 07:24:28 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: current_contacts(), contacts_count()
{
	std::cout << " -Welcome to Awesome PhoneBook- " << std::endl;
}

void PhoneBook::run()
{
	std::string command;

	while (1)
	{
		std::cout << "Available commands: ADD | SEARCH | EXIT" << std::endl;
		std::cout << "Enter command: ";
		if (safe_getline(command))
		{
			if (command == "ADD")
				add_command();
			else if (command == "SEARCH")
				search_command();
			else if (command == "EXIT")
				break ;
		}
	}
}

bool PhoneBook::safe_getline(std::string &input) const
{
	if (!std::getline(std::cin, input))
	{
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting." << std::endl;
			std::exit(1);
		}
		std::cin.clear();
		std::cout << "Input error. Try again." << std::endl;
		return false;
	}
	else if (input.empty())
	{
		std::cout << "Input cannot be empty." << std::endl;
		return false;
	}
	else if (input.length() > 255)
	{
		std::cout << "Input too long!" << std::endl;
		return false;
	}
	for (size_t i = 0; i < input.size(); i++)
	{
		unsigned char c = static_cast<unsigned char>(input[i]);
		if (static_cast<unsigned char>(input[i]) > 127)
		{
			std::cout << "Only ASCII characters are allowed." << std::endl;
			return false;
		}
		if ((c < 32 && c != 32) || c == 127)
		{
			std::cout << "Control characters (like tab, newline) are not allowed." << std::endl;
			return false;
		}
	}
	return true;
}

void PhoneBook::add_command()
{
	std::string input;

	add_first_name(input);
	add_last_name(input);
	add_nickname(input);
	add_phone_number(input);
	add_darkest_secret(input);
	if (current_contacts == 7)
		current_contacts = 0;
	else
		current_contacts++;
	if (contacts_count < 8)
		contacts_count++;
}

bool PhoneBook::is_valid_name(const std::string &input) const
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isspace(static_cast<unsigned char>(input[i])))
		{
			std::cout << "Whitespace is not allowed in the name." << std::endl;
			return false;
		}
	}
	return true;
}

bool PhoneBook::is_valid_phone_number(const std::string &input) const
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
		{
			std::cout << "Phone number must contain only digits." << std::endl;	
			return false;
		}
	}
	return true;
}

void PhoneBook::add_first_name(std::string &input)
{
	while (1)
	{
		std::cout << "Enter first name: ";
		if (safe_getline(input))
		{
			if (is_valid_name(input))
				break ;
		}
	}
	contacts[current_contacts].set_first_name(input);
	
}

void PhoneBook::add_last_name(std::string &input)
{
	while (1)
	{
		std::cout << "Enter last name: ";
		if (safe_getline(input))
		{
			if (is_valid_name(input))
				break ;
		}
	}
	contacts[current_contacts].set_last_name(input);
}

void PhoneBook::add_nickname(std::string &input)
{
	while (1)
	{
		std::cout << "Enter nickname: ";
		if (safe_getline(input))
		{
			if (!is_only_spaces(input))
				break;
		}
	}
	contacts[current_contacts].set_nickname(input);
}

void PhoneBook::add_phone_number(std::string &input)
{
	while (1)
	{
		std::cout << "Enter phone number: ";
		if (safe_getline(input))
		{
			if (is_valid_phone_number(input))
				break ;
		}
	}
	contacts[current_contacts].set_phone_number(input);
}

void PhoneBook::add_darkest_secret(std::string &input)
{
	while (1)
	{
		std::cout << "Enter darkest secret: ";
		if (safe_getline(input))
		{
			if (!is_only_spaces(input))
				break;
		}
	}
	contacts[current_contacts].set_darkest_secret(input);
}

bool PhoneBook::is_only_spaces(const std::string &str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	std::cout << "Input cannot be empty or spaces only." << std::endl;
	return true;
}

void PhoneBook::search_command() const
{
	if (!contacts_count)
	{
		std::cout << "PhoneBook is empty. No contacts to display." << std::endl;
		return ;
	}
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < contacts_count; i++)
	{
		std::cout << std::right << std::setw(10) << i ;
		std::cout << "|";
		std::cout << std::right << std::setw(10) << print_contacts_string(contacts[i].get_first_name());
		std::cout << "|";
		std::cout << std::right << std::setw(10) << print_contacts_string(contacts[i].get_last_name());
		std::cout << "|";
		std::cout << std::right << std::setw(10) << print_contacts_string(contacts[i].get_nickname());
		std::cout << "|" << std::endl;
	}

	while (1)
	{
		std::string index;
		std::cout << "Enter the index of the contact to display: ";
		if (safe_getline(index))
		{
			if (is_valid_index(index))
			{
				int idx = index[0] - '0';
				contacts[idx].display_contact();
				return ;
			}
		}
	}
}

std::string PhoneBook::print_contacts_string(const std::string &str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

bool PhoneBook::is_valid_index(std::string &index) const
{
	if (index.length() == 1 && std::isdigit(index[0]))
	{
		int num = index[0] - '0';
		if (num >= 0 && num < contacts_count)
			return true;
	}
	if (contacts_count == 1)
		std::cout << "Invalid index. Please enter a number 0." << std::endl;
	else
	{
		std::cout << "Invalid index. Please enter a number between 0 and";
		std::cout << contacts_count - 1 << "." << std::endl;
	}
	return false;
}