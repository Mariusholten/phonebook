#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

int main (){
    struct contact c1;
    setName(&c1, "Potet");
    setStreetName(&c1, "Old Street");
    setStreetNumber(&c1, 2);
    setPostalCode(&c1, 1234);
    setCity(&c1, "Oslo");
    setPhoneNumber(&c1, "1231521");
    
    addContact(c1);

    printf("%d\n", listLenght());

    popContact();

    printf("%d\n", listLenght());

    printContact(c1);

    return 0;
}