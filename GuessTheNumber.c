#include <stdio.h>
#include <stdlib.h>
int main() {
    int maxNumber=100, selectedNumber=10, triedNum, endlessLoop=0, endGame=0, timesLeft=10, alreadyTried[25]={}, j, i,index=0, flag=0;
    time_t seed=time(NULL);
    printf("This is a game, so i'll choose a number and you'll try to guess it.\n");
    printf("At this first time i will pick a number in betweeen 0 and %d\n", maxNumber );
    //printf("%d\n", seed);
    srand(seed);
    selectedNumber=rand()%maxNumber;
    printf("Selected is %d\t -- revealed number just for exploring game functionallity--\n", selectedNumber);


    do{
        printf("Try a number\n");
        scanf("%d", &triedNum);
    //    printf("indice %d\n", index);


        //alreadyTried[sizeof(alreadyTried)/sizeof(alreadyTried[0])]=triedNum;
        for (i=0; i<index; i++ ){
                if(*(alreadyTried+i)==triedNum){
                    printf("This number is already tried\nChoose another\n");
                    printf("Already tried numbers: ");
                    for (j=0; j<index; j++ ){
                            printf("%d, ", *(alreadyTried+j));
                    }
                    printf("\n");
                    flag=1;
                    break;
                }


        }
        printf("\n------------------------------------------------\n");
        if(flag==1){
            flag=0;
            continue;
        }
        *(alreadyTried+index)=triedNum;
        index++;

        if (triedNum==selectedNumber){
            printf("Amazing! This is the number\n");
            printf("Congratulations\n");
            break;
        }else if(triedNum>selectedNumber){
            printf("Too higer\n");
        }else if(triedNum<selectedNumber){
            printf("Too lower\n");
        }

        //triedNum!=selectedNumber


        timesLeft--;
        if (!timesLeft){
            printf  ("No tries left. \n");
            break;
        }else{
        printf("Tries left: %d\n", timesLeft);
        }




    }while(!endGame);

    printf("The Game is Over");



   return 0;
}
