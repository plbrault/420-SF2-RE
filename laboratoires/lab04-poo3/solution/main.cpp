#include <iostream>
#include "Time.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Time time(13, 25, 19);

    std::cout << "Entrer une heure (hh:mm:ss): ";
    std::cin >> time;

    std::cout << "L'heure entrée est: " << time << std::endl;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}