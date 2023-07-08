#include "Payment.h"

long int Payment::payment_count = 0;

void Payment::pay(){
    is_paid = true;
}

float Payment::get_bill_amount(){
    return bill_amount;
}

float Payment::get_total_amount(){
    return total_amount;
}

float Payment::get_discount(){
    return bill_amount * discount_percentage;
}

void Payment::print_bill(){
    std::cout << "Payment ID: " << payment_id << std::endl;
    std::cout << "Total Amount: " << total_amount << std::endl;
    std::cout << "Is Paid: " << is_paid << std::endl;
}