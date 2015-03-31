
#include <cmath>
#include <ostream>
#include <iostream>
#include <cassert>

// Basic units:

#include "../include/core.hpp"
#include "../include/aliases.hpp"

int main() {
	using namespace units::literals;

	auto distance1 = units::meter{3.0};
	auto distance2 = 4.0_m;
	auto time      = 2.5_s;
	auto area      = 15.0_m²;

	distance2 += 5.0_m;

	auto avg_speed1 = distance1 / time;
	auto avg_speed2 = distance2 / time;

	auto weird = distance1 * avg_speed1 / area;

	std::cout << weird << "\n";
	std::cout << avg_speed1 << "\n";
	std::cout << area << "\n";
	assert(avg_speed1 != avg_speed2);

	auto room = units::pow<3>(1.0_m);
	std::cout << room << '\n';

	std::cout << 5.0_m / 3.0_h << '\n';
}

