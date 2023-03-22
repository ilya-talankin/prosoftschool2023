#include "OtherComparisionOperators.h"
#include <type_traits>
#include <iostream>


template <typename T, typename ...OtherTypes>
struct any_of
{
    static constexpr bool value = (std::is_same_v<T, OtherTypes> || ...);
};

template <typename T, typename ...OtherTypes>
constexpr bool any_of_v = any_of<T, OtherTypes...>::value;


class B
{
public:
    B(int a, int b): m_a(a), m_b(b) {};
    int m_a = 0;
    int m_b = 0;
};

class A : public OtherComparisionOperators<A>
{
public:
    A(int a, int b) : m_a(a), m_b(b){}

    template <typename OtherT>
    std::enable_if_t<any_of_v<OtherT, A, B>, bool>

    operator<(const OtherT& other) const
    {
        return (m_a < other.m_a) && (m_b < other.m_b);
    }

    template <typename OtherT>
    std::enable_if_t<any_of_v<OtherT, A, B>, bool>
    operator>(const OtherT& other) const
    {
        return (m_a > other.m_a) && (m_b > other.m_b);
    }

    template <typename OtherT>
    std::enable_if_t<std::is_integral_v<OtherT>, bool> 
    operator<(const OtherT& other) const
    {
        return m_a < other;
    }

    template <typename OtherT>
    std::enable_if_t<std::is_integral_v<OtherT>, bool> 
    operator>(const OtherT& other) const
    {
        return m_a > other;
    }


private:
    int m_a = 0;
    int m_b = 0;
};


