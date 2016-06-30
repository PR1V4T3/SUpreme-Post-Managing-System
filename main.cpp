#include <iostream>
#include <stdlib.h>
#include <fstream>

    using namespace std;

/* COMMENTS & OTHERS

    /////// TO DO //////////////////////////////////////////////////////////////////////////////
    //                                                                                        //
    //  - kopiowanie z templatki do pliku generated.txt                                       //
    //  - wprowadzanie danych do pliku [SKOŃCZONE] -> fillFile()                              //
    //  - dodac plik PREVIOUS_POST.txt do przechowywania ostatniego artykuły na wszelki wypadek [  //
    //  - parser do automatycznego odczytywania miejsca gdzie ma być wklejony dany tekst bez  //
    //    używania seekg; odnajdywane w miejscu komentarza HTML                               //
    //                                                                                        //
    ////////////////////////////////////////////////////////////////////////////////////////////

    ////// IMPORTANT /////////////////////////////////////////////////////////////////////////////////////
    //                                                                                                  //
    //  - zle ustawione seekg uszkadza plik, wychodzenie poza istniejącą liczbe znaków jest zabronione  //
    //                                                                                                  //
    //////////////////////////////////////////////////////////////////////////////////////////////////////
*/

void fillFile(){
/*
    /////// TO DO ///////////////////////////////
    //                                         //
    //  - dodac wprowadzanie danych do pliku   //
    //                                         //
    /////////////////////////////////////////////

    fstream HTML_TEMPLATE;
    fstream HTML
    fstream HTML_GENERATED;

    HTML_GENERATED.open("/home/mrprivate/Artykuły/GENERATED");
    HTML_TEMPLATE.open("/home/mrprivate/Artykuły/TEMPLATE");

    string upload;

    cin >> upload;
    HTML_GENERATED << upload;

    HTML_GENERATED.seekg(5);
*/
}

void editor(){
/*
    fstream HTML_TEMPLATE;
    fstream HTML_GENERATED;

    HTML_GENERATED.open("/home/mrprivate/Artykuły/GENERATED");
    HTML_TEMPLATE.open("/home/mrprivate/Artykuły/TEMPLATE");
*/

    fillFile();
}

void editorLauncher(){

    char if_picker;
    cout << "Do you want create new article? y/n \n";
    cin >> if_picker;
    if(if_picker == 'y') editor();
}

void lastArticle(){

    fstream HTML_GENERATED;
    HTML_GENERATED.open("/home/mrprivate/Artykuły/DOC.html");

    // w getline, enter jest liczony jako jeden znak

    string download;
    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| Your last article will show in the bottom.               |\n";
    cout << "|__________________________________________________________|\n\n";
    cout << "============================================================\n";

        do{

            getline(HTML_GENERATED, download);
            cout << download << endl;

        }while (download != "</html>");

    cout << "============================================================ \n";

    HTML_GENERATED.close();
}

void checkingFileAndLaunching(){

    fstream HTML_GENERATED;
    HTML_GENERATED.open("/home/mrprivate/Artykuły/GENERATED");

    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";

    if(HTML_GENERATED.good()) {

        cout << "| File Status: the file is checked and ready to work       |\n";
        cout << "|__________________________________________________________|\n";
        HTML_GENERATED.close();

        lastArticle();
        editorLauncher();

    }else {

        cout << "| File Status: the file doesn't exits                      |\n";
        cout << "|__________________________________________________________|\n";
        HTML_GENERATED.close();

    }

}

void banner(){
    cout << " __________________________________________________________ \n";
    cout << "|==========================================================|\n";
    cout << "|========     SUpreme Post Managing System       ==========|\n";
    cout << "|========        by Dawid Rzenno @2016           ==========|\n";
    cout << "|==========================================================|\n";
}

void helper(){

    cout << "|                                                          |\n";
    cout << "| How to use my app:                                       |\n";
    cout << "| I.   You must have 2 files with *.html extention:        |\n";
    cout << "|      - TEMPLATE                                          |\n";
    cout << "|      - GENERATED                                         |\n";
    cout << "|      - PREVIOUS_POST                                     |\n";
    cout << "| II.  That files must be inside folder with application.  |\n";
    cout << "| III. In TEMPLATE.txt you can write your HTML code whose  |\n";
    cout << "|      will be used as template for generator.             |\n";
    cout << "| IV.  In GENERATED.txt you can see your ready-to-paste    |\n";
    cout << "|      code.                                               |\n";
    cout << "|__________________________________________________________|\n";
}

void updates(){

    cout << "|                                                          |\n";
    cout << "| To do:                                                   |\n";
    cout << "| - settings                                               |\n";
    cout << "| - auto-randomizing hints in menu                         |\n";
    cout << "| - *.txt files generator                                  |\n";
    cout << "|                                                          |\n";
    cout << "| Features in upcoming UAMS 2:                             |\n";
    cout << "| - modern, flat designed GUI                              |\n";
    cout << "| - auto-pasting to HTML file                              |\n";
    cout << "| - sending HTML file to FTP server                        |\n";
    cout << "|__________________________________________________________|\n";
}

void instalator(string whatFileNeeded){

    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| What's called your text editor?                          |\n";
    cout << "|__________________________________________________________|\n";
    cout << endl;
    cout << ":";

    string nameOfApp = "gedit"; // default name
    cin >> nameOfApp;

    /////// TO DO ////////////////////////////////////////////////////////////
    //                                                                      //
    //  Dodac przeszukiwanie lokalnego repo i instalacje domyslnego gedit   //
    //  jesli dana aplikacja nie jest zainstalowana na pc                   //
    //                                                                      //
    //////////////////////////////////////////////////////////////////////////

    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| SPMS files will be install in folder including this      |\n";
    cout << "| application                                              |\n";
    cout << "|__________________________________________________________|\n";

    cout << " __________________________________________________________ \n";
    cout << "|                                                          |\n";
    cout << "| Instalation has ended. There was/were created:           |\n";


    if(whatFileNeeded == "template"){

        system( nameOfApp + " TEMPLATE.html");
        cout << "| - TEMPLATE.html                                          |\n";
    }

    if(whatFileNeeded == "generated"){

        system( nameOfApp + "gedit GENERATED.html");
        cout << "| - GENERATED.html                                         |\n";
    }

    if(whatFileNeeded == "previous_post"){

        system( nameOfApp + "gedit PREVIOUS_POST.html");
        cout << "| - PREVIOSU_POST.html                                     |\n";
    }

    cout << "|__________________________________________________________|\n";
}

void installAll(){

    instalator("template");
    instalator("generated");
    instalator("previous_post");
}

void menu(){

    banner();
    helper();
    updates();
}

int main(){

   // menu();
   // checkingFileAndLaunching();

    ///// TO DO ///////////////////////////////////////////////////////
    //                                                               //
    //  - dodac czyszczenie ekranu po wybraniu uruchomienia edytora  //
    //                                                               //
    ///////////////////////////////////////////////////////////////////

   // fillFile();

    installAll();

    return 0;

}
