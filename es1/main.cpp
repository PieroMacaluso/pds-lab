#include <iostream>
#include "StringBuffer.h"

int main() {
    printf("Ca");
    StringBuffer s1("Hello");
    StringBuffer s2("world!");
    StringBuffer s0("Ciao", 50);
    StringBuffer s3(s1);
    StringBuffer s4 = s1;
    s0.insert(s1, 6);
    s1.append(" ");
    s1.append(s2);
    printf("%s", s1.c_str()); //Hello world!
    s1.set("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
    s1.append("\n");
    printf("%zu\n", s1.size()); //124
    s2.clear();
    for (int i = 0; i < 10; i++)
        s2.insert(s1, 0);
    printf("%s", s2.c_str()); //Lorem ipsum ... 10 volte
    printf("%zu\n", s2.size()); //1240
    printf("%zu\n", s2.capacity()); //1241
    return 0;
}