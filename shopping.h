#ifndef SHOPPING_H
#define SHOPPING_H

// Class declaration for Shopping
class Shopping {
public:
    // Public member functions
    void menu(); // Function to display the main menu
    void administrator(); // Function to handle administrator actions
    void buyer(); // Function to handle buyer actions

private:
    // Private member functions
    void addProduct(); // Function to add a product
    void editProduct(); // Function to edit a product
    void removeProduct(); // Function to remove a product
    void listProducts(); // Function to list all products
    void generateReceipt(); // Function to generate a receipt
};

#endif // SHOPPING_H
