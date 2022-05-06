#ifndef PARAMS_H
#define PARAMS_H

#define MAX_GEN 100
#define POP_NUM 100
#define XOVER_CHANCE 0.5
#define MUTATION_CHANCE 0.02
#define W 0.3
#define RANDOM(from, to) (rand() % to + from)
#define REAL_RANDOM(from, to)  (from + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (to - from))))
#endif // PARAMS_H
