# Sistema Netflix

## Descrição

Este é um sistema de gerenciamento de usuários e suas coleções de séries, inspirado no Netflix. Desenvolvido em linguagem C, permite cadastrar usuários, adicionar séries às suas listas pessoais, avaliar séries, favoritar e gerar relatórios sobre as melhores e piores avaliações, além de estatísticas gerais.

O projeto utiliza estruturas de dados como listas duplamente encadeadas para armazenar usuários e séries, proporcionando uma interface de console simples e intuitiva.

## Funcionalidades

### Gerenciamento de Usuários
- **Cadastrar Usuário**: Adiciona um novo usuário ao sistema com ID único gerado automaticamente.
- **Remover Usuário**: Remove um usuário pelo ID.
- **Buscar Usuário**: Busca um usuário pelo nome.
- **Listar Todos os Usuários**: Exibe todos os usuários cadastrados.

### Gerenciamento de Séries
- **Adicionar Série a Usuário**: Permite adicionar uma série à lista de um usuário específico, incluindo nome, gênero, avaliação (1-5) e comentário.
- **Remover Série de Usuário**: Remove uma série da lista de um usuário.
- **Listar Séries de Usuário**: Exibe todas as séries de um usuário específico.
- **Favoritar Série**: Define a avaliação de uma série como 5 (favorita).

### Relatórios
- **Séries Melhor Avaliadas**: Lista as séries com as melhores avaliações (nota 5).
- **Séries Pior Avaliadas**: Lista as séries com as piores avaliações (nota 1).
- **Estatísticas Gerais**: Exibe estatísticas sobre usuários e séries, como número total de usuários, séries por gênero, etc.

### Gêneros Disponíveis
- A - Ação
- C - Comédia
- D - Drama
- F - Ficção Científica
- T - Terror
- R - Romance
- M - Mistério
- V - Animação
- O - Documentário

## Requisitos

- Compilador C (ex: GCC)
- CMake (versão 3.30.5 ou superior)
- Sistema operacional compatível com CMake (Windows, Linux, macOS)

## Instalação e Compilação

1. **Clone o repositório** (se aplicável) ou navegue até o diretório do projeto.

2. **Crie um diretório de build**:
   ```
   mkdir build
   cd build
   ```

3. **Execute o CMake**:
   ```
   cmake ..
   ```

4. **Compile o projeto**:
   ```
   cmake --build .
   ```

5. **Execute o programa**:
   ```
   ./projaed  # No Windows: projaed.exe
   ```

## Uso

Após compilar e executar o programa, você verá o menu principal:

```
=== SISTEMA NETFLIX! ===

 -- Escolha uma opção! --
1. Cadastrar usuario
2. Remover usuario
3. Buscar usuario
4. Listar todos os usuarios
5. Adicionar serie a usuario
6. Remover serie de usuario
7. Listar series de usuario
8. Favoritar serie (dar nota 5)
9. Relatorio - Series melhor avaliadas
10. Relatorio - Series pior avaliadas
11. Estatisticas gerais
0. Sair
```

Digite o número da opção desejada e siga as instruções na tela. O programa valida entradas e fornece feedback para opções inválidas.

## Estrutura do Projeto

```
projaed/
├── CMakeLists.txt          # Arquivo de configuração do CMake
├── main.c                  # Ponto de entrada do programa
├── Lista/
│   ├── lista.c             # Implementação de listas e menus
│   └── lista.h             # Definições de estruturas e protótipos
├── Serie/
│   ├── serie.c             # Funções para gerenciamento de séries
│   ├── serie.h             # Protótipos de funções de séries
│   ├── relatorio.c         # Implementação de relatórios
│   └── relatorio.h         # Protótipos de relatórios
└── Usuario/
    ├── usuario.c           # Funções para gerenciamento de usuários
    └── usuario.h           # Protótipos de funções de usuários
```

## Contribuição

Para contribuir com o projeto:
1. Faça um fork do repositório.
2. Crie uma branch para sua feature (`git checkout -b feature/nova-feature`).
3. Commit suas mudanças (`git commit -am 'Adiciona nova feature'`).
4. Push para a branch (`git push origin feature/nova-feature`).
5. Abra um Pull Request.

## Licença

Este projeto é distribuído sob a licença MIT. Veja o arquivo `LICENSE` para mais detalhes.

## Autor

Desenvolvido como parte de um projeto acadêmico em Estrutura de Dados.