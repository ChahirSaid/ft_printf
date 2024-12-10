#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int x, y, p, ft_p, type, choice;
    char str[100];
    void *ptr;

    do {
        printf("\nSelect type:\n");
        printf("1: int\n2: char\n3: string\n4: hex\n5: HEX\n6: pointer\n -> ");
        scanf("%d", &type);

        if (type == 1) {
            printf("Enter an integer: ");
            scanf("%d", &x);
            ft_p = ft_printf("%d\n", x);
            p = printf("%d\n", x);
        } 
        else if (type == 2) {
            printf("Enter a character: ");
            scanf(" %c", (char *)&y);
            ft_p = ft_printf("%c\n", y);
            p = printf("%c\n", y);
        } 
        else if (type == 3) {
            printf("Enter a string: ");
            scanf("%99s", str);
            ft_p = ft_printf("%s\n", str);
            p = printf("%s\n", str);
        } 
        else if (type == 4) {
            printf("Enter a hexadecimal value: ");
            scanf("%x", &x);
            ft_p = ft_printf("%x\n", x);
            p = printf("%x\n", x);
        } 
        else if (type == 5) {
            printf("Enter a hexadecimal value (uppercase): ");
            scanf("%X", &x);
            ft_p = ft_printf("%X\n", x);
            p = printf("%X\n", x);
        } 
        else if (type == 6) {
            printf("Enter a memory address (pointer): ");
            scanf("%p", &ptr);
            ft_p = ft_printf("%p\n", ptr);
            p = printf("%p\n", ptr);
        } 
        else {
            printf("Invalid type selection.\n");
            continue;
        }
        printf("ft_printf: %d \t printf: %d \n", ft_p, p);
        printf("\nType 1 to enter new input or 2 to close: ");
        scanf("%d", &choice);
    } while (choice == 1);
    return 0;
}
