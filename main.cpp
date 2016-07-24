#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>

    using namespace std;

/* COMMENTS & OTHERS

    ////// IMPORTANT /////////////////////////////////////////////////////////////////////////////////////
    //                                                                                                  //
    //  - zle ustawione seekg uszkadza plik, wychodzenie poza istniejącą liczbe znaków jest zabronione  //
    //                                                                                                  //
    //////////////////////////////////////////////////////////////////////////////////////////////////////
*/

void anyKey(){

    char anyKey;
    cout << "Press any key and enter to continue. \n";
    cin >> anyKey;
}

bool checkIsExist(string filePath){

    fstream checkFile(filePath.c_str());
    return checkFile.is_open();
}

bool configFileStatus(bool isShowInformation = false){

    bool status = checkIsExist("APPLICATION_CONFIG.txt");

    if(isShowInformation == true){

        cout << " __________________________________________________________ \n";
        cout << "|                                                          |\n";

        if(status == true){

        cout << "| - APPLICATION_CONFIG.txt     ||   STATUS: GOOD           |\n";
        }else
        cout << "| - APPLICATION_CONFIG.txt     ||   STATUS: BAD            |\n";

        cout << "|__________________________________________________________|\n";
    }

    return status;
}

bool fileStatus(bool isShowInformation = false){                                // DONE



        if(isShowInformation == true){

        configFileStatus(true);

        cout << " __________________________________________________________ \n";
        cout << "|                                                          |\n";

        if(checkIsExist("TEMPLATE.txt") == true){
        cout << "| - TEMPLATE.txt               ||   STATUS: GOOD           |\n";
        }else
        cout << "| - TEMPLATE.txt               ||   STATUS: BAD            |\n";

        if(checkIsExist("TEMPORARY.txt") == true){
        cout << "| - TEMPORARY.txt              ||   STATUS: GOOD           |\n";
        }else
        cout << "| - TEMPORARY.txt              ||   STATUS: BAD            |\n";

        if(checkIsExits("PARSER_CONFIG.txt") == true){
        cout << "| - PARSER_CONFIG.txt          ||   STATUS: GOOD           |\n";
        }else
        cout << "| - PARSER_CONFIG.txt          ||   STATUS: BAD    n";

        if( == true){
        cout << "|                                                          |\n";
        cout << "| * nothing has changed                                    |\n";
        }

        cout << "|__________________________________________________________|\n";
        }

    return (checkIsExist("TEMPLATE.txt") && checkIsExist("TEMPORARY.txt") && checkIsExits("PARSER_CONFIG.txt") && configFileStatus())

}

const char *parser(string filePath, string valueSymbol, bool isShow = false){   // DONE

    fstream textFile;
    textFile.open(filePath.c_str());

    bool showThis = false;
    bool endLoop  = false;
    bool isFound  = false;

    string value;
    string load;

    int fileLine = 0;

    do{

    fileLine++;

    getline(textFile, load);

    if(load == valueSymbol){

        endLoop = true;
        isFound = true;
        getline(textFile, value);

        if(isShow == true) cout << value << " (FOUND IN LINE: " << fileLine << ")" << endl;

    }else isFound = false;

    if(textFile.eof() == true){

        endLoop = true;
        cout << "End of file reached. \n";

        if(isFound == false) cout << "Value symbol hasn't found.";
    }

    }while(endLoop == false);

    textFile.close();

    return value.c_str();
}

void overwriteFiles(string systemCommand = "gedit"){                            // DONE

    fstream APPLICATION_CONFIG;
    fstream TEMPLATE;
    fstream TEMPORARY;
    fstream PARSER_CONFIG;

    APPLICATION_CONFIG.open ("APPLICATION_CONFIG.txt"   );
    TEMPLATE.open           ("TEMPLATE.txt"             );
    TEMPORARY.open          ("TEMPORARY.txt"            );
    PARSER_CONFIG.open      ("PARSER_CONFIG.txt"        );

        if(APPLICATION_CONFIG.is_open() == false ){

            systemCommand += " APPLICATION_CONFIG.txt";
            system( systemCommand.c_str() );
        }

        if(TEMPLATE.is_open() == false ){

            systemCommand += " TEMPLATE.txt";
            system( systemCommand.c_str() );
        }

        if(TEMPORARY.is_open() == false ){

            systemCommand += " TEMPORARY.txt";
            system( systemCommand.c_str() );
        }

        if(PARSER_CONFIG.is_open() == false ){

            systemCommand += " PARSER_CONFIG.txt";
            system( systemCommand.c_str() );
        }

    APPLICATION_CONFIG.close();
    TEMPLATE.close();
    TEMPORARY.close();
    PARSER_CONFIG.close();
}

