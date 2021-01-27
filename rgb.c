#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    int red;
    int green;
    int blue;
} Rgb;

void print_color(double* arr[], int size);
void ptg_main_colors(double* arr[], int size);
void store_color(double* arr[], int size, Rgb* ptr);


int main(void) {
    int size;
    scanf("%d", &size);
    double* arr[size];

    Rgb rgb;
    Rgb* ptr = &rgb;;
    
    for(int i = 0; i < size; i++) {
        arr[i] = (double*)malloc(3 * sizeof(double));
    }

    
    store_color(arr, size, ptr);
    print_color(arr, size);
    ptg_main_colors(arr, size);

    for(int i = 0; i < size; i ++){
        free(arr[i]);
        arr[i] = NULL;
    }


    return 0;
}


void store_color(double* arr[], int size, Rgb* ptr){
    srand(time(NULL));

    for(int i = 0; i < size; i++){
        ptr->red = rand() % 256;
        ptr->green = rand() % 256;
        ptr->blue = rand() % 256;
        arr[i][0] = ptr->red;
        arr[i][1] = ptr->green;
        arr[i][2] = ptr->blue;
    }
}




void print_color(double *arr[], int size) {
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum = arr[i][0] + arr[i][1] + arr[i][2];
        printf("red: %.f green: %.f blue: %.f\nptg red: %.2lf\nptg green %.2lf\nptg blue %.2lf\n\n",arr[i][0], arr[i][1],arr[i][2],arr[i][0] / sum, arr[i][1] / sum, arr[i][2] / sum);
    }
    
}

void ptg_main_colors(double *arr[], int size){
    double sumRed = 0;
    double sumGreen = 0;
    double sumBlue = 0;
    for(int i = 0; i < size; i++){
        sumRed += arr[i][0];
        sumGreen += arr[i][1];
        sumBlue += arr[i][2];
    }
    
    printf("percentage of R,G,B to num_of_colors:\nptg red %.2lf\nptg green %.2lf\nptg blue %.2lf\n", sumRed/size, sumGreen/size, sumBlue/size);

}



