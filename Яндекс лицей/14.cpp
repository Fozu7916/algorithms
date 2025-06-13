#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>

class Product {
private:
    int productId_;
    std::string name_;
protected:
    double basePrice_;
public:
    Product(int id, const std::string& name, double basePrice)
        : productId_(id), name_(name), basePrice_(std::max(0.0, basePrice)) {}

    virtual ~Product() = default;

    int getProductId() const { return productId_; }
    std::string getName() const { return name_; }

    virtual double getFinalPrice(int quantity) const {
        return quantity >= 0 ? basePrice_ * quantity : 0.0;
    }
};

class DiscountedProduct : public Product {
private:
    double discountRate_;
public:
    DiscountedProduct(int id, const std::string& name, double basePrice, double discountRate)
        : Product(id, name, basePrice), discountRate_(std::min(1.0, std::max(0.0, discountRate))) {}

    double getDiscountRate() const { return discountRate_; }

    double getFinalPrice(int quantity) const override {
        return quantity >= 0 ? basePrice_ * quantity * (1.0 - discountRate_) : 0.0;
    }
};

class QuantityDiscountProduct : public Product {
private:
    int quantityThreshold_;
    double discountPrice_;
public:
    QuantityDiscountProduct(int id, const std::string& name, double basePrice, 
                          int threshold, double discountPrice)
        : Product(id, name, basePrice), 
          quantityThreshold_(std::max(1, threshold)),
          discountPrice_(std::max(0.0, discountPrice)) {}

    int getThreshold() const { return quantityThreshold_; }
    double getDiscountPrice() const { return discountPrice_; }

    double getFinalPrice(int quantity) const override {
        if (quantity < 0) return 0.0;
        return quantity >= quantityThreshold_ ? 
               discountPrice_ * quantity : 
               basePrice_ * quantity;
    }
};

class Order {
public:
    struct OrderItem {
        std::unique_ptr<Product> product;
        int quantity;

        OrderItem(std::unique_ptr<Product>&& p, int q)
            : product(std::move(p)), quantity(q) {}
    };

private:
    std::vector<OrderItem> items_;

public:
    void addItem(std::unique_ptr<Product> product, int quantity) {
        if (product && quantity > 0) {
            items_.emplace_back(std::move(product), quantity);
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items_) {
            total += item.product->getFinalPrice(item.quantity);
        }
        return total;
    }
};