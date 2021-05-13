#ifndef MCOUNT_H
#define MCOUNT_H


class MCount
{
public:
    MCount();
    int add_1();
    int add_10();
    int add_100();
    int add_1000();
    int reset();
    int count() const;
    bool is_error() const;
private:
    int counter;
};

#endif // MCOUNT_H
