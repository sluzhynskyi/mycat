#include <iostream>
#include <boost/program_options.hpp>
#include "operations_with_files.hpp"

namespace po = boost::program_options;


int main(int argc, char **argv) {
    try {
        int a_flag = 0;
        po::options_description visible("General options");
        visible.add_options()
                ("help,h", "Show help")
                ("show-all,A",
                 "Show all invisible (except whitespaces) in hexadecimal form");

        po::options_description hidden("Hidden options");
        hidden.add_options()
                ("files", po::value<std::vector<std::string>>(), "files");
        po::positional_options_description p;
        p.add("files", -1);

        po::options_description all("All options");
        all.add(visible).add(hidden);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(all).positional(p).run(), vm);
        po::notify(vm);

        std::string usage = "Usage:\n  mycat [-h|--help] [-A|--show-all] [--files] <file1> <file2> ... <fileN> \n";
        if (vm.count("help")) {
            std::cout << usage << visible << std::endl;
            return EXIT_SUCCESS;
        }
        if (vm.count("show-all")) {
            a_flag = 1;
        }
        if (vm.count("files")) {
            if (a_flag == 1) {
                std::cout << "Flagged A" << std::endl;
            }
            for (auto const &i: vm["files"].as<std::vector<std::string> >()) {
                std::cout << i << std::endl;
            }
        } else {
            std::cout << usage << std::endl;
            return EXIT_FAILURE;
        }
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
