#ifndef UNITS_CORE_HPP
#define UNITS_CORE_HPP

#include <cmath>
#include <ostream>
#include <ratio>
#include <string_view>
#include <array>

namespace units {


template<typename T, typename Factor = std::ratio<1,1>,
         int M = 0, int KG = 0, int S = 0, int A = 0,
         int K = 0, int Mol = 0, int CD = 0>
class physical_unit {
public:
	explicit physical_unit(T value): m_value{value} {}
	
	T get_value() const {return m_value;}
private:
	T m_value;
};


template<int Dimension, typename Stream, typename String>
bool print_unit_to_stream(Stream& stream, const String& name, bool first) {
	constexpr auto superscript_digits = std::array<std::string_view, 10>{{"⁰", "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"}};
	if (Dimension == 0) {
		return first;
	}
	if (first) {
		stream << " ";
	} else {
		stream << "⋅";
	}
	stream << name;
	if (Dimension < 0) {
		stream << "⁻";
	}
	auto dimension = std::abs(Dimension);
	while (dimension > 0) {
		stream << superscript_digits[dimension  % 10];
		dimension /= 10;
	}
	return false;

}

template<typename Char, typename T, typename Ratio,
         int M, int KG, int S, int A, int K, int Mol, int CD>
std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& stream,
                                     physical_unit<T, Ratio, M, KG, S, A, K, Mol, CD> value) {
	stream << value.get_value() * Ratio::num / Ratio::den;
	auto first = true;
	first = print_unit_to_stream<M>(stream, "m", first);
	first = print_unit_to_stream<KG>(stream, "kg", first);
	first = print_unit_to_stream<S>(stream, "s", first);
	first = print_unit_to_stream<A>(stream, "A", first);
	first = print_unit_to_stream<K>(stream, "K", first);
	first = print_unit_to_stream<Mol>(stream, "mol", first);
	first = print_unit_to_stream<CD>(stream, "cd", first);
	return stream;
}

template<typename T, typename Ratio, int...Dimensions>
auto operator+(physical_unit<T, Ratio, Dimensions...> lhs,
               physical_unit<T, Ratio, Dimensions...> rhs) {
	return physical_unit<T, Ratio, Dimensions...>{lhs.get_value() + rhs.get_value()};
}
template<typename T, typename Ratio, int...Dimensions>
decltype(auto) operator+=(physical_unit<T, Ratio, Dimensions...>& lhs,
                          physical_unit<T, Ratio, Dimensions...> rhs) {
	auto tmp = lhs + rhs;
	return lhs = tmp;
}

template<typename T, typename Ratio, int...Dimensions>
auto operator-(physical_unit<T, Ratio, Dimensions...> lhs,
               physical_unit<T, Ratio, Dimensions...> rhs) {
	return physical_unit<T, Ratio, Dimensions...>{lhs.get_value() - rhs.get_value()};
}
template<typename T, typename Ratio, int...Dimensions>
decltype(auto) operator-=(physical_unit<T, Ratio, Dimensions...>& lhs,
                          physical_unit<T, Ratio, Dimensions...> rhs) {
	auto tmp = lhs - rhs;
	return lhs = tmp;
}

template<typename T, typename Ratio1, int M1, int KG1, int S1, int A1, int K1, int Mol1, int CD1,
                     typename Ratio2, int M2, int KG2, int S2, int A2, int K2, int Mol2, int CD2>
auto operator*(physical_unit<T, Ratio1, M1, KG1, S1, A1, K1, Mol1, CD1> lhs,
               physical_unit<T, Ratio2, M2, KG2, S2, A2, K2, Mol2, CD2> rhs) {
	return physical_unit<T, std::ratio_multiply<Ratio1, Ratio2>,
	                     M1+M2, KG1+KG2, S1+S2, A1+A2, K1+K2, Mol1+Mol2, CD1+CD2>{
		lhs.get_value() * rhs.get_value()};
}

template<typename T, typename Ratio1, int M1, int KG1, int S1, int A1, int K1, int Mol1, int CD1,
                     typename Ratio2, int M2, int KG2, int S2, int A2, int K2, int Mol2, int CD2>
auto operator/(physical_unit<T, Ratio1, M1, KG1, S1, A1, K1, Mol1, CD1> lhs,
               physical_unit<T, Ratio2, M2, KG2, S2, A2, K2, Mol2, CD2> rhs) {
	return physical_unit<T, std::ratio_divide<Ratio1, Ratio2>, M1-M2,
	                     KG1-KG2, S1-S2, A1-A2, K1-K2, Mol1-Mol2, CD1-CD2>{
		lhs.get_value() / rhs.get_value()};
}

template<typename T, typename Ratio, int... Dimensions>
bool operator==(physical_unit<T, Ratio, Dimensions...> lhs,
                physical_unit<T, Ratio, Dimensions...> rhs) {
	return lhs.get_value() == rhs.get_value();
}
template<typename T, typename Ratio, int... Dimensions>
bool operator<(physical_unit<T, Ratio, Dimensions...> lhs,
               physical_unit<T, Ratio, Dimensions...> rhs) {
	return lhs.get_value() < rhs.get_value();
}

template<typename T, typename Ratio, int... Dimensions>
bool operator!=(physical_unit<T, Ratio, Dimensions...> lhs,
                physical_unit<T, Ratio, Dimensions...> rhs) {
	return !(lhs == rhs);
}
template<typename T, typename Ratio, int... Dimensions>
bool operator<=(physical_unit<T, Ratio, Dimensions...> lhs,
                physical_unit<T, Ratio, Dimensions...> rhs) {
	return !(rhs < lhs);
}
template<typename T, typename Ratio, int... Dimensions>
bool operator>=(physical_unit<T, Ratio, Dimensions...> lhs,
                physical_unit<T, Ratio, Dimensions...> rhs) {
	return !(lhs < rhs);
}

template<typename T, typename Ratio, int... Dimensions>
bool operator>(physical_unit<T, Ratio, Dimensions...> lhs,
               physical_unit<T, Ratio, Dimensions...> rhs) {
	return rhs < lhs;
}


} // namespace units


#endif
