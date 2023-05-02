/*biblioteca*/
#include "env.h"

int main(int argc, char *argv[], char *envp[]) {
    t_info  *info;
    if (!argc)
        (void)(argc);
    (void)(argv);
    info = init_info(envp);
    print_list(info->env);
    info->output = -1;
}