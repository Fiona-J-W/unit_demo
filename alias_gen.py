#! /usr/bin/python3

header = """
#ifndef UNITS_ALIASES_HPP
#define UNITS_ALIASES_HPP

// WARNING: this file is auto-generated, all changes will be lost!!

#include "core.hpp"

namespace units {
"""

template = """

template<typename T>
using {0}_t = physical_unit<T, std::ratio<{3}>, {2}>;
using {0}   = {0}_t<double>;

inline namespace literals {{
auto operator""{1}(long double val) {{
\treturn {0}{{static_cast<double>(val)}};
}}
}} //namespace literals

"""

footer = """

} //namespace units

#endif

"""


def main():
    input = open("src/data/aliases.txt", "r")
    output = open("src/include/aliases.hpp", "w")
    output.write(header)
    for line in input:
        (name, short, dimension, factor) = line.split(";")
        output.write(template.format(name.strip(), short.strip(),
                                     dimension.strip(), factor.strip()))
    output.write(footer)
    output.close()

if __name__ == "__main__":
    main()
