#ifndef INTERPRETER_H
#define INTERPRETER_H

void eval(std::vector<int>*v, const StatementList& statementList)
{
    for (auto e : statementList) {
        if (e.value == "add") {
            int value = std::atoi(e.params[0].c_str());
            add(v, value);            
        }
        if (e.value == "mult") {
            int value = std::atoi(e.params[0].c_str());
            mult(v, value);
        }
        if (e.value == "sort") {
            sort(v);
        }
        if (e.value == "filter") {
            int value = std::atoi(e.params[1].c_str());
            int op = 0;
            if (e.params[0] == "==") op = 0;
            if (e.params[0] == "<=") op = -1;
            if (e.params[0] == ">=") op = 1;
            filter(v, op, value);
        }

    }
}

#endif
