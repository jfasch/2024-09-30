#include "tmpdir-fixture.h"

#include <cassert>


void tmpdir_fixture::SetUp()
{
    static const unsigned max_tries = 1000;

    auto tmpdir = std::filesystem::temp_directory_path();
    unsigned n_tries = 0;
    std::random_device dev;
    std::mt19937 prng(dev());
    std::uniform_int_distribution<uint64_t> rand(0);
    std::filesystem::path path_found;
    for (;;) {
        std::stringstream ss;
        ss << std::hex << rand(prng);
        path_found = tmpdir / ss.str();

        if (std::filesystem::create_directory(path_found))
            break;
        if (n_tries == max_tries)
            assert(false);

        n_tries++;
    }

    dirname = path_found;
}

void tmpdir_fixture::TearDown()
{
    std::filesystem::remove_all(dirname);
}
