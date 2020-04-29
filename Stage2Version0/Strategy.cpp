

#include "Strategy.h"
#include <vector>
using namespace std;
unsigned AddRemaind6::calculateCredits(const vector<int>& results)
{
    unsigned sum = 0;
    for (auto result: results) {
        sum += result;
    }
    return sum % 6;
}


unsigned MulRemaind6::calculateCredits(const vector<int>& results)
{
    unsigned res = 1;
    for(auto result: results) {
        res *= result;
    }
    return res % 6;
}
