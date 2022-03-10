#include <stdio.h>
#include <stdlib.h>

typedef struct Model{
    int id;
    double data[1024*1024];
} Model;

Model* init_models(int length){
    Model* model_arr = malloc(sizeof(Model) * length);
    for(int i = 0; i < length; i++){
        model_arr[i].id = i;
        for(int j = 0; j < 1024*1024; j++)
            model_arr[i].data[j] = 0.0;
    }
    return model_arr;
}

void use_rand_model(){
    Model* model = malloc(sizeof(Model));
    if(model != NULL){
        model->id = rand() % 64;
        //do something with this model...
    }else{
        printf("Something didn't work quite right!\n");
    }
    model = NULL;
    free(model);
}

int main() {
    printf("Starting to leak memory...\n\n");

    //Initializing 100 "models" and "doing something with them"
    int length = 100;
    Model* models = malloc(sizeof(Model) * length);
    models = init_models(length);
    //do something with your models...
    free(models);
    models = NULL;

    //"Doing something" with a random model
    for(int i = 0; i < 4096; i++)
        use_rand_model();

    printf("\nFinished leaking memory\n");
    printf("Now stuck in an infinite loop so that the leaked memory will not be freed until you manually quit the program.\n");
    for(;;);
}
