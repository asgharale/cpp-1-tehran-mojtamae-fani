#include <iostream>
#include <srting>

using namespace std;


enum Status
{
    NEW = 1,            // کالا های نو
    BROKEN = 2,         // کالاهای از کار افتاده
    OUTOFQUANTITY = 3   // پایان موجودی
};


class Store
{
    private:
        long id;
        string name;
        vector<string> discountCodes;

    public:
        Store(long id, stirng name)
        {
            this->id = id;
            this->name = name;
        }
        void addDiscountCode(string code)
        {
            discountCodes.push_back(code);
            cout << "added successfully" << endl;
        }
}


class Product
{
    private:
        long id;
        string name;
        string Description;
        double price;
        double quantity;
        Status status;
        vector<string> discountCodes;
        double lastDiscountPercent;
        long StoreId;

    public:
        Product(lond id, string name, string description, double price, doule quantity=1, Status status, long storeId)
        {
            this->id = id;
            this->name = name;
            this->Description = description;
            this->price = price;
            this->quantity = quantity;
            this->status = status;
            this->storeId = storeId;
        }
        void addDiscountCode(string code)
        {
            discountCodes.push_back(code);
            cout << "added successfully" << endl;
        }
        double totalValue()
        {
            return price * quantity;
        }
        void applyDiscount(doule percent)
        {
            price = price * percent / 100;
            lastDiscountPercent = percent;
        }
        
        void showDetailedData()
        {
            cout << "name: " << name << "\t"
                << "description: " << description << "\t"
                << "price: " << price << "\t"
                << "quantity: " << quantity << endl
        }
        void changeStatus(Status status)
        {
            this->status = status;
        }
};

void showMenu()
{
    
}

int main()
{
    vector<Store> stores;
    vector<Product> products;


}