//
// Created by firas on 12/06/2026.
//

#ifndef T0466146_453_COURSEWORK_REAL_PAYMENT_DETAILS_H
#define T0466146_453_COURSEWORK_REAL_PAYMENT_DETAILS_H

using namespace std;

class PaymentDetails {
private:
    string payment_method_;
    string card_number_;
    string cvc_number_;
    string expiry_date_;
    double cash_paid_;

public:
    PaymentDetails();
    PaymentDetails(string payment_method, string card_number, string cvc_number, string expiry_date, double cash_paid);

    string GetPaymentMethod();
    string GetCardNumber();
    string GetCvcNumber();
    string GetExpiryDate();
    double GetCashPaid();

    void SetPaymentMethod(string payment_method);
    void SetCardNumber(string card_number);
    void SetCvcNumber(string cvc_number);
    void SetExpiryDate(string expiry_date);
    void SetCashPaid(double cash_paid);

    void DisplayPaymentDetails();
};

#endif //T0466146_453_COURSEWORK_REAL_PAYMENT_DETAILS_H
