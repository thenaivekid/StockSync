#include "OrderManagement.h"

void OrderManagement::place_order() {
    Order order;
    order.set_order();
    orders.push_back(order);
    std::cout << "Order placed" << std::endl;
}

void OrderManagement::cancel_order(long int order_id) {
    Order order = get_order_by_id(order_id);
    order.set_is_cancelled(true);
    std::cout << "Order cancelled" << std::endl;
}

void OrderManagement::update_delivery_status(long int order_id) {
    Order order = get_order_by_id(order_id);
    order.set_is_delivered(true);
    std::cout << "Order status updated" << std::endl;
}

Order OrderManagement::get_order_by_id(long int order_id){
    for (int i = 0; i < orders.size(); i++){
        if (orders[i].get_order_id() == order_id){
            return orders[i];
        }
    }
}


std::ostream& operator<<(std::ostream& os, const OrderManagement& order_management) {
    for (auto order: order_management.orders) {
        os << order;
    }
    return os;
}