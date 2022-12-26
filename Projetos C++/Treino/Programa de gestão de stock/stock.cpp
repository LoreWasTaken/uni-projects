// test
#include "iostream"
#include "vector"
#include "fstream"
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

// function to split a string into substrings using a delimiter character
vector<string> split(string str, char delimiter) {
    vector<string> substrings;
    string current;
    // loop through the string and split it by the delimiter
    for (char c : str) {
        if (c == delimiter) {
            substrings.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    // add the last substring (after the last delimiter)
    substrings.push_back(current);
    return substrings;
}

Product askProductData() {
    Product p;
    cout << "Enter the name of the product: ";
    cin >> p.name;
    cout << "Enter the price of the product: ";
    cin >> p.price;
    cout << "Enter the quantity in stock: ";
    cin >> p.quantity;
    return p;
}

void printProduct(Product p) {
    cout << "Product name: " << p.name << endl;
    cout << "Product price: " << p.price << endl;
    cout << "Product quantity: " << p.quantity << endl;
}

// function to insert a new product into the vector
void insertProduct(vector <Product> &products) {
    // ask the user for the data of a new product
    Product p = askProductData();
    // add the new product to the vector
    products.push_back(p);
}

// function to print the product list
void printProductList(vector <Product> products) {
    cout << "Product list:" << endl;
    // loop through the vector and print the data of each product
    for (Product p: products) {
        printProduct(p);
        cout << endl;
    }
}

// function to print the purchase list (products with quantity less than 5)
void printPurchaseList(vector <Product> products) {
    cout << "Purchase list:" << endl;
    // loop through the vector and print the data of products with quantity less than 5
    for (Product p: products) {
        if (p.quantity < 5) {
            printProduct(p);
            cout << endl;
        }
    }
}

// function to search for a product
void searchProduct(vector <Product> products) {
    cout << "Enter the name of the product to search for: ";
    string name;
    cin >> name;

    // loop through the vector and search for the product with the specified name
    bool found = false;
    for (Product p: products) {
        if (p.name == name) {
            found = true;
            printProduct(p);
            break;
        }
    }

    if (!found) {
        cout << "Product not found." << endl;
    }
}

// function to calculate the value in stock
void calculateValueInStock(vector <Product> products) {
    double total = 0;
    // loop through the vector and calculate the total value of the products in stock
    for (Product p: products) {
        total += p.price * p.quantity;
    }
    cout << "The total value in stock is: " << total << endl;
}

// function to apply inflation (10%) to the prices of the products
void applyInflation(vector <Product> &products) {
    // loop through the vector and increase the price of each product by 10%
    for (Product &p: products) {
        p.price *= 1.1;
    }
}

// function to export the product list to a file
void exportProductList(vector <Product> products) {
    cout << "Enter the name of the file: ";
    string filename;
    cin >> filename;

    ofstream file(filename);
    if (file.is_open()) {
        // loop through the vector and write the data of each product to the file
        for (Product p: products) {
            file << p.name << "," << p.price << "," << p.quantity << endl;
        }
        cout << "Product list successfully exported to file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// function to import a product list from a file
void importProductList(vector <Product> &products) {
    cout << "Enter the name of the file: ";
    string filename;
    cin >> filename;

    ifstream file(filename);
    if (file.is_open()) {
        string line;
        // loop through the file and read each line
        while (getline(file, line)) {
            // parse the line and create a new product
            vector <string> fields = split(line, ',');
            Product p;
            p.name = fields[0];
            p.price = stod(fields[1]);
            p.quantity = stoi(fields[2]);
            // add the new product to the vector
            products.push_back(p);
        }
        cout << "Product list successfully imported from file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    vector<Product> products; // create an empty vector of products

// ask the user for the data of a new product
    Product p = askProductData();
// add the new product to the vector
    products.push_back(p);

    while (true) {
        cout << "Enter your choice:" << endl;
        cout << "1. Insert a product" << endl;
        cout << "2. Print the product list" << endl;
        cout << "3. Print purchase list (products with quantity less than 5)" << endl;
        cout << "4. Search for a product" << endl;
        cout << "5. Calculate the value in Stock" << endl;
        cout << "6. Apply inflation 10%" << endl;
        cout << "7. Export the product list to a file" << endl;
        cout << "8. Import a product list from a file ()" << endl;
        cout << "9. Exit" << endl;

        int choice;
        cin >> choice;

        // use a switch statement to execute the corresponding operation
        switch (choice) {
            case 1:
                // insert a new product
                insertProduct(products);
                break;
            case 2:
                // print the product list
                printProductList(products);
                break;
            case 3:
                // print the purchase list
                printPurchaseList(products);
                break;
            case 4:
                // search for a product
                searchProduct(products);
                break;
            case 5:
                // calculate the value in stock
                calculateValueInStock(products);
                break;
            case 6:
                // apply inflation (10%) to the prices of the products
                applyInflation(products);
                break;
            case 7:
                // export the product list to a file
                exportProductList(products);
                break;
            case 8:
                // import a product list from a file
                importProductList(products);
                break;
            case 9:
                // exit the program
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}