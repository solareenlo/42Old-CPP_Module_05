/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:49:00 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/18 20:51:24 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : name_("Bureaucrat"), grade_(Bureaucrat::LOWEST_GRADE_) {
    this->checkGrade(this->grade_);
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : name_(name), grade_(grade) {
    this->checkGrade(this->grade_);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
    : name_(src.getName()), grade_(src.getGrade()) {
    this->checkGrade(this->grade_);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
    if (this != &rhs) {
        this->setGrade(rhs.getGrade());
    }
    this->checkGrade(this->grade_);
    return *this;
}

std::string const& Bureaucrat::getName() const { return this->name_; }
int Bureaucrat::getGrade() const { return this->grade_; }

void Bureaucrat::incrementGrade() {
    this->checkGrade(this->getGrade() - 1);
    this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade() {
    this->checkGrade(this->getGrade() + 1);
    this->setGrade(this->getGrade() + 1);
}

void Bureaucrat::signForm(Form* form) {
    if (form == NULL) {
        return;
    }
    try {
        form->beSigned(*this);
        std::cout << this->getName() << " signs " << form->getName()
                  << std::endl;
    } catch (std::exception& e) {
        std::cout << this->getName() << " cannot sign " << form->getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::setGrade(int grade) { this->grade_ = grade; }

void Bureaucrat::checkGrade(int grade) {
    if (grade > Bureaucrat::LOWEST_GRADE_) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (grade < Bureaucrat::HIGHEST_GRADE_) {
        throw Bureaucrat::GradeTooHighException();
    }
}

char const* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}

#include <iostream>

std::ostream& operator<<(std::ostream& ostream, Bureaucrat const& rhs) {
    ostream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    ostream << std::endl;
    return ostream;
}
