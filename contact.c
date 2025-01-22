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
    if(cn->data->phoneNumber[0] != '\0' && strcmp(p, cn->data->phoneNumber) == 0) {
        return true;
    }
    
    if (idx > 0) {
        return checkPhoneNumber(p, cn->nextContact, idx - 1);
    }

    return false;
}

// Add contact to last index of list
void addContact(struct contact contact){

    if(!checkPhoneNumber(contact.phoneNumber, headContact, length)){
        struct contactNode *newContactNode = (struct contactNode *)malloc(sizeof(struct contactNode));

        newContactNode->data = (struct contact *)malloc(sizeof(struct contact));
        *newContactNode->data = contact;

        if(contact.name[0] == '\0' || contact.phoneNumber[0] == '\0'){
            printf("Need name or phone number!\n");
            free(newContactNode->data);
            free(newContactNode);
            removeContactList();
            exit(1);
        }
        if(contact.streetName[0] == '\0')setStreetName(newContactNode->data, "empty");
        if(contact.city[0] == '\0')setCity(newContactNode->data, "empty");
        if(!contact.streetNumber)setStreetNumber(newContactNode->data, 0);
        if(!contact.postalCode)setPostalCode(newContactNode->data, 0);

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
        printf("Phone number allready exists or null...\n");
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

// Set or change name
void setName(struct contact* cn, char *newName){
    if(strlen(newName) > MAX_SIZE - 1){
        printf("Name too long: %s\n", newName);
    }
    else {
        strncpy(cn->name, newName, MAX_SIZE - 1);
    }
}

// Set or change street name
void setStreetName(struct contact* cn, char *newStreetName){
    if(strlen(newStreetName) > MAX_SIZE - 1){
        printf("StreetName too long: %s\n", newStreetName);
    }
    else {
        strncpy(cn->streetName, newStreetName, MAX_SIZE - 1);
    }
}

// Set or change street number
void setStreetNumber(struct contact* cn, int newStreetNumber){
    cn->streetNumber = newStreetNumber;
}

// Set or change postal code
void setPostalCode(struct contact* cn, int newPostalCode){
    cn->postalCode = newPostalCode;
}

// Set or change city
void setCity(struct contact* cn, char *newCity){
    if(strlen(newCity) > MAX_SIZE - 1){
        printf("CityName too long: %s\n", newCity);
    }
    else {
        strncpy(cn->city, newCity, MAX_SIZE - 1);
    }
}

// Set or change phone number
void setPhoneNumber(struct contact* cn, char *newPhoneNumber){
    if(strlen(newPhoneNumber) > MAX_PHONE_NUMBER_LENGTH - 1 || checkPhoneNumber(cn->phoneNumber, headContact, length)){
        printf("PhoneNumber too long or already exists: %s\n", newPhoneNumber);
    }
    else {
        strncpy(cn->phoneNumber, newPhoneNumber, MAX_PHONE_NUMBER_LENGTH - 1);
    }
}

void removeContactList(){
    while (headContact) {
        struct contactNode* temp = headContact;
        headContact = headContact->nextContact;
        free(temp->data);
        free(temp);
    }
}


void printContact(struct contact cn){
    printf("=================\n");
    printf("Name: %s\n", cn.name);
    printf("StreetName: %s\n", cn.streetName);
    printf("StreetNumber: %d\n", cn.streetNumber);
    printf("PostalCode: %d\n", cn.postalCode);
    printf("City: %s\n", cn.city);
    printf("PhoneNumber: %s\n", cn.phoneNumber);
    printf("=================\n");
}