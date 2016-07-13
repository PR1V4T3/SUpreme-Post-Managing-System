#include <iostream>
#include <stdlib.h>
#include <fstream>

    using namespace std;

/* COMMENTS & OTHERS

    ////// IMPORTANT /////////////////////////////////////////////////////////////////////////////////////
    //                                                                                                  //
    //  - zle ustawione seekg uszkadza plik, wychodzenie poza istniejącą liczbe znaków jest zabronione  //
    //                                                                                                  //
    //////////////////////////////////////////////////////////////////////////////////////////////////////
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void anyKey(){

    char anyKey;
    cout << "Press any key and enter to continue. \n";
    cin >> anyKey;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool fileStatus(bool isShowInformation = false){                            // DONE

    fstream APPLICATION_CONFIG;
    fstream TEMPLATE;
    fstream TEMPORARY;
    fstream PARSER_CONFIG;

    APPLICATION_CONFIG.open ("APPLICATION_CONFIG.txt"   );
    TEMPLATE.open           ("TEMPLATE.txt"             );
    TEMPORARY.open          ("TEMPORARY.txt"            );
    PARSER_CONFIG.open      ("PARSER_CONFIG.txt"        );

        if(isShowInformation == true){

        cout << " __________________________________________________________ \n";
        cout << "|                                                          |\n";

        if(APPLICATION_CONFIG.is_open() == true){
        cout << "| - APPLICATION_CONFIG.txt     ||   STATUS: GOOD           |\n";
        }else
        cout << "| - APPLICATION_CONFIG.txt     ||   STATUS: BAD            |\n";

        if(TEMPLATE.is_open() == true){
        cout << "| - TEMPLATE.txt               ||   STATUS: GOOD           |\n";
        }else
        cout << "| - TEMPLATE.txt               ||   STATUS: BAD            |\n";

        if(TEMPORARY.is_open() == true){
        cout << "| - TEMPORARY.txt              ||   STATUS: GOOD           |\n";
        }else
        cout << "| - TEMPORARY.txt              ||   STATUS: BAD            |\n";

        if(PARSER_CONFIG.is_open() == true){
        cout << "| - PARSER_CONFIG.txt          ||   STATUS: GOOD           |\n";
        }else
        cout << "| - PARSER_CONFIG.txt          ||   STATUS: BAD            |\n";

        if(APPLICATION_CONFIG.is_open() && TEMPLATE.is_open() && TEMPORARY.is_open() && PARSER_CONFIG.is_open() == true){

        cout << "|                                                          |\n";
        cout << "| * nothing has changed                                    |\n";
        }

        cout << "|__________________________________________________________|\n";
        }

    bool errorFlag = APPLICATION_CONFIG.is_open() && TEMPLATE.is_open() && TEMPORARY.is_open() && PARSER_CONFIG.is_open();

    APPLICATION_CONFIG.close();
    TEMPLATE.close();
    TEMPORARY.close();
    PARSER_CONFIG.close();

    return errorFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overwriteFiles(string systemCommand = "gedit"){                        // DONE

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void repairApplication(){                                                   // DONE

    bool endLoop = false;

    do{

        fileStatus(true);

        if(fileStatus() == false){

        cout << " __________________________________________________________ \n";
        cout << "|                                                          |\n";
        cout << "| Application can't open important files so, app will      |\n";
        cout << "| overwrite them. What applicaton want you use for repair? |\n";
        cout << "| The best are text editors like gEdit or Vi.              |\n";
        cout << "|__________________________________________________________|\n";
        cout << "\n";

        string systemCommand;
        cin >> systemCommand;

        overwriteFiles(systemCommand);

        }

    endLoop = fileStatus();

    }while(endLoop == false);

    anyKey();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void textService(string filePath, string mode = "txt"){                     // DONE

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void editor(){                                                              // TODO

    system("clear");
    cout << "Editor is running. ";

    anyKey();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void theLatestPost(){                                                       // DONE

    // w getline, enter jest liczony jako jeden znak

    string download;
    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| Your last generated HMTL code will show in the bottom.   |\n";
    cout << "|__________________________________________________________|\n\n";
    cout << "============================================================\n";

    textService("TEMPORARY.txt");

    cout << "============================================================ \n";

    anyKey();

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void runEditor(){                                                           // DONE


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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mainMenu(){                                                            // DONE

    char pick;
    bool endLoop = false;

    do{

    system("clear");

        textService("banner.txt");
        textService("updates.txt");
        textService("menu.txt");


        cin >> pick;

        switch(pick){

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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    mainMenu();

    return 0;
}
