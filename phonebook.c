#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

int main (){
    struct contact c1;
    c1.name = "Marius";
    c1.phoneNumber = "12345678";
    c1.streetName = "New Street";
    c1.streetNumber = 2;
    c1.postalCode = 1234;
    c1.city = "Oslo";

    struct contact c2;
    c2.name = "Ina";
    c2.phoneNumber = "87654321";
    c2.streetName = "New Street";
    c2.streetNumber = 2;
    c2.postalCode = 1234;
    c2.city = "Oslo";

    struct contact c3;
    c3.name = "Løk";
    c3.phoneNumber = "99999999";
    c3.streetName = "New Street";
    c3.streetNumber = 2;
    c3.postalCode = 1234;
    c3.city = "Oslo";

    struct contact c4;
    c4.name = "Dasspapir";
    c4.phoneNumber = "11111111";
    c4.streetName = "Old Street";
    c4.streetNumber = 1;
    c4.postalCode = 4321;
    c4.city = "New York";

    addContact(c1);
    addContact(c2);
    addContact(c3);
    addContact(c4);

    printf("%d\n", listLenght());

    removeContact(2);

    printf("%d\n", listLenght());

    popContact();

    printf("%d\n", listLenght());

    return 0;
}