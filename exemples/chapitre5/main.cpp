#include <iostream>
#include "Felin.h"
#include "Chat.h"
#include "Lion.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Chat felix;
    Lion simba;

    felix.manger();
    felix.dormir();
    felix.miauler();

    simba.manger();
    simba.dormir();
    simba.rugir();

    Felin felins[2];
    felins[0] = felix;
    felins[1] = simba;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.