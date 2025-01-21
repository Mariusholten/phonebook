#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

struct contactNode *headContact;
struct contactNode *tailContact;
int length = 0;

void removeContactRecursive(struct contactNode *cn, int index);


// Add contact to last index of list
void addContact(struct contact contact){
    struct contactNode *newContactNode = (struct contactNode *)malloc(sizeof(struct contactNode));
    
    // Set new contact as head if list is empty
    if(!headContact && !tailContact){
        headContact = newContactNode;
        tailContact = newContactNode;
    }

    newContactNode->nextContact = headContact;
    newContactNode->previousContact = tailContact;
    newContactNode->previousContact->nextContact = newContactNode;
    tailContact = newContactNode;

    newContactNode->data = (struct contact *)malloc(sizeof(struct contact));
    newContactNode->data = &contact;

    length++;
}

// Remove item based on index
void removeContact(int index){
    if(length != 0){
        if(index == 0 && length == 1){
            free(headContact->data);
            free(headContact);
            headContact = NULL;
        }
        else if (index == 0 && length > 1){
            struct contactNode *newHead = headContact->nextContact;
            headContact->nextContact->previousContact = headContact->previousContact;
            headContact->previousContact->nextContact = headContact->nextContact;
            free(headContact->data);
            free(headContact);
            headContact = newHead;
        }
        
        else if(index == length-1){
            popContact();
        }

        removeContactRecursive(headContact, index);


        length--;
    }
    else {
        perror("The list is empty...");
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
    if(tailContact){
        struct contactNode *newTail = tailContact->nextContact;
        tailContact->nextContact->previousContact = tailContact->previousContact;
        tailContact->previousContact->nextContact = tailContact->nextContact;
        free(tailContact->data);
        free(tailContact);
        headContact = newTail;
    }
    else {
        perror("The list is empty...");
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
