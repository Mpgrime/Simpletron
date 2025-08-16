#include <stdio.h>
  int accumulator;
  int memory [100];
  int counter;
  int isHalt;
int main(int argc, char** argv){
    counter=0;
    isHalt=0;
    int myWord=0000;
    int lastTwo=00;
    printf("*** Welcome to Simpletron! ***\n");
    printf("*** Please enter your program one instruction  ***\n");
    printf("*** (or data word) at a time. I will display  ***\n");
    printf("*** the location number and a question mark (?)  ***\n");
    printf("*** You then type the word for that location.  ***\n");
    printf("*** Type -99999 to stop entering your program  ***\n");
    while(isHalt==0){
         if(counter<10){
             printf("0");
         }
         printf("%d",counter);
         printf(" ?\n");
         scanf("%d",&myWord);
	 if(myWord==-99999){
            isHalt=1;
            printf("*** Program loading completed ***\n");
            printf("*** Program execution begins ***\n");
         }
	 else if(myWord>9999){
            printf("*** Invalid input: number out of bounds. ***\n");
	    printf("*** Please enter a valid number. ***\n");
	 }
	  else if(myWord<-9999){
      	    printf("*** Invalid input: number out of bounds. ***\n");
            printf("*** Please enter a valid number. ***\n");
         }
	 else{
	    memory[counter]=myWord;
            counter=counter+1;
	 }
    }
    isHalt=0;
    counter=0;
    while(isHalt==0){
         myWord=memory[counter];
	 lastTwo=myWord%100;
	 counter=counter+1;
	 if(counter>99){
	   printf("*** Memory capacity exceeded ***\n");
	   isHalt=1;
	 }
	 else if((myWord/100)==10){
	   myWord=0;
	   printf("What word do you want to store?\n");
	   scanf("%d",&myWord);
	   memory[lastTwo]=myWord;
	 }
	 else if((myWord/100)==11){
           myWord=memory[lastTwo];
           printf("%d\n",myWord); 
	 }
	 else if((myWord/100)==20){
	   accumulator=memory[lastTwo];
	 }
	 else if((myWord/100)==21){
	   memory[lastTwo]=accumulator;
	 }
	 else if((myWord/100)==30){
	   if((accumulator+memory[lastTwo])>9999){
	     isHalt=1;
             printf("*** Cannot add up to a number greater than 9999 ***\n");
             printf("*** Simpletron execution abnormally terminated ***\n");
	     dumpCode(myWord);
	   }
	   else if((accumulator+memory[lastTwo])<-9999){
             isHalt=1;
             printf("*** Cannot add up to a number less than -9999 ***\n");
             printf("*** Simpletron execution abnormally terminated ***\n");
	     dumpCode(myWord);
           }
	   else{
             accumulator=accumulator+memory[lastTwo];
	   }
         }
	 else if((myWord/100)==31){
	   if((accumulator-memory[lastTwo])>9999){
             isHalt=1;
             printf("*** Cannot subtract to a number greater than 9999 ***\n");
             printf("*** Simpletron execution abnormally terminated ***\n");
	     dumpCode(myWord);
           }
	   else if((accumulator-memory[lastTwo])<-9999){
             isHalt=1;
             printf("*** Cannot subtract to a number less than -9999 ***\n");
             printf("*** Simpletron execution abnormally terminated ***\n");
	     dumpCode(myWord);
	     isHalt=1;
           }
	   else{
           accumulator=accumulator-memory[lastTwo];
	   }
	 }
	 else if((myWord/100)==32){
	   if(memory[lastTwo]==0){
               printf("*** Attempt to divide by zero ***\n");
	       printf("*** Simpletron execution abnormally terminated ***\n");
	       dumpCode(myWord);
	       isHalt=1;
	   }
	   else{
      	       accumulator=accumulator/memory[lastTwo];
	   }
         }
	 else if((myWord/100)==33){
	   if((accumulator*memory[lastTwo])>9999){
             isHalt=1;
             printf("*** Cannot multiply to a number greater than 9999 ***\n");
             printf("*** Simpletron execution abnormally terminated ***\n");
	     dumpCode(myWord);
	     isHalt=1;
           }
           else if((accumulator-memory[lastTwo])<-9999){
             isHalt=1;
             printf("*** Cannot multiply to a number less than -9999 ***\n");
             printf("*** Simpletron execution abnormally terminated ***\n");
	     dumpCode(myWord);
	     isHalt=1;
           }
	   else{
       	   accumulator=accumulator*memory[lastTwo];
	   }
	 }
	 else if((myWord/100)==40){
      	   counter=lastTwo;
         }
	 else if((myWord/100)==41){
	   if(accumulator<0){
              counter=lastTwo;
	   }
         }
	  else if((myWord/100)==42){
           if(accumulator==0){
              counter=lastTwo;
           }
         }
	 else if((myWord/100)==43){
           isHalt=1;  
         }
	 else{
	   printf("*** Invalid instruction data ***\n");
	   printf("*** Simpletron execution abnormally terminated ***\n");
	   dumpCode(myWord);
	   isHalt=1;
	 }
    }
}
void dumpCode(int myWord){
   int flip=0;
   int operationCode=0;
   int operand=0;
   if (myWord<0){
     flip=myWord-(myWord*2);
     operationCode=flip/100;
     operand=myWord%100;
   }
   else{
     operationCode=myWord/100;
     operand=myWord%100;
   }
   printf("REGISTERS:\n");
   printf("Accumulator:          ");
   if(accumulator>=0){
     printf("+");
     if(accumulator<1000){
       printf("0");
       if(accumulator<100){
	 printf("0");
	 if(accumulator<10){
	   printf("0");
	 }
       }
     }
     printf("%d\n",accumulator);
   }
   if(accumulator<0){
     printf("-");
     flip=accumulator-(accumulator*2);
     if(flip<1000){
       printf("0");
       if(flip<100){
         printf("0");
         if(flip<10){
	   printf("0");
	 }
       }
     }
     printf("%d\n",flip);
   }
   printf("instructionCounter:   ");
   if(counter<10){
     printf("0");
   }
   printf("%d\n",counter);
   printf("instructionRegister:  ");
   if(myWord>=0){
     printf("+");
     if(myWord<1000){
       printf("0");
       if(myWord<100){
         printf("0");
         if(myWord<10){
	   printf("0");
         }
       }
     }
     printf("%d\n",myWord);
   }
   if(myWord<0){
     printf("-");
     flip=myWord-(myWord*2);
     if(flip<1000){
       printf("0");
       if(flip<100){
         printf("0");
         if(flip<10){
           printf("0");
         }
       }
     }
     printf("%d\n",flip);
   }
   printf("operationCode:        ");
   if(operationCode<10){
     printf("0");
   }
   printf("%d\n",operationCode);
   printf("operand:              ");
   if(operand<10){
     printf("0");
   }
   printf("%d\n",operand);
   printf("MEMORY:\n");
   int currWord=0;
   int row=0;
   printf("       0     1     2     3     4     5     6     7     8     9\n");
   for (int i = 0; i < 10; i++){
	row = i*10;
	printf("%d",row);
	if(row==0){
          printf(" ");
	}
	printf(" ");
	for (int j = 0; j < 10; j++){
	  currWord=memory[row+j];
	  if (currWord<0){
	    printf("-");
	    flip=currWord-(currWord*2);
	    if(flip<1000){
	      printf("0");
	      if(flip<100){
		printf("0");
		if(flip<10){
		  printf("0");
		}
	      }
	    }
	    if(j<9){
		printf("%d",flip);
		printf(" ");
	    }
	    else{
	      printf("%d\n",flip);
	    }
	  }
	  else{
	    printf("+");
            if(currWord<1000){
              printf("0");
              if(currWord<100){
                printf("0");
                if(currWord<10){
                  printf("0");
                }
              }
            }
            if(j<9){
                printf("%d",currWord);
                printf(" ");
            }
	    else{
	        printf("%d\n",currWord); 
	    }
	  }
        }
   }
}
