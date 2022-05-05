#include <iostream>

std::string repeat(std::string str, int reps){
    std::string res;
    for(int i = 0; i < reps; i++)    {
        res += str;
    }
    return res;
}


int main(){
    std::cout << "Geben Sie eine Anzahl an Wiederholungen ein: " << std::endl;

    int reps;
    std::cin >> reps;

    std::cout << "Geben Sie eine Zeichenkette ein: " << std::endl;

    std::string str;
    std::cin >> str;

    std::string result = repeat(str, reps);
    std::cout << "Das Resultat ist: " << std::endl;
    std::cout << result << std::endl;

    return 0;
}