void repairApplication(){                                                       // DONE

    bool endLoop = false;
    char pick;

    do{

        fileStatus(true);

        if(fileStatus() == false){

        cout << " __________________________________________________________ \n";
        cout << "|                                                          |\n";
        cout << "| Application can't open important files so, app will      |\n";
        cout << "| overwrite them. The app will use (for repair):           |\n";
        cout << "|__________________________________________________________|\n";
        cout << "                                                            \n";
        cout << " "<< parser("CONFIG.txt", "REPAIRING_APPLICATION", true) <<"\n";
        cout << " __________________________________________________________ \n";
        cout << "|                                                          |\n";
        cout << "| Are you want continue?    [y]/[n]                        |\n";
        cout << "|__________________________________________________________|\n";
        cout << "                                                            \n";

        cin >> pick;

            if(pick == 'y') {

                overwriteFiles( parser("CONFIG.txt", "REPAIRING_APPLICATION", false) );     // downloading name of application
                                                                                            // from config file
                cout << " __________________________________________________________ \n";
                cout << "|                                                          |\n";
                cout << "| Please, now exit and launch application again.           |\n";
                cout << "|__________________________________________________________|\n";
            }
        }

    endLoop = fileStatus();

    if(pick == 'n') endLoop = true;

    }while(endLoop == false);

    anyKey();
}

void textService(string filePath, string mode = "txt"){                         // DONE

    if(fileStatus() == true){

        fstream textFile;
        string textShow = "";

        textFile.open(filePath.c_str());

        if(mode == "txt"){

            do{

            getline(textFile, textShow);
            cout << textShow << endl;

            }while(textFile.eof() == false);
        }

        if(mode == "html"){

            do{

            getline(textFile, textShow);
            cout << textShow << endl;

            }while(textShow != "<-- EOF !-->");
        }

        textFile.close();

    }else repairApplication();
}

void theLatestPost(){                                                           // DONE

    // w getline, enter jest liczony jako jeden znak

    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| Your last generated HTML code will show in the bottom.   |\n";
    cout << "|__________________________________________________________|\n\n";
    cout << "============================================================\n";

    textService( parser("APPLICATION_CONFIG.txt", "TEMPORARY_HTML_FILE_PATH", false) );

    cout << "============================================================ \n";

    anyKey();
}

void editor(){                                                                  // TODO

    system("clear");
    cout << "Editor is running. ";

    anyKey();
}

void temporaryEditor(){                                                         // TODO

    if()





}

void runEditor(){                                                               // DONE


    if(fileStatus() == true){

    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| File Status: files has checked and ready to work.        |\n";
    cout << "|__________________________________________________________|\n\n";
    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "|  Do you want run Editor?   [y]/[n]                       |\n";
    cout << "|__________________________________________________________|\n";
    cout << "\n";

    char choose;

    cin >> choose;

    switch(choose){

    case 'y': editor();
    break;

    case 'n':
    break;

    default:
    break;

    }

    }else if(fileStatus() == false) repairApplication();

}

const char *dateAndTime(string mode = "all"){                                   // TODO

    string date;
    string time;

    cout << "\nTIME :";
    cin >> time;

    cout << "\nDATE: ";
    cin >> date;

    // VERY TO DO: POBIERANIE DATY Z SYSTEMU I ZWRACANIE JEJ Z FUNKCJI

    if(mode == "date") return date.c_str();
    if(mode == "time") return time.c_str();
}

void showConfig(){                                                              // TODO

    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| All settings has shown in the bottom.                    |\n";
    cout << "|__________________________________________________________|\n";
    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| APPLICATION SETTINGS:                                    |\n";
    cout << "|__________________________________________________________|\n";
    cout << "                                                            \n";

    textService("APPLICATION_CONFIG.txt");

    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| PARSER SETTINGS:                                         |\n";
    cout << "|__________________________________________________________|\n";
    cout << "                                                            \n";

    textService("PARSER_CONFIG.txt");

    anyKey();

}

void mainMenu(){                                                                // DONE

    char pick;
    bool endLoop = false;

    do{

    system("clear");

    textService("banner.txt");
    textService("updates.txt");
    textService("menu.txt");

        cin >> pick;

        switch(pick){

            case '0':
            system("clear");

                showConfig();
                break;

            case '1':
            system("clear");

                runEditor();

            break;

            case '2':
            system("clear");

                theLatestPost();
                break;

            case '3':
            system("clear");

                repairApplication();
                break;

            case '4':
            system("clear");

                textService("how_to.txt");
                anyKey();
                break;

            case '5':
            system("clear");

                endLoop = true;
                break;

            default:
            break;
        }

    }while(endLoop == false);
}

void runApplication(){

    if(fileStatus() == true){

    mainMenu();

    }else if(fileStatus() == false) repairApplication();
}

int main(){

    //runApplication();

    //dateAndTime();

    if(configFileStatus() == true) temporaryEditor();

    return 0;
}




















