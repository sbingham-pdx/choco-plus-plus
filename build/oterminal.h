#include "structures.h"

//Defined macros
/*#define ERROR

//Function prototypes
void to_report(string &);    
void to_id(int &);          
void management_terminal(); */

//Defined macros
#define ERROR

//Function prototypes
void to_report(string &);    
void to_id(int &, int);          
void management_terminal(); 
int validateInputInteger();
void update_payment_status(management_report &);



int pterminal();
int pterminal_service();
int member_status();
void clearcin();

void scrBrk();
void clear(void);
void termHeader(const int);


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