#include <iostream>
#include "cli.h"

int main(int argc, char *argv[])
{
    auto args = cli::parse_args(argc, argv);
    return 0;
}
