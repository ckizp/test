#ifndef VISUALSORT_SEQUENCE_FACTORY_H_
#define VISUALSORT_SEQUENCE_FACTORY_H_
#include <vector>

namespace InitialOrder {
    enum Type {
        kRandom,
        kNearlySorted,
        kReversed,
        kFewUnique,
    };

    static const Type All[] = { kRandom, kNearlySorted, kReversed, kFewUnique };

    std::string toString(Type);
}

namespace ProblemSize {
    enum Type {
        kSmall = 500,
        kMedium = 5000,
        kHigh = 50000,
    };

    static const Type All[] = { kSmall, kMedium, kHigh };
}

class SequenceFactory {
public:
    static std::vector<int> makeSequence(ProblemSize::Type size, InitialOrder::Type type);
};

#endif // VISUALSORT_SEQUENCE_FACTORY_H_