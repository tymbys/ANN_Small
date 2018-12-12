#include "NN.h"

double sigmoid(double x) {
	return 1.0/(1+exp(-x));
}
double sigmoid_d(double x) {
	double g = sigmoid(x);
	return g*(1-g);
}

void set_network_inputs(int test, double noise_prob) {
    int i;

    /* Fill the network inputs vector from the test */
    for (i = 0; i < INPUT_NEURONS; i++) {

        inputs[i] = tests[test].image[i];

        /* In the given noise probability, negate the cell */
        if (rand() < noise_prob * RAND_MAX) {
            inputs[i] = (inputs[i]) ? 0 : 1;
        }

    }

    return;
}

void feed_forward(void) {
    int i, j;

    /* Calculate outputs of the hidden layer */
    for (i = 0; i < HIDDEN_NEURONS; i++) {

        hidden[i] = 0.0;

        for (j = 0; j < INPUT_NEURONS + 1; j++) {
            hidden[i] += (w_h_i[i][j] * inputs[j]);
        }

        hidden[i] = sigmoid(hidden[i]);

    }

    /* Calculate outputs for the output layer */
    for (i = 0; i < OUTPUT_NEURONS; i++) {

        outputs[i] = 0.0;

        for (j = 0; j < HIDDEN_NEURONS + 1; j++) {
            outputs[i] += (w_o_h[i][j] * hidden[j]);
        }

        outputs[i] = sigmoid(outputs[i]);

    }

}

int classifier(void) {
    int i, best;
    double max;

    best = 0;
    max = outputs[0];


    for (i = 1; i < OUTPUT_NEURONS; i++) {

        if (outputs[i] > max) {
            max = outputs[i];
            best = i;
        }

    }

    return best;
}

int rand_test() {
    int r = rand();
    int RR = RAND_MAX / MAX_TESTS;
    int rr = r / (RR);
    return rr;
}

int find_ans(int index) {
    int i = 0;
    for (i = 0; i < MAX_TESTS; i++)
        if (tests[index].output[i] == 1) break;

    return i;
}
