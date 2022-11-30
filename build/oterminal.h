#include "structures.h"

//Defined macros
#define ERROR

//Function prototypes
void to_report(string &);    
void to_id(int &);          
void management_terminal(); 



int pterminal();
int pterminal_service();
void clearcin();

void scrBrk();


class oterminal {
    public:
        oterminal();
        ~oterminal();
        int useTerminal();
    private:
        void printMenu();

        int validateInputInteger();
        float validateInputFloat();
        string validateInputString();

        void interpretProviderStatus(const int status, const string providerToEdit);
        void interpretMemberStatus(const int status, const string memberToEdit);
        void interpretServiceStatus(const int status, const string serviceToEdit);

        provider inputProvider();
        member inputMember();
        service inputService();
};