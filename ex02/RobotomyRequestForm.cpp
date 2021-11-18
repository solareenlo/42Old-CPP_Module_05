/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:01:55 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 02:50:15 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

char const* RobotomyRequestForm::FORM_NAME_ = "Robotomy";

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(this->FORM_NAME_, this->SIGN_GRADE_, this->EXEC_GRADE_) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm(this->FORM_NAME_, this->SIGN_GRADE_, this->EXEC_GRADE_, target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
    : AForm(src) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

void RobotomyRequestForm::action() const {
    std::cout << "Dori dori dori dori ..." << std::endl;
    int random_number = std::rand();
    if (random_number % 2) {
        std::cout << "The robotization of " << this->getName()
                  << " has been successfully completed." << std::endl;
    } else {
        std::cout << "The robotization of " << this->getName()
                  << " has failed..." << std::endl;
    }
}
