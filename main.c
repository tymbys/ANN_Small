#include <stdio.h>
#include <string.h>
#include "NN.h"

#define COUNT 5
//double** ar_img;
//double** ar_label;

double ar_img[COUNT][INPUT_NEURONS];
double ar_label[COUNT][1];

int main(int argc, char** argv) {

    //ar_img = malloc(sizeof(double[count][INPUT_NEURONS]));
    ReadMNIST("./db/t10k-images.idx3-ubyte", COUNT, &ar_img[0][0], IS_IMG); //28x28

    //ar_label = malloc(sizeof(double[count][1]));
    ReadMNIST("./db/t10k-labels.idx1-ubyte", COUNT, &ar_label[0][0], IS_LABEL);

    int true_test = 0;
    int false_test = 0;


    for (int img = 0; img < COUNT; img++) {
        int label = ar_label[img][0];


        if (label >= 0 && label < 10) { //0..9

//            printf("\n\nloaded: %d",label);
//            for (int j = 0; j < INPUT_NEURONS; j++) {
//                if ((j % 28) == 0) printf("\n");
//                printf("%03d", (int) ar_img[img][j]);
//                //cout << setw(4) << (int) neural_net->inputs[j];
//            }



            //memcpy(&inputs[0], &ar_img[img][0], (INPUT_NEURONS) * sizeof (double));

            for (int i = 0; i < INPUT_NEURONS; i++) {
                inputs[i] = ar_img[img][i];
            }

            double noise_prob = 0;
            int guess;

            feed_forward();
            guess = classifier();

            if (guess == label) {
                true_test++;
                printf("\nTrue test! classifier: %d, label: %d", guess, label);
            } else {
                false_test++;
                printf("\nFalse test! classifier: %d, label: %d", guess, label);

                for (int j = 0; j < INPUT_NEURONS; j++) {
                    if ((j % 28) == 0) printf("\n");
                    printf("%03d", (int) inputs[j]);
                    //cout << setw(4) << (int) neural_net->inputs[j];
                }

            }


        }



    }
    printf("\nCount image: %d\n", COUNT);
    printf("True test:%d\n", true_test);
    printf("False test:%d\n", false_test);
    printf("Procent is true:%d\n", true_test * 100 / COUNT);
    
    printf("w_h_i[0][0]: %f\n",w_h_i[0][0]);
    return 0;
}


