#ifndef INCLUDED_CLI
#define INCLUDED_CLI

/** Command-line argument namespace. **/
namespace cli {

/** The Options structure is used to hold command-line arguments and flags. **/
typedef struct {
    bool debug;
    bool khal;
    std::string time;
} Arguments;

Arguments* parse_args(int, char**);

}  // namespace cli

#endif /* INCLUDED_CLI */
