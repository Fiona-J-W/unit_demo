
#ifndef UNITS_ALIASES_HPP
#define UNITS_ALIASES_HPP

// WARNING: this file is auto-generated, all changes will be lost!!

#include "core.hpp"

namespace units {


template<typename T>
using meter_t = physical_unit<T, std::ratio<1,1>, 1,  0,  0,  0,  0,  0,  0>;
using meter   = meter_t<double>;

inline namespace literals {
auto operator""_m(long double val) {
	return meter{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using square_meter_t = physical_unit<T, std::ratio<1,1>, 2,  0,  0,  0,  0,  0,  0>;
using square_meter   = square_meter_t<double>;

inline namespace literals {
auto operator""_m²(long double val) {
	return square_meter{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using kilogramm_t = physical_unit<T, std::ratio<1,1>, 0,  1,  0,  0,  0,  0,  0>;
using kilogramm   = kilogramm_t<double>;

inline namespace literals {
auto operator""_kg(long double val) {
	return kilogramm{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using gramm_t = physical_unit<T, std::ratio<1,1000>, 0,  1,  0,  0,  0,  0,  0>;
using gramm   = gramm_t<double>;

inline namespace literals {
auto operator""_g(long double val) {
	return gramm{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using sekunde_t = physical_unit<T, std::ratio<1,1>, 0,  0,  1,  0,  0,  0,  0>;
using sekunde   = sekunde_t<double>;

inline namespace literals {
auto operator""_s(long double val) {
	return sekunde{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using minute_t = physical_unit<T, std::ratio<60,1>, 0,  0,  1,  0,  0,  0,  0>;
using minute   = minute_t<double>;

inline namespace literals {
auto operator""_min(long double val) {
	return minute{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using hour_t = physical_unit<T, std::ratio<3600,1>, 0,  0,  1,  0,  0,  0,  0>;
using hour   = hour_t<double>;

inline namespace literals {
auto operator""_h(long double val) {
	return hour{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using ampere_t = physical_unit<T, std::ratio<1,1>, 0,  0,  0,  1,  0,  0,  0>;
using ampere   = ampere_t<double>;

inline namespace literals {
auto operator""_A(long double val) {
	return ampere{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using kelvin_t = physical_unit<T, std::ratio<1,1>, 0,  0,  0,  0,  1,  0,  0>;
using kelvin   = kelvin_t<double>;

inline namespace literals {
auto operator""_K(long double val) {
	return kelvin{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using mol_t = physical_unit<T, std::ratio<1,1>, 0,  0,  0,  0,  0,  1,  0>;
using mol   = mol_t<double>;

inline namespace literals {
auto operator""_mol(long double val) {
	return mol{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using candela_t = physical_unit<T, std::ratio<1,1>, 0,  0,  0,  0,  0,  0,  1>;
using candela   = candela_t<double>;

inline namespace literals {
auto operator""_cd(long double val) {
	return candela{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using newton_t = physical_unit<T, std::ratio<1,1>, 1,  1, -2,  0,  0,  0,  0>;
using newton   = newton_t<double>;

inline namespace literals {
auto operator""_N(long double val) {
	return newton{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using joule_t = physical_unit<T, std::ratio<1,1>, 2,  1, -2,  0,  0,  0,  0>;
using joule   = joule_t<double>;

inline namespace literals {
auto operator""_J(long double val) {
	return joule{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using watt_t = physical_unit<T, std::ratio<1,1>, 2,  1, -3,  0,  0,  0,  0>;
using watt   = watt_t<double>;

inline namespace literals {
auto operator""_W(long double val) {
	return watt{static_cast<double>(val)};
}
} //namespace literals



template<typename T>
using hertz_t = physical_unit<T, std::ratio<1,1>, 0,  0, -1,  0,  0,  0,  0>;
using hertz   = hertz_t<double>;

inline namespace literals {
auto operator""_Hz(long double val) {
	return hertz{static_cast<double>(val)};
}
} //namespace literals



} //namespace units

#endif

