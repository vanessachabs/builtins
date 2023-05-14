/*biblioteca*/
#include "env.h"

int main(int argc, char *argv[], char *envp[]) {
    t_info  *info;
    //int i = 2;
    if (!argc)
        (void)(argc);
    (void)(argv);
    info = init_info(envp);
    //print_list(info->env);
    /*while (i < argc)
    {
        printf("%s", argv[2]);
        i++;
    }*/
    if (ft_strncmp(argv[1], "export", 7) == 0)
       export_builtins(argc, argv, info);
    print_list(info->env);
    info->output = -1;
}