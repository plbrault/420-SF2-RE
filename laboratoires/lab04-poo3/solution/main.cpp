#include <iostream>
#include "Time.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Time time;

    time.addHours(13).addMinutes(59).addSeconds(31);
    std::cout << "\n" << time.toString();

    time.addSeconds(100);
    std::cout << "\n" << time.toString();

    time.addMinutes(120);
    std::cout << "\n" << time.toString();

    time.subtractSeconds(120);
    std::cout << "\n" << time.toString();
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}