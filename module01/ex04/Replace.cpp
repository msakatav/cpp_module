/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 03:50:29 by msakata           #+#    #+#             */
/*   Updated: 2025/08/11 06:03:37 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Replace.hpp"

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2)
	: filename(filename), s1(s1), s2(s2)
{}

bool Replace::process()
{
	std::string content = readFile();
	if (content.empty() && s1.empty())
		return false;
	std::string replaced = replacAll(content);
	return writeFile(replaced);
}

std::string Replace::readFile()
{
	// c++98
	std::ifstream in_file(filename.c_str());
	if (!in_file)
		return "";
	char ch;
	while (in_file.get(ch))
		content += ch;
	return content;
}

std::string Replace::replacAll(const std::string &content)
{
	if (s1.empty())
		return content;

	std::string result;
	size_t pos = 0;
	size_t found;
	// content.find(s1, pos) で、pos 以降に s1 が出てくる位置を探す
	// npos は「不正な位置」を表すため、find が npos を返す＝「見つからなかった」と判断できます。
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content.substr(pos, found - pos));
		result.append(s2);
		pos = found + s1.size();
	}
	result.append(content.substr(pos));
	return result;
}

bool Replace::writeFile(const std::string &content)
{
	std::ofstream out_file((filename + ".replace").c_str());
	if (!out_file)
		return false;
	out_file << content;
	return true;
}