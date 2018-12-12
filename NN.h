#ifndef NN_H
#define NN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MNIS.h"
//#include "NN_W.h"
#include "NN_W.h"


#define RHO (double)0.1
    
#define RAND_WEIGHT (((double)rand() / (double)RAND_MAX) - 0.5)
#define IMAGE_SIZE INPUT_NEURONS
#define MAX_TESTS 10
    
//#define INPUT_NEURONS IMAGE_SIZE
//#define HIDDEN_NEURONS 10
//#define OUTPUT_NEURONS 10


    typedef struct test_images_s {
        double image[IMAGE_SIZE];
        double output[OUTPUT_NEURONS];

    } test_images_t;
    
    test_images_t tests[MAX_TESTS];


    double inputs[INPUT_NEURONS + 1];
    double hidden[HIDDEN_NEURONS + 1];
    double outputs[OUTPUT_NEURONS];

    double sigmoid(double x);
    double sigmoid_d(double x);

    void set_network_inputs(int test, double noise_prob);
    void feed_forward(void);
    int classifier(void);
    int find_ans(int index);



#endif /* NN_H */

