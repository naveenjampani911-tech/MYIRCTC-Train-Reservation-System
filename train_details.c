#include <stdlib.h>
#include <stdio.h>
#include "train.h"

void print_train_info(void)
{
    FILE *fptr = fopen("all_train_details.txt", "r");

    if (fptr == NULL)
    {
        printf("Error: Unable to open train details file.\n");
        return;
    }

    printf("\n");
    printf("================================================================================================================\n");
    printf("                                      MYIRCTC - TRAIN INFORMATION\n");
    printf("================================================================================================================\n");

    printf("+------+------------------------+------------------+------------------+-------------+------------------+\n");
    printf("| ID   | Train Name             | From             | To               | Total Seats | Available Seats  |\n");
    printf("+------+------------------------+------------------+------------------+-------------+------------------+\n");

    while (fscanf(fptr, "%d %49s %49s %49s %d %d",
                  &TRAIN.train_no,
                  TRAIN.train_name,
                  TRAIN.source,
                  TRAIN.destination,
                  &TRAIN.no_of_seats,
                  &TRAIN.available_seats) == 6)
    {
        printf("| %-4d | %-22.22s | %-16.16s | %-16.16s | %-11d | %-16d |\n",
               TRAIN.train_no,
               TRAIN.train_name,
               TRAIN.source,
               TRAIN.destination,
               TRAIN.no_of_seats,
               TRAIN.available_seats);

        printf("+------+------------------------+------------------+------------------+-------------+------------------+\n");
    }

    printf("================================================================================================================\n");
    printf("                         Thank you for choosing MYIRCTC!\n");
    printf("================================================================================================================\n\n");

    fclose(fptr);
}
