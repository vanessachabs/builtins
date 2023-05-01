/*biblioteca*/
#include "env.h"

int main(int argc, char *argv[], char *envp[]) {
    t_info  *info;
    if (!argc)
        (void)(argc);

    info = init_info(envp);
}