// Define a contact structure

#define MAX_SIZE 64
#define MAX_PHONE_NUMBER_LENGTH 16

struct contact{
    char name[MAX_SIZE];
    char streetName[MAX_SIZE];
    int streetNumber;
    int postalCode;
    char city[MAX_SIZE];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
};

struct contactNode{
    struct contactNode *nextContact;
    struct contactNode *previousContact;
    struct contact *data;
};

void addContact(struct contact contact);

void removeContact(int index);

void popContact();

struct contact getFirstContact();

struct contact getLastContact();

int listLenght();

void setName(struct contact* cn, char *newName);

void setStreetName(struct contact* cn, char *newStreetName);

void setStreetNumber(struct contact* cn, int newStreetNumber);

void setPostalCode(struct contact* cn, int newPostalCode);

void setCity(struct contact* cn, char *newCity);

void setPhoneNumber(struct contact* cn, char *newPhoneNumber);

void removeContactList();

void printContact(struct contact cn);