#include<stdio.h>
#include<stdlib.h>

int solution(int *one, int *two);
int main(){
    FILE *f;
    char name[] = "1.txt"; 
    int buffer[2000];
    f = fopen(name, "r");
    if(f==NULL){
        printf("error open");
        return -1;
    }
    
    for (size_t i = 0; i < 2000; i++){
        if(fscanf(f, "%d", &buffer[i])!=1){
            printf("Error on position %zu\n", i);
            fclose(f);
            return -1;
        }
    }

    fclose(f);
    int first_column[1000]; 
    int second_column[1000];
    size_t i_1 = 0;
    size_t i_2 = 0;
    for (size_t i = 0; i < 2000; i++)
    {    
        if(i%2 == 0){
            first_column[i_1] = buffer[i];
            i_1++;
        }else{
            second_column[i_2] = buffer[i];
            i_2++;
        }
    }
    
    
 
    int result = solution(first_column, second_column);
    printf("%d", result);

    return 0;
}
int solution(int *one, int *two){
    int result = 0;
    for (size_t i = 0; i < 1000; i++)
    {   
        int x = 0;
        for (size_t j = 0; j < 1000; j++){
            int count = 0;
            if(one[i] == two[j]) count++;
            x = x + count * one[i];
        }
        result = result + x;
    }
    return result;
}
