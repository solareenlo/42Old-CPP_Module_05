/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:12:18 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/18 21:56:03 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

void runTest(std::string const& name_bure, int grade,
             std::string const& name_form, int sign_grade, int exec_grade) {
    try {
        std::cout << "< " << name_bure << "'s test >" << std::endl;

        Bureaucrat bure(name_bure, grade);
        std::cout << bure;

        Form form(name_form, sign_grade, exec_grade);
        bure.signForm(form);
        std::cout << form << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    runTest("Akira", 10, "test1", 100, 100);
    runTest("Tetsuo", 100, "test1", 10, 10);
    runTest("Yamagata", 50, "test1", 10, 100);
    runTest("Kiyoko", 100, "test1", -10, 10);
    runTest("Takashi", 100, "test1", 10, -10);
    runTest("Masaru", 100, "test1", 10, 999);
    runTest("Taisa", 100, "test1", 999, 10);
    runTest("A", 999, "test1", 999, 999);
    runTest("B", -999, "test1", 999, 999);
    runTest("C", 100, "test1", -999, -999);
    return 0;
}
