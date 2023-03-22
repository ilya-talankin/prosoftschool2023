#ifndef OTHERCOMPARISIONOPERATORS_H
#define OTHERCOMPARISIONOPERATORS_H

template <class Derived>
class OtherComparisionOperators
{
public:
    template<class T>
    bool operator!=(const T& other) const{
        return ((*self > other) || (*self < other));
    }

    template<class T>
    bool operator==(const T& other){
        return !(*self != other);
    }

    template<class T>
    bool operator<=(const T& other){
        return !(*self > other);
    }

    template<class T>
    bool operator>=(const T& other){
        return !(*self < other);
    }

private:
    Derived* self = static_cast<Derived*>(this);
};

#endif // OTHERCOMPARISIONOPERATORS_H
