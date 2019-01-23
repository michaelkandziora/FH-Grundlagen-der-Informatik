#include <iostream>


int main ( )
{
    long long i,j, groesse=1, letzte;
    int offset=8;
    int end=8;
    int *feld;


    std::locale system_locale("");
    std::cout.imbue(system_locale);
    std::cin.imbue(system_locale);


    for(i=1e1; i<1e12; i*=10){
        for(j=1; j<end; j+=offset){
            if (i>1e2) { offset=4; }
            if (i>1e4) { offset=2; }
            if (i>1e6) { offset=1; end=10; }
            letzte=groesse;
            groesse = i*j;
            try
            {
                std::cout << "Hole Speicherplatz für ein Feld mit " << groesse << " Integers ... ";
                feld = new int[groesse];

                std::cout << "und gib diesen Speicher wieder frei.\n";
                delete[] feld;
            }
            catch (std::bad_alloc& ba)
            {
                std::cout << "fehlgeschlagen / maximale Feldgröße wurde überschritten.\n\n";

                if (letzte >= 1e8)
                {
                    std::cout << "\nIhr Computer kann Felder mit " << letzte << " Integers anlegen. => Test bestanden, alles OK :-)\n";
                    std::cout << "Bitte erweitern Sie Ihr Sortierprogramm aus 'Programmieren C++1'  JETZT so, dass das Feld dynamisch angelegt wird.\n";
                    std::cout << "Ergänzen Sie den Zufallszahlengenerator so, dass mindestens 32 Bit der Zahlen zufällig sind.\n\n";
                } else {
                    std::cout << "\nIhr Computer kann Felder mit " << groesse << " Integers NICHT anlegen.  =>  Das ist  NICHT  ausreichend.\n\n";
                    std::cout << "Bitte checken Sie die Einstellungen Ihres Compilers, die Einstellungen Ihrer Shell\n";
                    std::cout << "und die Einstellungen in Ihrem Betriebssystem.\n\n";
                    std::cout << "Beheben Sie das Speicherproblem auf Ihrem Computer bitte HEUTE mit Hilfe der Drittsemester, ...).\n";
                    std::cout << "Für die kommenden Aufgaben muss Ihr Computer grosse Felder anlegen können.\n\n\n\n";
                }

                return 1;
            }

        }
    }

    std::cout << "\nIhr Computer kann Felder mit " << groesse << " Integers anlegen. => Test bestanden, alles OK :-)\n";
    std::cout << "Bitte erweitern Sie Ihr Sortierprogramm aus 'Programmieren C++1'  JETZT so, dass das Feld dynamisch angelegt wird.\n";
    std::cout << "Ergänzen Sie den Zufallszahlengenerator so, dass mindestens 32 Bit der Zahlen zufällig sind.\n\n";

    return 0;
}