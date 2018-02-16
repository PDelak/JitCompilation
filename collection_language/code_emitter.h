#ifndef MACHINE_CODE_EMITTER_H
#define MACHINE_CODE_EMITTER_H

auto emit_machine_code(std::vector<int>* v, const StatementList& statementList)
{
    X86InstrVector i_vector;
    i_vector.push_function_prolog();

    for (auto e : statementList) {
        if (e.value == "add") {
            int value = std::atoi(e.params[0].c_str());
            i_vector.push_back({ 0x68 }); // push
            i_vector.push_back(i_vector.int_to_bytes(value));
            i_vector.push_back({ 0x68 }); // push 
            i_vector.push_back(i_vector.get_address(v)); // address of vector
            i_vector.push_back({ 0xB8 });  // \  mov eax, address of function
            i_vector.push_back(i_vector.get_address(&add));
            i_vector.push_back({ 0xFF, 0xD0 }); // call eax
            i_vector.push_back({ 0x83, 0xC4, 0x08 }); // add esp, 8 (clean stack)
        }
        if (e.value == "mult") {
            int value = std::atoi(e.params[0].c_str());
            i_vector.push_back({ 0x68 }); // push
            i_vector.push_back(i_vector.int_to_bytes(value));
            i_vector.push_back({ 0x68 }); // push 
            i_vector.push_back(i_vector.get_address(v)); // address of vector
            i_vector.push_back({ 0xB8 });  // \  mov eax, address of function
            i_vector.push_back(i_vector.get_address(&mult));
            i_vector.push_back({ 0xFF, 0xD0 }); // call eax
            i_vector.push_back({ 0x83, 0xC4, 0x08 }); // add esp, 8 (clean stack)     
        }
        if (e.value == "sort") {
            i_vector.push_back({ 0x68 }); // push 
            i_vector.push_back(i_vector.get_address(v)); // address of vector
            i_vector.push_back({ 0xB8 });  // \  mov eax, address of function
            i_vector.push_back(i_vector.get_address(&sort));
            i_vector.push_back({ 0xFF, 0xD0 }); // call eax
            i_vector.push_back({ 0x83, 0xC4, 0x04 }); // add esp, 8 (clean stack)
        }
        if (e.value == "filter") {
            int value = std::atoi(e.params[1].c_str());
            int op = 0;
            if (e.params[0] == "==") op = 0;
            if (e.params[0] == "<=") op = -1;
            if (e.params[0] == ">=") op = 1;
            i_vector.push_back({ 0x68 }); // push
            i_vector.push_back(i_vector.int_to_bytes(value));
            i_vector.push_back({ 0x68 }); // push
            i_vector.push_back(i_vector.int_to_bytes(op)); // op
            i_vector.push_back({ 0x68 }); // push 
            i_vector.push_back(i_vector.get_address(v)); // address of vector
            i_vector.push_back({ 0xB8 });  // \  mov eax, address of function
            i_vector.push_back(i_vector.get_address(filter));
            i_vector.push_back({ 0xFF, 0xD0 }); // call eax
            i_vector.push_back({ 0x83, 0xC4, 0x0C }); // add esp, 12 (clean stack)     
        }
    }
    i_vector.push_function_epilog();
    JitCompiler jit(i_vector);
    return jit.compile();
}

#endif
