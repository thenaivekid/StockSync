#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "OrderManagement.h"
#include "SupplyManagement.h"
#include "Supply.h"
#include "Order.h"
//TODO USER
class Payment{
public:
    static long int payment_count;
    long int payment_id;
    bool is_paid;
    float bill_amount;
    float discount_percentage;
    float total_amount;

public:
    Payment(float bill_amount_, float discount_percentage_ = 0.0)
    : bill_amount(bill_amount_), discount_percentage(discount_percentage_) {
        payment_id = payment_count++;
        is_paid = false;
        total_amount = bill_amount - (bill_amount * discount_percentage);
    }

    // TODO MAKE METHODS TO PAY AND PRINT BILL
    void pay();

    float get_bill_amount();

    float get_total_amount();

    float get_discount();

    void print_bill();
};
#endif