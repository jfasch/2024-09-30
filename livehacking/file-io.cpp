#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << argv[0] << ": <in-filename> <out-filename\n";
        return 1;
    }

    const char* in_filename = argv[1];
    const char* out_filename = argv[2];
    
    std::ifstream inf(in_filename);
    int temperature;
    inf >> temperature;

    std::ofstream outf(out_filename);
    outf << temperature/1000.0 << '\n';

    return 0;
}
