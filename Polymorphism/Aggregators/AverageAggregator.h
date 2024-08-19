//
// Created by uchih on 19/08/2024.
//

#ifndef AVERAGEAGGREGATOR_H
#define AVERAGEAGGREGATOR_H

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator {
    int sum;
public:
    AverageAggregator(std::istream& istr) : StreamAggregator(istr), sum(0) {
        aggregationResult = 0;
    }

    virtual void aggregate(int next) override {
        StreamAggregator::aggregate(next);
        sum += next;
        aggregationResult = sum / getNumAggregated();
    }

};

#endif //AVERAGEAGGREGATOR_H
