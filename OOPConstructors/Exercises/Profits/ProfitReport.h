#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"

std::string getProfitReport(Company *from, Company *to, std::map<int, ProfitCalculator> & calculate) {
    std::ostringstream ostr;

    for (;from != to+1; from++) {
        int profit = calculate[from->getId()].calculateProfit(*from);
        ostr << from->getName() << " = " << profit << std::endl;
    }
    return ostr.str();
}

#endif // !PROFIT_REPORT_H
