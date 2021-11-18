/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 05:14:46 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 06:37:57 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(Intern const& src) { (void)src; }

Intern& Intern::operator=(Intern const& rhs) {
    (void)rhs;
    return *this;
}

Intern::makeFormType_ const Intern::makeFormTypeList_[] = {
    {"shrubbery creation", &Intern::makeShrubberyCreationForm},
    {"presidential pardon", &Intern::makePresidentialPardonForm},
    {"robotomy request", &Intern::makeRobotomyRequestForm},
    {"unknown form", NULL},
};

Form* Intern::makeShrubberyCreationForm(std::string const& target) {
    return (new ShrubberyCreationForm(target));
}

Form* Intern::makeRobotomyRequestForm(std::string const& target) {
    return (new RobotomyRequestForm(target));
}

Form* Intern::makePresidentialPardonForm(std::string const& target) {
    return (new PresidentialPardonForm(target));
}

Form* Intern::makeForm(std::string const& name, std::string const& target) {
    int const n =
        sizeof(Intern::makeFormTypeList_) / sizeof(Intern::makeFormType_);

    int i = 0;
    for (; i < n - 1 && Intern::makeFormTypeList_[i].name != name;) {
        i++;
    }

    if (Intern::makeFormTypeList_[i].func == NULL) {
        std::cout << "Intern cannot create " << name << std::endl;
        return NULL;
    }

    std::cout << "Intern create " << name << std::endl;
    return (this->*(makeFormTypeList_[i].func))(target);
}
