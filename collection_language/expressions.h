#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

void add(std::vector<int>* v, int value)
{
    std::for_each(v->begin(), v->end(), [&](int& element) { element += value;});
}

void mult(std::vector<int>* v, int value)
{
    std::for_each(v->begin(), v->end(), [&](int& element) { element *= value;});
}

void sort(std::vector<int>* v)
{
    std::sort(v->begin(), v->end());
}

void merge(std::vector<int>* v1, std::vector<int>* v2)
{
    std::copy(v2->begin(), v2->end(), std::back_inserter(*v1));
}

void filter(std::vector<int>* v, int op, int value)
{
    auto equal = [&](int element) { return value == element;};
    auto smaller = [&](int element) { return element < value;};
    auto larger = [&](int element) { return element > value;};
    switch (op) {
        case -1: {
            auto begin = std::remove_if(v->begin(), v->end(), smaller);
            v->erase(begin, v->end());
            break;
        }
        case 0: {
            auto begin = std::remove_if(v->begin(), v->end(), equal);
            v->erase(begin, v->end());
            break;
        }
        case 1: {
            auto begin = std::remove_if(v->begin(), v->end(), larger);
            v->erase(begin, v->end());
            break;
        }
    }
}

#endif
