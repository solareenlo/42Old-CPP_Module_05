/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:12:18 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/18 15:38:42 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

void runTest(std::string const& name, int grade) {
    try {
        std::cout << "< " << name << "'s test >" << std::endl;

        Bureaucrat bure(name, grade);
        std::cout << bure;

        bure.incrementGrade();
        std::cout << bure;
        bure.incrementGrade();
        std::cout << bure;

        bure.decrementGrade();
        std::cout << bure;
        bure.decrementGrade();
        std::cout << bure;
        bure.decrementGrade();
        std::cout << bure;

        std::cout << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    runTest("Kaneda", 1);
    runTest("Tetsuo", 150);
    runTest("Akira", 100);
    runTest("Kiyoko", 150);
    runTest("Takashi", -999);
    runTest("Masaru", 999);
    return 0;
}
