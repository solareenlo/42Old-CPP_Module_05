/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:08:59 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/19 01:50:07 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
    : name_("Form"),
      signed_(false),
      exec_grade_(AForm::LOWEST_GRADE_),
      sign_grade_(AForm::LOWEST_GRADE_),
      target_("") {
    this->checkGrade(sign_grade_);
    this->checkGrade(exec_grade_);
}

AForm::AForm(std::string const& name, int grade_sign, int grade_exec)
    : name_(name),
      signed_(false),
      exec_grade_(grade_exec),
      sign_grade_(grade_sign),
      target_("") {
    this->checkGrade(grade_sign);
    this->checkGrade(grade_exec);
}

AForm::AForm(std::string const& name, int grade_sign, int grade_exec,
             std::string const& target)
    : name_(name),
      signed_(false),
      exec_grade_(grade_exec),
      sign_grade_(grade_sign),
      target_(target) {
    this->checkGrade(grade_sign);
    this->checkGrade(grade_exec);
}

AForm::AForm(AForm const& src)
    : name_(src.getName()),
      signed_(src.getSigned()),
      exec_grade_(src.getExecGrade()),
      sign_grade_(src.getSignGrade()),
      target_(src.getTarget()) {}

AForm::~AForm() {}

AForm& AForm::operator=(AForm const& rhs) {
    if (this != &rhs) {
        this->signed_ = rhs.getSigned();
    }
    return *this;
}

std::string const AForm::getName() const { return this->name_; }
bool AForm::getSigned() const { return this->signed_; }
int AForm::getSignGrade() const { return this->sign_grade_; }
int AForm::getExecGrade() const { return this->exec_grade_; }
std::string const AForm::getTarget() const { return this->target_; }

void AForm::beSigned(Bureaucrat const& src) {
    if (src.getGrade() > this->sign_grade_) {
        throw AForm::GradeTooLowException();
    }
    this->setSigned(true);
}

void AForm::execute(Bureaucrat const& executer) const {
    if (this->getSigned() == false) {
        throw AForm::NotSignedException();
    }
    if (executer.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    this->action();
}

void AForm::setSigned(bool sign) { this->signed_ = sign; }

void AForm::checkGrade(int grade) const {
    if (grade > AForm::LOWEST_GRADE_) {
        throw AForm::GradeTooLowException();
    }
    if (grade < AForm::HIGHEST_GRADE_) {
        throw AForm::GradeTooHighException();
    }
}

char const* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high for form";
}

char const* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low for form";
}

char const* AForm::NotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& ostream, AForm const& rhs) {
    ostream << "Form " << rhs.getName() << " ";
    ostream << (rhs.getSigned() ? "" : "not ");
    ostream << "signed";
    ostream << " (Sign grade: " << rhs.getSignGrade();
    ostream << ", Execute grade: " << rhs.getExecGrade();
    ostream << ")" << std::endl;
    return ostream;
}
