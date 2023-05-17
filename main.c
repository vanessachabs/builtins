/*biblioteca*/
#include "env.h"

int main(int argc, char *argv[], char *envp[]) {
    t_info  *info;
    if (argc == 1)
    {
        printf("Tente ./builtins export ou ./builtins export key=value\n");
        printf("ou ./builtins unset key\n");
        return (0);
    }
    info = init_info(envp);
    if (ft_strncmp(argv[1], "export", 7) == 0)
       export_builtins(argc, argv, info);
    else if (ft_strncmp(argv[1], "unset", 5) == 0)
       unset_builtins(argc, argv, info);
    else if (ft_strncmp(argv[1], "env", 3) == 0)
        print_list(info->env);
    info->output = -1;
    return (0);
}