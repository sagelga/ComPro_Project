// Welcome to the program. The declaration of the functions and the library used is in .h file
#include "main.h"
void personnelSwitchHub (){
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Personnel Database");
    bannerBlankBorder ();
    bannerFullBorder ();

    for ( int i = 0; i < 10; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("What do you want to do ?");
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("1. Preview personnel database");
    bannerBlankBorderTextCen ("2. Create new personnel ID");
    bannerBlankBorderTextCen ("3. Delete personnel metadata from the database");
    bannerBlankBorderTextCen ("4. Update existed personnel");

    for (int i = 0;i<15;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("ALTERNATE RESPONSE  |  Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char flag;
    scanf (" %c", &flag);

    switch(toupper(flag)){

        case ('1'):
            personnelSelectInterface ();
            break;

        case ('2'):
            personnelInsertInterface ();
            break;

        case ('3'):
            personnelDeleteInterface ();
            break;

        case ('4'):
            personnelUpdateInterface ();
            break;

        case ('B'):
            switchHub ();

        default:
            personnelSwitchHub ();
            return;

    }
}

void personnelInsertInterface(){
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Personnel Database");
    bannerFullBorder ();

    bannerBlankBorderTextCen ("Create new Personnel ID");

    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Insert in form");
    bannerBlankBorderTextCen ("Form: ID");
    bannerBlankBorderTextCen ("Firstname");
    bannerBlankBorderTextCen ("Lastname");
    bannerBlankBorderTextCen ("Role");
    bannerBlankBorderTextCen ("Username");
    bannerBlankBorderTextCen ("Password");
    bannerBlankBorderTextCen ("Token_ID");
    bannerBlankBorderTextCen (" ");
    bannerBlankBorderTextCen ("Ex: 1234567891012");
    bannerBlankBorderTextCen ("Prayut");
    bannerBlankBorderTextCen ("Chun-O-Char");
    bannerBlankBorderTextCen ("0");
    bannerBlankBorderTextCen ("admin");
    bannerBlankBorderTextCen ("admin");
    bannerBlankBorderTextCen ("Token_0");
    bannerBlankBorder ();
    bannerBlankBorder ();
    bannerBlankBorderTextCen ("Insert PersonnelID Below");

    for ( int i = 0; i < 11; i++ )
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char id[MAX_LNG_ID], firstname[MAX_LNG_TEXT], lastname[MAX_LNG_TEXT], username[MAX_LNG_TEXT], password[MAX_LNG_TEXT], barcodeToken[MAX_LNG_TOKEN];
    char buffer[140], flag[MAX_LNG_TEXT], checker;
    int role;
    char bufferHead[140];
    sprintf(bufferHead, "%-20s|%-28s|%-28s|%-10s|%-20s|%-20s", "ID", "Firstname", "Lastname", "Role", "Username", "Password");
    while (1){
        scanf("%s", id);
        if (strcmp(id, "B") == 0 || strcmp(id, "b") == 0 ){
            personnelSwitchHub();
            break;
        } else if ( strcmp (id, "N") == 0 || strcmp (id, "n") == 0 ) {
            terminate ();
            break;
        } else {
            //------------------After Input--------------------
            //---------------------ID--------------------------
            screenClear ();
            sprintf(buffer, "%-20s->", id);
            bannerFullBorder();
            bannerBlankBorderTextCen ("Personnel Database");
            bannerFullBorder();
            bannerBlankBorder ();

            bannerBlankBorderTextLeft (bufferHead);
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextLeft (buffer);
    
            for (int i = 0;i<28;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please Type Personnel Firstname...");
            bannerFullBorder ();

            bannerUserInput ();

            //---------------------FirstName--------------------------
            scanf("%s", firstname);
            sprintf(buffer, "%-20s %-28s->", id, firstname);
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Personnel Database");
            bannerFullBorder();
            bannerBlankBorder ();

            bannerBlankBorderTextLeft (bufferHead);
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextLeft (buffer);
    
            for (int i = 0;i<28;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please Type Personnel Lastname...");
            bannerFullBorder ();

            bannerUserInput ();

            //---------------------LastName--------------------------
            scanf("%s", lastname);
            sprintf(buffer, "%-20s %-28s %-28s->", id, firstname, lastname);
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Personnel Database");
            bannerFullBorder();
            bannerBlankBorder ();

            bannerBlankBorderTextLeft (bufferHead);
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextLeft (buffer);
    
            for (int i = 0;i<28;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please Type Personnel Role (0/1/2)...");
            bannerFullBorder ();

            bannerUserInput ();

            //---------------------Role--------------------------
            scanf ("%d", &role);
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Personnel Database");
            bannerFullBorder();
            bannerBlankBorder ();

            bannerBlankBorderTextLeft (bufferHead);
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            if (role == 0){
                sprintf(buffer, "%-20s %-28s %-28s %-10s->", id, firstname, lastname, "Manager");
            }
            if (role == 1){
                sprintf(buffer, "%-20s %-28s %-28s %-10s->", id, firstname, lastname, "Marketing");
            }
            if (role == 2){
                sprintf(buffer, "%-20s %-28s %-28s %-10s->", id, firstname, lastname, "Sale");
            }
            bannerBlankBorderTextLeft (buffer);
            for (int i = 0;i<10;i++)
                bannerBlankBorder ();
            /*bannerBlankBorderTextCen ("Are you sure to Insert this personnel ?");
            bannerBlankBorderTextCen ("Type 'Y' to Yes || 'N' to No");*/
    
            for (int i = 0;i<18;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please Type Personnel Username...");
            bannerFullBorder ();

            bannerUserInput ();
            //-----Username-----
            scanf("%s", username);
            if (role == 0){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s->", id, firstname, lastname, "Manager", username);
            }
            if (role == 1){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s->", id, firstname, lastname, "Marketing", username);
            }
            if (role == 2){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s->", id, firstname, lastname, "Sale", username);
            }
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Personnel Database");
            bannerFullBorder();
            bannerBlankBorder ();

            bannerBlankBorderTextLeft (bufferHead);
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextLeft (buffer);
    
            for (int i = 0;i<28;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please Type Personnel Password...");
            bannerFullBorder ();

            bannerUserInput ();

            //-----Password-----
            scanf("%s", password);
            if (role == 0){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Manager", username, password);
            }
            if (role == 1){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Marketing", username, password);
            }
            if (role == 2){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Sale", username, password);
            }
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Personnel Database");
            bannerFullBorder();
            bannerBlankBorder ();

            bannerBlankBorderTextLeft (bufferHead);
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextLeft (buffer);
    
            for (int i = 0;i<28;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Please Type Personnel Token");
            bannerFullBorder ();

            bannerUserInput ();

            //-----Token-----
            scanf("%s", barcodeToken);
            if (role == 0){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Manager", username, password);
            }
            if (role == 1){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Marketing", username, password);
            }
            if (role == 2){
                sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Sale", username, password);
            }
            screenClear ();
            bannerFullBorder ();
            bannerBlankBorderTextCen ("Personnel Database");
            bannerFullBorder();
            bannerBlankBorder ();

            bannerBlankBorderTextLeft (bufferHead);
            bannerFullBorderSection ();
            bannerBlankBorder ();
            bannerBlankBorder ();
            bannerBlankBorderTextLeft (buffer);
    
            for (int i = 0;i<27;i++)
                bannerBlankBorder ();
            bannerBlankBorderTextCen ("Are you sure to Insert this Personnel ?");
            bannerBlankBorderTextCen ("Type 'Y' to Yes || 'N' to No");
            bannerFullBorder ();

            bannerUserInput ();
            scanf (" %c", &checker);

            if ( checker == 'y' || checker == 'Y' ) {
                if ( personnelInsert (id, firstname, lastname, role, username, password, barcodeToken)) {
                    screenClear ();
                    bannerFullBorder ();
                    bannerBlankBorderTextCen ("Personnel Database");
                    bannerFullBorder();
                    bannerBlankBorder ();

                    bannerBlankBorderTextLeft (bufferHead);
                    bannerFullBorderSection ();
                    bannerBlankBorder ();
                    bannerBlankBorder ();
                    if (role == 0){
                        sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Manager", username, password);
                    }
                    if (role == 1){
                        sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Marketing", username, password);
                    }
                    if (role == 2){
                        sprintf(buffer, "%-20s %-28s %-28s %-10s %-20s %-20s", id, firstname, lastname, "Sale", username, password);
                    }
                    bannerBlankBorderTextLeft (buffer);
                    bannerBlankBorder ();
                    bannerBlankBorder ();
                    for (int i = 0;i<8;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Insert Success");
                    bannerBlankBorderTextCen ("_____________________");
                    bannerBlankBorderTextCen ("Insert Next Personnel Or Type 'B' to Back");
        
                    for (int i = 0;i<15;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                    bannerFullBorder ();

                    bannerUserInput ();
                }
                else{
                    sprintf(buffer, "ID: %s", id);
                    screenClear ();
                    bannerFullBorder ();
                    bannerBlankBorderTextCen ("Personnel Database");
                    bannerFullBorder ();

                    bannerBlankBorderTextCen ("Insert Personnel");

                    bannerFullBorderSection ();
                    bannerBlankBorder ();
                    bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Insert not Successful !");
                    bannerBlankBorderTextCen ("Please check your Personnel ID");
                    bannerBlankBorder ();
                    bannerBlankBorderTextCen (buffer);
                    bannerBlankBorder ();
                    bannerBlankBorderTextCen ("was repeatedly");
                    bannerBlankBorderTextCen ("_____________________");
                    bannerBlankBorder ();
                    bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Insert Next Personnel Or Type 'B' to Back");
        
                    for (int i = 0;i<20;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                    bannerFullBorder ();

                    bannerUserInput ();

                }
            } else {
                personnelInsertInterface ();
            }
        }
    }
}

void displayPersonnel(int page) {
    screenClear ();
    int allPage = (int) ceil (RecordCount.personnel / 34) + 1;
    char NewRole[10];
    bannerFullBorder ();
    printf ("::     %-16s |           %-19s |           %-19s |    %-6s |     %-12s |     %-12s ::\n", "Personnel ID", "Firstname", "Lastname", "Role", "Username", "Password");
    bannerFullBorder ();

    if ( page == allPage ) {
        for ( int i = (page - 1) * 34; i < RecordCount.personnel; ++i ) {
            if (Personnel[i].role == 0)
            {
                strcpy(NewRole, "Manager");
            }
            else if (Personnel[i].role == 1)
            {
                strcpy(NewRole, "Marketing");
            }
            else
            {
                strcpy(NewRole, "Sale");
            }
            printf (":: %-20s | %-29s | %-29s | %-9s | %16s | %16s ::\n", Personnel[i].id, Personnel[i].firstname,
                    Personnel[i].lastname, NewRole, Personnel[i].username,
                    Personnel[i].password);
            //bannerBlankBorder();
        }
        //display remaining line as bannerBlankBorder()
        for ( int i = 0; i < 34 - (RecordCount.personnel % 34); ++i ) {
            printf (":: %-20s | %-29s | %-29s | %-9s | %16s | %16s ::\n", "", "", "", "", "", "");
        }
    } else {
        for ( int i = (page - 1) * 34; i < page * 34/*(34*page)*/; ++i ) {
            if (Personnel[i].role == 0)
            {
                strcpy(NewRole, "Manager");
            }
            else if (Personnel[i].role == 1)
            {
                strcpy(NewRole, "Marketing");
            }
            else
            {
                strcpy(NewRole, "Sale");
            }
            printf (":: %-20s | %-29s | %-29s | %-9s | %16s | %16s ::\n", Personnel[i].id, Personnel[i].firstname,
                    Personnel[i].lastname, NewRole, Personnel[i].username,
                    Personnel[i].password);
            //bannerBlankBorder();
        }
    }

    bannerBlankBorderTextCen ("Enter Page/Enter 'B' to back to Personnel Menu");
    printf ("::                                                       <<  <  ( Page %d of %d ) > >>                                                      ::\n",
            page, allPage);
    bannerFullBorder ();

}

void personnelSelectInterface(){
    char handling;
    int pageIn = 1, CheckPage;
    displayPersonnel(1);
    for ( int i = 0; i >= 0; ++i ) {
        printf(">>> ");
        scanf (" %c", &handling);
        if ((handling == 'B') || (handling == 'b')) {
            screenClear ();
            personnelSwitchHub ();
        } else if ( isdigit (handling)) {
            CheckPage = (int) handling - 48;
            if ((CheckPage <= ((int) ceil (RecordCount.personnel / 34) + 1)) && (CheckPage >= 1)) {
                pageIn = (int) handling - 48;
                displayPersonnel(pageIn);
            } else {
                displayPersonnel(pageIn);
                printf ("Oops! Page not found, Please enter correct page: ");
            }
        } else {
            displayPersonnel(pageIn);
            printf ("Oops! Input Error, Please enter correctly: ");
        }
    }
}

void personnelDeleteInterface(){
    char bufferHead[140];
    sprintf(bufferHead, "%-20s|%-50s|%-50s|%s", "ID", "Firstname", "Lastname", "Role");
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Personnel Database");
    bannerFullBorder();
    bannerBlankBorder ();

    bannerBlankBorderTextLeft (bufferHead);
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorderTextLeft ("->");
    bannerBlankBorder ();
    bannerBlankBorder ();

    for (int i = 0;i<27;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      Please Type PersonnelID...     |   Type 'B' to back");
    bannerFullBorder ();

    bannerUserInput ();
    char id[MAX_LNG_ID], firstname[MAX_LNG_TEXT], lastname[MAX_LNG_TEXT], username[MAX_LNG_TEXT], password[MAX_LNG_TEXT], barcodeToken[MAX_LNG_TOKEN];
    char buffer[140], flag;
    int role;
    while ( 1 ) {
        scanf ("%s", id);
        if ( strcmp (id, "B") == 0 || strcmp (id, "b") == 0 ) {
            personnelSwitchHub ();
        } else if ( strcmp (id, "N") == 0 || strcmp (id, "n") == 0 ) {
            terminate ();
        } else {
            if (personnelSelectById (id, firstname, lastname, &role, username, password, barcodeToken)) {
                screenClear ();
                if (role == 0){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Manager");
                }
                if (role == 1){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Marketing");
                }
                if (role == 2){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Sale");
                }
                bannerFullBorder();
                bannerBlankBorderTextCen ("Personnel Database");
                bannerFullBorder();
                bannerBlankBorder ();

                bannerBlankBorderTextLeft (bufferHead);
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorderTextLeft (buffer);
                for (int i = 0;i<10;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Are you sure to delete ?");
                bannerBlankBorderTextCen ("Type 'Y' to comfirm || Type 'N' to Discard");

                for (int i = 0;i<17;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
                scanf (" %c", &flag);
                if ( flag == 'Y' || flag == 'y' ) {
                    personnelDelete (id);
                    screenClear ();
                    bannerFullBorder ();
                    bannerBlankBorderTextCen ("Personnel Database");
                    bannerFullBorder();
                    bannerBlankBorder ();

                    bannerBlankBorderTextLeft (bufferHead);
                    bannerFullBorderSection ();
                    bannerBlankBorder ();
                    bannerBlankBorderTextLeft ("->");
                    for (int i = 0;i<10;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Delete Success");
                    bannerBlankBorderTextCen ("Type Next PersonnelID Or Type 'B' to Back");
            
                    for (int i = 0;i<17;i++)
                        bannerBlankBorder ();
                    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                    bannerFullBorder ();

                    bannerUserInput ();
                } else {
                    screenClear ();
                    personnelDeleteInterface ();
                }
            } else {
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Personnel Database");
                bannerFullBorder();
                bannerBlankBorder ();

                bannerBlankBorderTextLeft (bufferHead);
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorderTextLeft ("->");
                for (int i = 0;i<11;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("PersonnelID dosen't exist.");
                bannerBlankBorderTextCen ("Type Next PersonnelID Or Type 'B' to Back");
            
                for (int i = 0;i<16;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            }

        }
    }
}

void personnelUpdateInterface(){
    char bufferHead[140];
    sprintf(bufferHead, "%-20s|%-50s|%-50s|%s", "ID", "Firstname", "Lastname", "Role");
    screenClear ();
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Personnel Database");
    bannerFullBorder();
    bannerBlankBorder ();

    bannerBlankBorderTextLeft (bufferHead);
    bannerFullBorderSection ();
    bannerBlankBorder ();
    bannerBlankBorderTextLeft ("->");
    for (int i = 0;i<10;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type PersonnelID");

    for (int i = 0;i<18;i++)
        bannerBlankBorder ();
    bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
    bannerFullBorder ();
    bannerUserInput ();
    char id[MAX_LNG_ID], firstname[MAX_LNG_TEXT], lastname[MAX_LNG_TEXT], username[MAX_LNG_TEXT], password[MAX_LNG_TEXT], barcodeToken[MAX_LNG_TOKEN];
    char buffer[140], flag[MAX_LNG_TEXT];
    int role;
    while ( 1 ) {
        scanf ("%s", id);
        if ( strcmp (id, "B") == 0 || strcmp (id, "b") == 0 ) {
            personnelSwitchHub ();
        } else if ( strcmp (id, "N") == 0 || strcmp (id, "n") == 0 ) {
            terminate ();
        } else {
            if (personnelSelectById (id, firstname, lastname, &role, username, password, barcodeToken)) {
                screenClear ();
                if (role == 0){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Manager");
                }
                if (role == 1){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Marketing");
                }
                if (role == 2){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Sale");
                }
                bannerFullBorder();
                bannerBlankBorderTextCen ("Personnel Database");
                bannerFullBorder();
                bannerBlankBorder ();

                bannerBlankBorderTextLeft (bufferHead);
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorderTextLeft (buffer);
                bannerBlankBorderTextCen (" ");

                for (int i = 0;i<28;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type another name to change personnel name... | Press Enter to set by default");
                bannerFullBorder ();
                bannerUserInput ();

                printf("Default Firstname: (%s) >>> ", firstname);
                if (superscanf(flag) != 0)
                    personnelUpdateFirstname(id, flag);
                printf("Default Lastname: (%s) >>> ", lastname);
                if (superscanf(flag) != 0)
                    personnelUpdateLastname(id, flag);
                printf("Default Role: (%d) >>> ", role);
                if (superscanf(flag) != 0)
                    personnelUpdateRole(id, (flag[0] - '0'));
                
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Personnel Database");
                bannerFullBorder();
                bannerBlankBorder ();

                bannerBlankBorderTextLeft (bufferHead);
                bannerFullBorderSection ();
                bannerBlankBorder ();
                personnelSelectById (id, firstname, lastname, &role, username, password, barcodeToken);
                if (role == 0){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Manager");
                }
                if (role == 1){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Marketing");
                }
                if (role == 2){
                    sprintf(buffer, "%-20s %-50s %-50s %s", id, firstname, lastname, "Sale");
                }
                bannerBlankBorderTextLeft (buffer);
                bannerBlankBorder ();
                bannerBlankBorderTextLeft ("->");
                for (int i=0;i<10;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Personnel has been updated");
                bannerBlankBorderTextCen ("Type Next PersonnelID to Update Or Type 'B' to Back");
            
                for (int i = 0;i<15;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();

            } else {
                screenClear ();
                bannerFullBorder ();
                bannerBlankBorderTextCen ("Personnel Database");
                bannerFullBorder();
                bannerBlankBorder ();

                bannerBlankBorderTextLeft (bufferHead);
                bannerFullBorderSection ();
                bannerBlankBorder ();
                bannerBlankBorderTextLeft ("->");
                for (int i=0;i<10;i++)
                    bannerBlankBorder ();
                bannerBlankBorder ();
                bannerBlankBorderTextCen ("PersonnelID dosen't exist.");
                bannerBlankBorderTextCen ("Type Next PersonnelID Or Type 'B' to Back");
            
                for (int i = 0;i<16;i++)
                    bannerBlankBorder ();
                bannerBlankBorderTextCen ("Type 'N' to stop   |      ALTERNATE RESPONSE      |   Type 'B' to back");
                bannerFullBorder ();

                bannerUserInput ();
            }

        }
    }
}

int personnelSelectById (char *id, char *firstname, char *lastname, int *role, char *username, char *password,
                         char *barcodeToken) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            // Return all values back by reference
            strcpy (firstname, Personnel[i].firstname);
            strcpy (lastname, Personnel[i].lastname);
            *role = Personnel[i].role;
            strcpy (username, Personnel[i].username);
            strcpy (password, Personnel[i].password);
            strcpy (barcodeToken, Personnel[i].barcodeToken);
            return 1;   // Found a record
        }
    }
    return 0;           // Not found the given `id` in the records
}

int personnelInsert (char *id, char *firstname, char *lastname, int role, char *username, char *password,
                     char *barcodeToken) {
    int tailIndex = RecordCount.personnel;

    // To comfirm that `id`, `username` and `barcodeToken` is unique
    for ( int i = 0; i < tailIndex; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 || strcmp (Personnel[i].username, username) == 0 ||
             strcmp (Personnel[i].barcodeToken, barcodeToken) == 0 )
            return 0;   // Error: Some field already exists
    }

    strcpy (Personnel[tailIndex].id, id);
    strcpy (Personnel[tailIndex].firstname, firstname);
    strcpy (Personnel[tailIndex].lastname, lastname);
    Personnel[tailIndex].role = role;
    strcpy (Personnel[tailIndex].username, username);
    strcpy (Personnel[tailIndex].password, password);
    strcpy (Personnel[tailIndex].barcodeToken, barcodeToken);

    RecordCount.personnel++;    // Update the amount of records

    personnelFileWrite ();       // Save to a Database file
    return 1;   // Operation Success
}

int personnelUpdateFirstname (char *id, char *firstname) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            strcpy (Personnel[i].firstname, firstname);
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdateLastname (char *id, char *lastname) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            strcpy (Personnel[i].lastname, lastname);
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdateRole (char *id, int role) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            Personnel[i].role = role;
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelUpdatePassword (char *id, char *password) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            strcpy (Personnel[i].password, password);
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully updated
        }
    }
    return 0;   // Not found the given `id` in the records
}

int personnelDelete (char *id) {
    int numberOfRecords;    // Number of the records in a table
    numberOfRecords = RecordCount.personnel;
    for ( int i = 0; i < numberOfRecords; i++ ) {
        if ( strcmp (Personnel[i].id, id) == 0 ) {
            while ( i < numberOfRecords - 1 ) {
                Personnel[i] = Personnel[i + 1];
                i++;
            }
            RecordCount.personnel--;    // Update the amount of records
            personnelFileWrite ();   // Save to a Database file
            return 1;               // Record successfully deleted
        }
    }
    return 0;   // Not found the given `id` in the records
}

/*void personnelSwitchHub(){
    bannerFullBorder ();
    bannerBlankBorderTextCen ("Personnel Hub");
    bannerBlankBorderTextCen ("-----------------------");
    bannerBlankBorderTextCen ("What do you want to do?");
    bannerFullBorder ();

    bannerBlankBorder ();
    bannerBlankBorderTextCen ("1. Preview personnel database");
    bannerBlankBorderTextCen ("2. Add personnel to database");
    bannerBlankBorderTextCen ("3. Edit personnel in the database");
    bannerBlankBorderTextCen ("4. Remove personnel from the database");

    for ( int i = 0; i < 27; i++ ) {
        bannerBlankBorder ();
    }

    if (errorResponse == 1){
        bannerBlankBorderTextCen ("Invalid response. Please try again.");
    } else{
        bannerBlankBorder ();
    }

    bannerBlankBorderTextCen ("Type 'Q' to quit  |  Type in your response  |  Type 'B' to back");
    bannerFullBorder ();
    bannerUserInput ();

    char userInput;
    scanf (" %c", &userInput);
    errorResponse = 0;

    switch ( toupper (userInput)) {
        case ('1'):
            inventoryDatabaseInterface ();
            break;

        case ('2'):
            inventoryAdd ();
            break;

        case ('3'):
            //inventoryEdit();
            break;

        case ('4'):
            inventoryRemove ();
            break;

        case ('5'):
            categoryDatabaseInterface ();
            break;

        case ('6'):
            categoryAdd ();
            break;

        case ('7'):
            //categoryEdit();
            break;

        case ('B'):
            switchHub ();
            break;

        case ('Q'):
            terminate ();
            break;

        default:
            errorResponse = 1;
            inventorySwitchHub ();
    }
}

/*
 *                                             All hail the god..
 *  -----------------------------------------------------------------------------------------------------------------------
 *  |      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      ||      _=_      |
 *  |    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    ||    q(-_-)p    |
 *  |    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    ||    '_) (_`    |
 *  |    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    ||    /__/  \    |
 *  |  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  ||  _(<_   / )_  |
 *  | (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) || (__\_\_|_/__) |
 *  |---------------||---------------||---------------||---------------||---------------||---------------||---------------|
 *  |     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     ||     Hello     |
 *  |     Monday    ||    Tuesday    ||   Wednesday   ||    Thursday   ||     Friday    ||    Saturday   ||     Sunday    |
 *  -----------------------------------------------------------------------------------------------------------------------
 *                                         Program bug best enemy
 *                                 Please. No bug. No crash. No interrupt.
 *  -----------------------------------------------------------------------------------------------------------------------
 */