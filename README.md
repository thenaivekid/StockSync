# StockSync

This is a inventory management system aimed for the company like amazon to take order and deliver the items.


## File storage

- stock items are stored in items/category_name/id.txt in stock_management_system
- orders are stored in orders/id.txt in order_management_system
- supplies are stored in supplies/id.txt in supply_management_system


## For implementation in UI

**Be careful with the directory.**

- Call this to create new item in the warehouse.` item_obj.set_item(args)`
   ``` void set_item(std::string name_, std::string description_, float weight_, int price_, int quantity_, std::string category_);```

- To read item file 

```
    Item item3 = Item::read_item_file(0);
```
- find the example usage of setting and getting order

```
test_SupplyManagement.cpp
```

- find the example usage of setting and getting supply

```
test_SupplyManagement.cpp
```

### Team members
- Ashok Neupane
- Ashok BK
- Anil Shrestha