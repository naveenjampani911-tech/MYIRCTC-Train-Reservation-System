#include "headerfile.h"
int lcnt = 0;
int sign_in(void)
{
    FILE *fptr = NULL;
    char usr[100];
    char pass[100];

    fptr = fopen("user_login_details.txt", "r");

    if (fptr == NULL)
    {
        printf("\n----------------------------------------\n");
        printf(" ERROR: Unable to open login details file\n");
        printf("----------------------------------------\n");
        return 0;
    }

    /* Allow a maximum of 3 login attempts */
    while (lcnt < 3)
    {
        /* Reset file position before checking credentials */
        rewind(fptr);

        printf("\n========================================\n");
        printf("             MYIRCTC SIGN IN\n");
        printf("========================================\n");

        printf("Enter username: ");
        if (scanf("%99s", usr) != 1)
        {
            fclose(fptr);
            return 0;
        }

        printf("Enter password: ");
        if (scanf("%99s", pass) != 1)
        {
            fclose(fptr);
            return 0;
        }

        lcnt++;

        if (check_usr_pass(usr, pass, fptr) == 1)
        {
            printf("\n========================================\n");
            printf("          LOGIN SUCCESSFUL!\n");
            printf("          Welcome, %s!\n", usr);
            printf("========================================\n\n");

            fclose(fptr);
            lcnt = 0;
            return 1;
        }

        printf("\nIncorrect username or password.\n");
        printf("Attempts remaining: %d\n", 3 - lcnt);
    }

    printf("\n========================================\n");
    printf("       MAXIMUM ATTEMPTS REACHED\n");
    printf("       Please try again later.\n");
    printf("========================================\n");

    fclose(fptr);
    lcnt = 0;
    return 0;
}

int check_usr_pass(char *user, char *paw, FILE *fptr)
{
    char usr[100];
    char pass[100];

    while (fscanf(fptr, "%99s %99s", usr, pass) == 2)
    {
        if (strcmp(usr, user) == 0 &&
            strcmp(pass, paw) == 0)
        {
            return 1;
        }
    }

    return 0;
}
