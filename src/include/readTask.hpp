//
// Created by tobyw on 11.06.2024.
//

#ifndef READTASK_HPP
#define READTASK_HPP

#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

void readTask() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    // Schnappschuss der aktuellen Prozesse erstellen
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        std::cout << "CreateToolhelp32Snapshot (of processes)" << std::endl;
        return;
    }


}

#endif //READTASK_HPP
