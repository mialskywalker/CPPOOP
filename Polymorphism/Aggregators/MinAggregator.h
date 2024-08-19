//
// Created by uchih on 19/08/2024.
//

#ifndef MINAGGREGATOR_H
#define MINAGGREGATOR_H

#include "Aggregator.h"
#include <climits>

class MinAggregator : public StreamAggregator {
public:
    MinAggregator(std::istream& istr) : StreamAggregator(istr) {
        aggregationResult = INT_MAX;
    }

    virtual void aggregate(int next) override {
        StreamAggregator::aggregate(next);
        if (next < aggregationResult)
            aggregationResult = next;
    }

};

#endif //MINAGGREGATOR_H
