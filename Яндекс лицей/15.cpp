#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct Point {
    int x;
    int y;
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class Shape {
private:
    Point position_;
    std::string color_;

public:
    Shape(Point position, const std::string& color) 
        : position_(position), color_(color) {}

    Point getPosition() const { return position_; }
    std::string getColor() const { return color_; }

    void setPosition(Point p) { position_ = p; }
    void setColor(const std::string& c) { color_ = c; }

    std::string getState() const {
        return "Position: " + std::to_string(position_.x) + "," + 
               std::to_string(position_.y) + ", Color: " + color_;
    }
};

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Shape& shape) = 0;
    virtual void undo(Shape& shape) = 0;
};

class MoveCommand : public Command {
private:
    Point targetPosition_;
    Point previousPosition_;

public:
    MoveCommand(Point targetPosition) : targetPosition_(targetPosition) {}

    void execute(Shape& shape) override {
        previousPosition_ = shape.getPosition();
        shape.setPosition(targetPosition_);
    }

    void undo(Shape& shape) override {
        shape.setPosition(previousPosition_);
    }
};

class ColorCommand : public Command {
private:
    std::string targetColor_;
    std::string previousColor_;

public:
    ColorCommand(const std::string& targetColor) : targetColor_(targetColor) {}

    void execute(Shape& shape) override {
        previousColor_ = shape.getColor();
        shape.setColor(targetColor_);
    }

    void undo(Shape& shape) override {
        shape.setColor(previousColor_);
    }
};