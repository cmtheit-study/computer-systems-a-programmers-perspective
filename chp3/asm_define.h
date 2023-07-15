//
// Created by cmtheit on 23-7-15.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ASM_DEFINE_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ASM_DEFINE_H

#define ASM_DEFINE(name, ...) \
long asm_##name(__VA_ARGS__);  \
long name(__VA_ARGS__)                              \


#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ASM_DEFINE_H
