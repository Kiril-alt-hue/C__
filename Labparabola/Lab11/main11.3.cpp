#include "functions11.3.h"


int main() {
    const char *file_F_name = "F.txt";
    const char *file_G_name = "G.txt";

    create_file_F(file_F_name);

    create_file_G(file_F_name, file_G_name);

    return 0;
}