#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int units;
    

    printf("Enter name of user: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character from name

    printf("Enter number of units consumed: ");
    scanf("%d", &units);



    printf("Name: %s\n", name);
    printf("Units consumed: %d\n", units);
    printf("Charges: %.2f\n", charges);

    return 0;
}
