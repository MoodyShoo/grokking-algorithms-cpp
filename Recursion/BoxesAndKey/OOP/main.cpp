#include <iostream>
#include <vector>

using namespace std;

class Item {
public:
    virtual bool IsKey() const = 0;
    virtual bool IsBox() const = 0;
};

class Key : public Item {
public:
    bool IsKey() const override {
        return true;
    }

    bool IsBox() const override {
        return false;
    }
};

class Box : public Item {
public:
    Box() = default;
    explicit Box(vector<Item*> items) 
        : items_(std::move(items)) {
    }

    bool IsKey() const override {
        return false;
    }

    bool IsBox() const override {
        return true;
    }

    const vector<Item*>& GetItems() const {
        return items_;
    }

private:
    vector<Item*> items_;
};

void LookForKey(const Box& box) {
    for (const auto& item : box.GetItems()) {
        if (item->IsBox()) {
            cout << "In box!" << endl;
            LookForKey(static_cast<const Box&>(*item));
        } else if (item->IsKey()){
            cout << "Found key!"sv << endl;
        }
    }
}

int main() {
    Key key;
    Box empty_box{};
    Box box_inner{vector<Item*>{&key}};
    Box box_outer{vector<Item*>{&empty_box, &box_inner}};
    LookForKey(box_outer);

    cout << "End" << endl;
}