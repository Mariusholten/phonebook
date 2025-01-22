#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

int main (){
    struct contact c1;
    setName(&c1, "Potet");
    setPhoneNumber(&c1, "123435");
    setPostalCode(&c1, 1234);

    struct contact c2;
    setName(&c2, "Snake");
    //setPhoneNumber(&c2, "11223435");
    setPostalCode(&c2, 142342344);
    
    addContact(c1);
    addContact(c2);

    printf("%d\n", listLenght());

    popContact();

    printf("%d\n", listLenght());

    return 0;
}