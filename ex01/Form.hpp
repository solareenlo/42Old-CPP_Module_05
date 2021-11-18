/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:54:08 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/18 21:14:03 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX01_FORM_HPP_
#define EX01_FORM_HPP_

#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
    Form();
    Form(std::string const& name, int grade_sign, int grade_exec);
    virtual ~Form();
    Form(Form const& src);

    Form& operator=(Form const& rhs);

    std::string const getName() const;
    bool getSigned() const;
    int getGradeRequiredToExecute() const;
    int getGradeRequiredToSign() const;

    void beSigned(Bureaucrat const& src);

 private:
    static const int HIGHEST_GRADE_ = 1;
    static const int LOWEST_GRADE_ = 150;

    std::string const name_;
    bool signed_;
    int const grade_required_to_execute_;
    int const grade_required_to_sign_;

    void setSigned(bool sign);

    void checkGrade(int grade) const;

    class GradeTooHighException : public std::exception {
     public:
        char const* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        char const* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& ostream, Form const& rhs);

#endif  // EX01_FORM_HPP_
