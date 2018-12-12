#include <stdlib.h>

#include "MNIS.h"

int ReverseInt(int i) {
    unsigned char ch1, ch2, ch3, ch4;
    ch1 = i & 255;
    ch2 = (i >> 8)&255;
    ch3 = (i >> 16)&255;
    ch4 = (i >> 24)&255;
    return ((int) ch1 << 24)+((int) ch2 << 16)+((int) ch3 << 8) + ch4;
}

void ReadMNIST(const char *db, int NumberOfImages, double *arr, int DATA_TYPE) {
    //"C:\\t10k-images.idx3-ubyte"
    //arr.resize(NumberOfImages, vector<double>(DataOfAnImage));
    //arr = (double **)malloc(DataOfAnImage*sizeof(double));
    
    //ifstream file(db, ios::binary);
    FILE *fp = fopen(db, "rb+");
    rewind (fp);
    
    if (fp != NULL) {
        int magic_number = 0;
        int number_of_images = 0;
        int n_rows = 0;
        int n_cols = 0;
        //file.read((char*) &magic_number, sizeof (magic_number));
        fread ((char*) &magic_number,1,sizeof (magic_number),fp);        
        magic_number = ReverseInt(magic_number);
        
        fread ((char*) &number_of_images,1,sizeof (number_of_images),fp);
        number_of_images = ReverseInt(number_of_images);

        if (DATA_TYPE == IS_IMG) {
            //file.read((char*) &n_rows, sizeof (n_rows));
            fread ((char*) &n_rows,1,sizeof (n_rows),fp);            
            n_rows = ReverseInt(n_rows);
            
            //file.read((char*) &n_cols, sizeof (n_cols));
            fread ((char*) &n_cols,1,sizeof (n_cols),fp); 
            n_cols = ReverseInt(n_cols);
            //for(int i=0;i<number_of_images;++i)
            
            //arr = (double **)malloc(NumberOfImages * n_cols * n_rows * sizeof(double));
            //arr = malloc(sizeof(double[NumberOfImages][n_cols * n_rows]));
            
            for (int i = 0; i < NumberOfImages; ++i) {
                for (int r = 0; r < n_rows; ++r) {
                    for (int c = 0; c < n_cols; ++c) {
                        unsigned char temp = 0;
                        //file.read((char*) &temp, sizeof (temp));
                        int size = fread ((char*) &temp,1,sizeof (temp),fp);  
                        
                        if (size !=1)
                            printf("size: %d\n", size);
                        //arr[i][(n_rows * r) + c] = (double) temp;
                        
                        int t = n_rows * n_cols;
                        arr[i*t + n_rows * r + c] = (double) temp;
                        //arr[0]=(double) temp;
                        
                    }
                }
            }
            


        } else if (DATA_TYPE == IS_LABEL) {
            //arr = (double **)malloc(NumberOfImages * sizeof(double));
            
            for (int i = 0; i < NumberOfImages; ++i) {
                unsigned char temp = 0;
                //file.read((char*) &temp, sizeof (temp));
                fread ((char*) &temp,1,sizeof (temp),fp);  
                //arr[i][0] = (double) temp;
                arr[i] = (double) temp;
            }
        }

    }
}