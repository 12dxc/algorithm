#pragma once
#include <iostream>
using namespace std;

class WeightedEdge
{
private:
    int v_, w_, weight_;

public:
    WeightedEdge(int v, int w, int weight)
        : v_(v), w_(w), weight_(weight)
    {
    }

    int getV() { return v_; }

    int getW() { return w_; }

    int getWeight() { return weight_; }

    friend ostream &operator<<(ostream &os, WeightedEdge we)
    {
        os << "(" << we.v_ << "-" << we.w_ << ": " << we.weight_ << ")";
        return os;
    }

    bool operator<(const WeightedEdge &another) const
    {
        return this->weight_ < another.weight_;
    }
    bool operator>(const WeightedEdge &another) const
    {
        return this->weight_ > another.weight_;
    }
};
