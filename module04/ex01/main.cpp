/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:40:17 by msakata           #+#    #+#             */
/*   Updated: 2025/08/22 01:38:09 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void separator(const std::string &title)
{
	std::cout << "\n===== " << title << " =====\n";
}

int main()
{
	separator("basic new/delete via base pointer");
	const Animal* j = new Dog();
    const Animal* i = new Cat();
    j->makeSound();
    i->makeSound();
    delete j; // should not leak; must call Dog -> Brain destructors
    delete i; // same for Cat

    separator("array of Animal* (half dogs, half cats)");
    const int N = 6;
    Animal* zoo[N];
    for (int k = 0; k < N; ++k) {
        if (k < N / 2) zoo[k] = new Dog();
        else           zoo[k] = new Cat();
    }
    for (int k = 0; k < N; ++k) {
        zoo[k]->makeSound();
    }
    for (int k = 0; k < N; ++k) {
        delete zoo[k];
    }

    separator("deep copy test: Dog");
    Dog d1;
    d1.setIdea(0, "chase the cat");
    d1.setIdea(1, "bury the bone");

    Dog d2 = d1; // copy constructor (deep)
    std::cout << "d1[0]=" << d1.getIdea(0) << ", d2[0]=" << d2.getIdea(0) << std::endl;

    // mutate d1 after copy
    d1.setIdea(0, "sleep on the sofa");
    std::cout << "after change d1[0]=" << d1.getIdea(0) << ", d2[0]=" << d2.getIdea(0)
              << "  (should be unchanged if deep copy)\n";

    separator("deep copy test: Cat (assignment)");
    Cat c1;
    c1.setIdea(0, "knock the glass");
    Cat c2;
    c2 = c1; // copy assignment (deep)
    std::cout << "c1[0]=" << c1.getIdea(0) << ", c2[0]=" << c2.getIdea(0) << std::endl;

    c1.setIdea(0, "sit on keyboard");
    std::cout << "after change c1[0]=" << c1.getIdea(0) << ", c2[0]=" << c2.getIdea(0)
              << "  (should be unchanged if deep copy)\n";

    separator("polymorphic delete check (again)");
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    delete a1;
    delete a2;

    separator("done");
    return 0;
}

/*
Animal constructor called
Brain construcotr called
Dog constructor called
Brain destructor called
Dog destructor called
Animal destructor called
なぜこの順番になる？

違和感を感じるのは、
呼び出されたときに、最初にI/O出力せずに、
中身を処理しているから。
*/