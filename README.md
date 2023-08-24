# StockSync

This is a inventory management system aimed for the company like amazon to take order and deliver the items.

# Usage

Libraries required for the project
- wxWidget: (https://github.com/wxWidgets/wxWidgets)
- Becrypt: (https://github.com/pyca/bcrypt)

Compiling instructions
- We recommend compiling with c++ standard 17+
- Visual Studio is the recommended IDE
- Download the Libraries from given links
- Build the codes of libraries for the required OS environment
    - wxWidget
        - Go to directory in the wxWidget library: build > msw > wz_cv17.sln
        - debug and release according to the os platform
        - Go the project, in the view tab, go to other Windows, in property manager > add existing property, add .props file of this libray
    
    - Becrypt
        - Put the Downloaded codes in the project and include the classes just like our custom classes (as it is a small library)
- Put all the codes of our project directories in the root directory and build it in visual Studio

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