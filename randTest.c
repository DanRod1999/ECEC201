#include <stdio.h>
int main(int argc, char ** argv){

//     if (3!=argc) {
// 	printf("USAGE : genRand <#ofRands> <randTest> \n");
// 	return -1;
// }


    // float array_sum = 0.0;
    // float mean;
    // float frandMin = .99;
    // float frandMax = .01;
    // float rand_val;

    // srand(time(0));
    // int array_len = rand() % 10 + 1; // random length of csv



    // printf("rand val = %d\n", array_len);

    // for(int i = 0; i< array_len; i++)
    // {
    //     rand_val = (rand() % 99) * .01;
    //     printf("rand num: %.2f\n", rand_val);
    //     // printf("min: %.2f\n", frandMin);

    //     if(rand_val <= frandMin){
    //         frandMin = rand_val;
    //     }
        
    //     if(rand_val >= frandMax){
    //         frandMax = rand_val;
    //     }

    //     // printf("max = %f, min = %f\n\n", frandMax, frandMin);
    //     array_sum += rand_val;
        
    // }
    
    // mean = array_sum/array_len;
 
    // printf("Max val = %.2f, Min val = %.2f, Mean val = %.2f\n\n", frandMax, frandMin ,mean);
    printf("Value of argv[1]: %s\n", argv[0]);
    printf("Value of argv[2]: %s\n", argv[1]);

}