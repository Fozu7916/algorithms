#include <iostream>
#include <string>
#include <vector>
#include <memory>

class FileSystemNode {
protected:
    std::string name_;

public:
    FileSystemNode(const std::string& name) : name_(name) {}
    virtual ~FileSystemNode() = default;

    std::string getName() const { return name_; }
    virtual size_t getSize() const = 0;
    virtual void display(int depth = 0) const = 0;
    virtual bool isDirectory() const { return false; }
};

class File : public FileSystemNode {
private:
    size_t size_;

public:
    File(const std::string& name, size_t size) 
        : FileSystemNode(name), size_(size >= 0 ? size : 0) {}

    size_t getSize() const override { return size_; }

    void display(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "[F] " << name_ << " (" << size_ << " bytes)\n";
    }
};

class Directory : public FileSystemNode {
private:
    std::vector<std::unique_ptr<FileSystemNode>> contents_;

public:
    Directory(const std::string& name) : FileSystemNode(name) {}

    bool isDirectory() const override { return true; }

    FileSystemNode* find(const std::string& name) const {
        for (const auto& node : contents_) {
            if (node->getName() == name) {
                return node.get();
            }
        }
        return nullptr;
    }

    void add(std::unique_ptr<FileSystemNode> node) {
        contents_.push_back(std::move(node));
    }

    size_t getSize() const override {
        size_t total = 0;
        for (const auto& node : contents_) {
            total += node->getSize();
        }
        return total;
    }

    void display(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "[D] " << name_ << "\n";
        for (const auto& node : contents_) {
            node->display(depth + 1);
        }
    }
};