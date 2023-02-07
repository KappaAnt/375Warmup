#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
//intended arguments: ./run input.txt

    char *textFile = argv[1];
    FILE * fpointer = fopen(textFile, "r");
    if(fpointer == NULL){
        printf("Unable to open file\n");
        return 1;
    }
    char line[255];
    int size = 10;
    int counter = 0;
    int j = 0;
    int *arr = malloc(sizeof(int)*size);
    while(fgets(line, 255, fpointer) != NULL){
        counter++;
        if(counter > size){ //resize array
            size = size*2;
            int *temp = malloc(sizeof(int)*size);
            for(int i = 0; i< counter-1; i++){
                temp[i] = arr[i];
            }
            free(arr);
            arr = temp;
        }
        arr[j] = atoi(line);
        //printf("%d\n", arr[j]);
        j++;
    }
    fclose(fpointer);
    printf("Array Populated...\n");
    //Search the sums (including 0 cases)
    int sum = 0;
    fpointer = fopen("output.txt", "w");
    for(int i = 0; i < counter; i++){ //triple for loop
        
        for(int j = i+1; j < counter; j++){
            sum = arr[i] + arr[j]; //every possible combination of sums

            for(int k = 0; k < counter; k++){ // search through array to see if sum = an element
                if(arr[k] == sum){
                    //printf("%d %d=%d+%d Ping!\n", arr[k], sum, arr[i], arr[j]); 
                    fprintf(fpointer, "%d %d %d", arr[k], arr[i], arr[j]);
                    fprintf(fpointer, "\n");
                } 

            }

        }

    }
    printf("Output Populated...\n");
    fclose(fpointer);
    free(arr);
    return 0;
}