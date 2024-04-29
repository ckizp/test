#include <random>
#include "sequence_factory.h"

std::string InitialOrder::toString(InitialOrder::Type initial_order) {
    switch (initial_order) {
        case kRandom: return "Random";
        case kNearlySorted: return "Nearly sorted";
        case kReversed: return "Reversed";
        case kFewUnique: return "Few unique";
        default: return "Unknown";
    }
}

std::vector<int> SequenceFactory::makeSequence(ProblemSize::Type size, InitialOrder::Type type) {
    int s_size = static_cast<int>(size);
    std::vector<int> sequence(s_size);

    // On met en place notre générateur de nombres pseudo-aléatoires.
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> uni_dist;

    switch(type) {
        case InitialOrder::kRandom:
            // On initialise notre séquence en fonction de la taille entrée en paramètre.
            for (int i = 0; i < s_size; i++)
                sequence[i] = i;

            // On borne notre générateur.
            uni_dist = std::uniform_int_distribution<int> (0, s_size-1);

            // On randomise toute notre séquence.
            for (int i = 0; i < s_size; i++) {
                int new_index = uni_dist(mt);
                std::swap(sequence[i], sequence[new_index]);
            }
            break;
        case InitialOrder::kReversed:
            // On initialise dans l'ordre inverse notre séquence en fonction de la taille entrée en paramètre.
            for (int i = 0; i < s_size; i++)
                sequence[i] = s_size - i - 1;
            break;
        case InitialOrder::kFewUnique:
            // On initialise aléatoirement la séquence avec quatre valeurs possibles.
            uni_dist = std::uniform_int_distribution<int>(1,4);
            for (int i = 0; i < s_size; i++)
                sequence[i] = s_size / 4 * uni_dist(mt);
            break;
        case InitialOrder::kNearlySorted:
            // On initialise notre séquence en fonction de la taille entrée en paramètre.
            for (int i = 0; i < s_size; i++)
                sequence[i] = i;

            // On randomise notre séquence de bout en bout.
            int range = s_size / 100;
            for (int i = 0; i < s_size; i++) {
                uni_dist = std::uniform_int_distribution<int>(i / range * range, (i / range + 1) * range);
                int new_index = uni_dist(mt);
                int new_index_value = sequence[new_index];
                sequence[new_index] = sequence[i];
                sequence[i] = new_index_value;
            }
            break;
    }

    return sequence;
}