#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "contact.h"

struct contactNode *headContact;
struct contactNode *tailContact;
int length = 0;

void removeContactRecursive(struct contactNode *cn, int index);

// Checks if phone number allready exists
bool checkPhoneNumber(char *p, struct contactNode *cn, int idx){
    if(!headContact){
        return false;
    }
    if(strcmp(p, cn->data->phoneNumber) == 0 && cn->data->phoneNumber != NULL) {
        return true;
    }
    
    if(idx == 0) {
        return false;
    }

    idx--;

    return checkPhoneNumber(p, cn->nextContact, idx);
}

// Add contact to last index of list
void addContact(struct contact contact){

    if(!checkPhoneNumber(contact.phoneNumber, headContact, length)){
        struct contactNode *newContactNode = (struct contactNode *)malloc(sizeof(struct contactNode));

        newContactNode->data = (struct contact *)malloc(sizeof(struct contact));
        newContactNode->data->name = strdup(contact.name);
        newContactNode->data->streetName = strdup(contact.streetName);
        newContactNode->data->city = strdup(contact.city);
        newContactNode->data->phoneNumber = strdup(contact.phoneNumber);
        newContactNode->data->streetNumber = contact.streetNumber;
        newContactNode->data->postalCode = contact.postalCode;
    
        // Set new contact as head if list is empty
        if(!headContact && !tailContact){
            headContact = newContactNode;
            tailContact = newContactNode;
        }

        newContactNode->nextContact = headContact;
        newContactNode->previousContact = tailContact;
        newContactNode->previousContact->nextContact = newContactNode;
        tailContact = newContactNode;

        length++;
    }
    else{
        printf("Phone number allready exists...\n");
    }
}

// Remove item based on index
void removeContact(int index){
    if(length != 0){
        if(length == 1){
            free(headContact->data);
            free(headContact);
            headContact = NULL;
            length--;
        }
        else if (index == 0 && length > 1){
            struct contactNode *newHead = headContact->nextContact;
            headContact->nextContact->previousContact = headContact->previousContact;
            headContact->previousContact->nextContact = headContact->nextContact;
            free(headContact->data);
            free(headContact);
            headContact = newHead;
            length--;
        }
        else if(index == length-1){
            popContact();
        }
        else {
            removeContactRecursive(headContact, index);
            length--;
        }

    }
    else {
        printf("The list is empty...\n");
    }
    
}

void removeContactRecursive(struct contactNode *cn, int index){
    if(index == 0){
        cn->nextContact->previousContact = cn->previousContact;
        cn->previousContact->nextContact = cn->nextContact;
        free(cn->data);
        free(cn);
        cn = NULL;
    }
    else{
        index--;
        removeContactRecursive(cn->nextContact, index);
    }
}

// Remove last item
void popContact(){
    if(length == 1){
        free(headContact->data);
        free(headContact);
        headContact = NULL;
        length--;
    }
    else if(length > 1){
        struct contactNode *newTail = tailContact->nextContact;
        tailContact->nextContact->previousContact = tailContact->previousContact;
        tailContact->previousContact->nextContact = tailContact->nextContact;
        free(tailContact->data);
        free(tailContact);
        tailContact = newTail;
        length--;
    }
    else {
        printf("The list is empty...\n");
    }
}

// Returns head
struct contact getFirstContact(){
    return *headContact->data;
}

// Returns tail
struct contact getLastContact(){
    return *tailContact->data;
}

// Returns length of list
int listLenght(){
    return length;
}

// Change name
void changeName(){

}

// Change street name
void changeStreetName(){
    
}

// Change street number
void changeStreetNumber(){
    
}

// Change postal code
void changePostalCode(){
    
}

// Change city
void changeCity(){
    
}

// Change phone number
void changePhoneNumber(){
    
}
