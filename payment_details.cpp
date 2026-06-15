//
// Created by firas on 12/06/2026.
//

#include <iostream>
#include "payment_details.h"

using namespace std;

PaymentDetails::PaymentDetails() {
    payment_method_ = "";
    card_number_ = "";
    cvc_number_ = "";
    expiry_date_ = "";
    cash_paid_ = 0.0;
}

PaymentDetails::PaymentDetails(string payment_method, string card_number, string cvc_number,
                               string expiry_date, double cash_paid) {
    payment_method_ = payment_method;
    card_number_ = card_number;
    cvc_number_ = cvc_number;
    expiry_date_ = expiry_date;
    cash_paid_ = cash_paid;
}

string PaymentDetails::GetPaymentMethod() const  {
    return payment_method_;
}

string PaymentDetails::GetCardNumber() const {
    return card_number_;
}

string PaymentDetails::GetCvcNumber() const {
    return cvc_number_;
}

string PaymentDetails::GetExpiryDate() const {
    return expiry_date_;
}

double PaymentDetails::GetCashPaid() const {
    return cash_paid_;
}

void PaymentDetails::SetPaymentMethod(string payment_method) {
    payment_method_ = payment_method;
}

void PaymentDetails::SetCardNumber(string card_number) {
    card_number_ = card_number;
}

void PaymentDetails::SetCvcNumber(string cvc_number) {
    cvc_number_ = cvc_number;
}

void PaymentDetails::SetExpiryDate(string expiry_date) {
    expiry_date_ = expiry_date;
}

void PaymentDetails::SetCashPaid(double cash_paid) {
    cash_paid_ = cash_paid;
}

void PaymentDetails::DisplayPaymentDetails() const {
    cout << "Payment method: " << payment_method_ << endl;

    if (payment_method_ == "card" || payment_method_ == "Card") {
        cout << "Card number: " << card_number_ << endl;
        cout << "CVC number: " << cvc_number_ << endl;
        cout << "Expiry date: " << expiry_date_ << endl;
    } else if (payment_method_ == "cash" || payment_method_ == "Cash") {
        cout << "Cash paid: " << cash_paid_ << endl;
    }
}