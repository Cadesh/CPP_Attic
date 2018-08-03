/// COMPOSITION, AGGREGATION & ASSOCIATION
/// Cadesh
/// 02AGO2018

//I read some internet pages with the wrong explantion about this
//this is the right one

class Bar1 {};
//-----------------------------------------------------------
// COMPOSTION
// myBar is defined inside Foo0 (as a pointer or no), if Foo0 is destroyed myBar is gone
class Foo0
{
    Bar1 myBar;
};
//-----------------------------------------------------------
// AGGREGATION
// Foo1 has a pointer to a Bar1 defined somewhere else, if Foo1 is 
// destroyed the outside object Bar1 survives
class Foo1
{
    Bar1* myBar;
    void setBar(Bar1& _bar)
    {
        MyBar = &_bar;
    }
};
//------------------------------------------------------------
// ASSOCIATION
// Bar2 and Foo2 are associated to each other, each one has a
// pointer to the other object
// you must have a two way link
class Bar2 {
    Foo2* foo; 
    void setFoo(Foo2& _foo)
    {
        foo = &_foo;
    }
};
class Foo2
{
    Bar* bar;
    void setBar(Bar& _bar)
    {
        bar = &_bar;
    }
};




