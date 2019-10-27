#include <iostream>
#include <string>
#include <fstream>

struct text_class {

    text_class() = default ;

    explicit text_class( const std::string& file_name ) {

        if( std::ifstream file{file_name} ) { // if file was opened successfully

            // read each character in the file and append to text
            char c ;
            while( file.get(c) ) text += c ;
        }

        else {

            // failed to open file
        }
    }

    const std::string& contents() const { return text ; }

    private: std::string text ;
};

int main() {

    const std::string this_file = __FILE__ ;

    std::cout << text_class(this_file).contents() ;
}