#include<stdio.h>
#include<stdbool.h>

int main()
{
    char a = 'a';
    float b = 5.0;
    const int c = 3;

    switch(a) {
        case 'a':
        // caso a == 'a'
         b = 20;
        break;
        case 'b':
        // caso a == 'b'
        break;
        default:
        // in tutti gli altri casi finisco qui
        break;
    }

    if (a == 1) {

    } else if (a == 2) {

    } else if (a == 4) {


    } else {
        // quando tutte le altre condizioni sono FALSE
    }
}