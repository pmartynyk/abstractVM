
#pragma once

#define CMD "\\s*(pop|dump|add|sub|mul|div|mod|print|exit)\\s*(;.*|[]{0,0})"
#define CMD_VAL "\\s*(push|assert)\\s+(int8|int16|int32|float|double)[(](([-+]?)((\\d+|\\d+.\\d+)|((\\d+|\\d+.\\d+)[Ee]?[-+]?\\d+)))[)]\\s*(;.*|[]{0,0})"
#define CMDERR "\\s*(.*)\\s*(;.*|[]{0,0})"
// #define CMDERRVAL "\\s*(.*)\\s+(int8|int16|int32|float|double)[(](([-+]?)((\\d+|\\d+.\\d+)|((\\d+|\\d+.\\d+)[Ee]?[-+]?\\d+)))[)]\\s*(;.*|[]{0,0})"
#define CMDERRVAL "\\s*(.*)\\s+(\\w*)[(](\\d*)[)]\\s*"
#define CMDLEX "(^pop$|^dump$|^add$|^sub$|^mul$|^div$|^mod$|^print$|^push$|^assert$|^exit$)"
#define CMT ";.*"
#define EMPTY "\\s*"
#define EXIT "(\\s*(exit)\\s*|;;\\s*)(;.*|[]{0,0})"