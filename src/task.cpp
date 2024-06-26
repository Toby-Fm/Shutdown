//
// Created by tobyw on 11.06.2024.
//

#include "include/task.hpp"

#include <windows.h>
#include <tlhelp32.h>

void task::readTask() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    // Schnappschuss der aktuellen Prozesse erstellen
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        std::cout << "Fehler beim erstellen vom Snapshot" << std::endl;
        return;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Den ersten Prozess im Schnappschuss abrufen
    if (!Process32First(hProcessSnap, &pe32)) {
        std::cout << "Fehler den ersten Prozess zu bekommen" << std::endl;
        CloseHandle(hProcessSnap);
        return;
    }

    // Alle Prozesse im Schnappschuss durchgehen und ihre Namen ausgeben
    do {
        std::wcout << "Programm: " << pe32.szExeFile << std::endl;
    } while (Process32Next(hProcessSnap, &pe32));

    // Schnappschuss-Handle schließen
    CloseHandle(hProcessSnap);
}

void task::killTask() {
    // Nothing
}
