# builtins
Como funciona determinados comandos e situações em um terminal BASH. Será estruturada as funções que irão manipular as variáveis de ambientes do programa. Será utilizado o terceiro parâmetro da função main() para conseguir esse feito.

A variável `env` é um ponteiro para um array de strings, onde cada elemento do array é uma string contendo um par de chave-valor, separado pelo caractere '='. Por exemplo, o par de chave-valor "PATH=/usr/local/bin" significa que a variável PATH tem o valor "/usr/local/bin".

O array de strings é terminado com um elemento nulo, ou seja, uma string vazia. Por convenção, o último elemento do array é sempre nulo, indicando o fim da lista de variáveis de ambiente.

A variável `env` é geralmente usada em programas C para acessar ou definir variáveis de ambiente do sistema.

Para rodar execute o seguinte comando `make` Depois execute ```./builtins```

Use ```makefclean``` para limpar os objetos. Para recompilar utilize ```make re```

Testando export:

`./builtins export student=yourname` ou `./envir export`
