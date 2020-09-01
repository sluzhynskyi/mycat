#include <iostream>
#include <boost/program_options.hpp>


int main(int argc, char **argv) {
    int variable_a, variable_b;

    namespace po = boost::program_options;
    po::options_description desc("General options");
    desc.add_options()
            ("help,h", "Show help")
            (",A", "Stdout of invisible characters (other than whitespaces) in Hexadecimal form")
            ("files", po::value<std::vector<std::string>>(), "files");
    po::positional_options_description p;
    p.add("files", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
    po::notify(vm);
    if (vm.count("files")) {
        for (auto const &i: vm["files"].as<std::vector<std::string> >()) {
            std::cout << i << std::endl;
        }
        return EXIT_SUCCESS;
    }
    if (vm.count("help")) {
        std::cout << "Usage:\n  mycat [-h|--help] [-A] [--files] <file1> <file2> ... <fileN> \n" << desc << std::endl;
        return EXIT_SUCCESS;
    }


    return EXIT_SUCCESS;
}
