// Define a contact structure
struct contact{
    char *name;
    char *streetName;
    int streetNumber;
    int postalCode;
    char *city;
    char *phoneNumber;
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

void changeName();

void changeStreetName();

void changeStreetNumber();

void changePostalCode();

void changeCity();

void changePhoneNumber();