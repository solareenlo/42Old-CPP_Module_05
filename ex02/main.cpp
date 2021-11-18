/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:12:18 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 06:23:38 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void _test_shrubbery(std::string const& test_name, std::string const& name_bure,
                     int grade, std::string const& target) {
    try {
        std::cout << "< " << test_name << " >" << std::endl;

        Bureaucrat bure(name_bure, grade);
        std::cout << bure;

        ShrubberyCreationForm form(target);
        std::cout << form;

        form.beSigned(bure);
        std::cout << form;

        form.execute(bure);
        std::cout << name_bure << " executed " << form.getName() << std::endl;
        std::cout << std::endl;
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Bureaucrat Error: " << e.what() << std::endl;
        std::cout << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Bureaucrat Error: " << e.what() << std::endl;
        std::cout << std::endl;
    } catch (AForm::NotSignedException& e) {
        std::cout << "Form Error: " << e.what() << std::endl;
        std::cout << std::endl;
    } catch (AForm::GradeTooHighException& e) {
        std::cout << "Form Error: " << e.what() << std::endl;
        std::cout << std::endl;
    } catch (AForm::GradeTooLowException& e) {
        std::cout << "Form Error: " << e.what() << std::endl;
        std::cout << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

void _test_robotomy(std::string const& test_name, std::string const& name_bure,
                    int grade, std::string const& target) {
    try {
        std::cout << "< " << test_name << " >" << std::endl;

        Bureaucrat bure(name_bure, grade);
        std::cout << bure;

        RobotomyRequestForm form(target);
        std::cout << form;

        form.beSigned(bure);
        std::cout << form;

        form.execute(bure);
        std::cout << name_bure << " executed " << form.getName() << std::endl;
        std::cout << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

void _test_presidential(std::string const& test_name,
                        std::string const& name_bure, int grade,
                        std::string const& target) {
    try {
        std::cout << "< " << test_name << " >" << std::endl;

        Bureaucrat bure(name_bure, grade);
        std::cout << bure;

        PresidentialPardonForm form(target);
        std::cout << form;

        form.beSigned(bure);
        std::cout << form;

        form.execute(bure);
        std::cout << name_bure << " executed " << form.getName() << std::endl;
        std::cout << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

void _test_bure(std::string const& test_name, std::string const& name_bure,
                int grade, std::string const& target) {
    try {
        std::cout << "< " << test_name << " >" << std::endl;

        Bureaucrat bure(name_bure, grade);
        std::cout << bure;

        ShrubberyCreationForm shrubbery(target);
        std::cout << shrubbery;
        RobotomyRequestForm robotomy(target);
        std::cout << robotomy;
        PresidentialPardonForm presidential(target);
        std::cout << presidential;
        std::cout << std::endl;

        bure.executeForm(shrubbery);
        bure.signForm(shrubbery);
        bure.executeForm(shrubbery);

        bure.executeForm(robotomy);
        bure.signForm(robotomy);
        bure.executeForm(robotomy);

        bure.executeForm(presidential);
        bure.signForm(presidential);
        bure.executeForm(presidential);

        std::cout << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::srand(std::time(NULL));

    std::cout << "<< SHURUBBERY TESTS >>" << std::endl;
    _test_shrubbery("Bure: OK, Sign: OK, Exec: OK", "Akira", 10, "test1");
    _test_shrubbery("Bure: OK, Sign: OK, Exec: NG", "Tetsuo", 140, "test2");
    _test_shrubbery("Bure: OK, Sign: NG, Exec: NG", "Kiyoko", 150, "test3");
    _test_shrubbery("Bure: NG, Sign: NG, Exec: NG", "A", 999, "test4");
    _test_shrubbery("Bure: NG, Sign: NG, Exec: NG", "B", -999, "test5");
    std::cout << std::endl;

    std::cout << "<< ROBOTOMY TESTS >>" << std::endl;
    _test_robotomy("Bure: OK, Sign: OK, Exec: OK", "Akira", 10, "test11");
    _test_robotomy("Bure: OK, Sign: OK, Exec: OK", "Tetsuo", 45, "test22");
    _test_robotomy("Bure: OK, Sign: OK, Exec: NG", "Kiyoko", 60, "test33");
    _test_robotomy("Bure: OK, Sign: NG, Exec: NG", "Takashi", 80, "test44");
    _test_robotomy("Bure: NG, Sign: NG, Exec: NG", "A", 999, "test55");
    _test_robotomy("Bure: NG, Sign: NG, Exec: NG", "B", -999, "test66");
    std::cout << std::endl;

    std::cout << "<< PRESIDENTIAL TESTS >>" << std::endl;
    _test_presidential("Bure: OK, Sign: OK, Exec: OK", "Akira", 1, "test111");
    _test_presidential("Bure: OK, Sign: OK, Exec: NG", "Tetsuo", 10, "test222");
    _test_presidential("Bure: OK, Sign: NG, Exec: NG", "Kiyoko", 60, "test333");
    _test_presidential("Bure: NG, Sign: NG, Exec: NG", "A", 999, "test444");
    _test_presidential("Bure: NG, Sign: NG, Exec: NG", "B", -999, "test555");

    std::cout << "<< BUREAUCRAT TESTS >>" << std::endl;
    _test_bure("Shru: NG, Robo: NG, Pre: NG", "Tetsuo", 140, "target01");
    _test_bure("Shru: OK, Robo: NG, Pre: NG", "Kaneda", 60, "target02");
    _test_bure("Shru: OK, Robo: OK, Pre: NG", "Yamagata", 10, "target03");
    _test_bure("Shru: OK, Robo: OK, Pre: OK", "Akira", 1, "target04");
    return 0;
}
