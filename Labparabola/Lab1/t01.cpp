#include <stdio.h>

int main() {
    int x;
    printf("Enter a number: ");
    //scanf("%d",&x); //format %d for int variable
    scanf_s("%d",&x);
    printf("Hello World\n Hello, %d", x);
}