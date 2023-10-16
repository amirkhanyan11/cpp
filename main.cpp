#include <iostream>
#include <fstream>
std::string run_length_encode(std::string);
void code_and_insert(std::fstream&, std::fstream&);

int main() {

    std::fstream source;
    std::fstream destination;

    source.open("src.txt");
    destination.open("dest.txt");

    code_and_insert(source, destination);

    source.close();
    destination.close();

    return 0;
}

std::string run_length_encode(std::string source) {

    std::string output_string;

    for(int i = 0; i < source.length(); ) {

        if(source[i] == ' ') {
            continue;
        }

        int current_count = 0;
        char j = i;

        while(source[j] == source[i]) {
            current_count++;
            j++;
        }

        output_string.push_back(source[i]);
        output_string += std::to_string(current_count);
        i = j;
    }

    return output_string;
}

void code_and_insert(std::fstream& source, std::fstream& destination) {
    
    std::string current;

    while(!source.eof()) {
        std::getline(source, current);
        destination << run_length_encode(current) << std::endl;
    }

    return;
}






