# Diretorio aux

Nesse diretório estão os códigos fontes para alguns programas que podem auxiliar nos laboratórios (trabalhos) da disciplina. 

Além dos arquivos arquivos fontes com códigos em C, há também um ``makefile`` para compilar esses arquivos. **Sugere-se que os alunos observem os códigos fontes, bem como o arquivo ``makefile``, de modo que possam usar estratégias parecidas para implementar as soluções para o trabalho.**

## Programas nesse diretório

Nesse diretório estão os códigos fontes para dois programas. Um deles, ``generateRandomMatrix.c``, gera uma matriz de números inteiros aleatórios; outro, ``generateRandomMatrixDouble.c``, gera uma matriz de números reais aleatórios com até duas casas decimais. Ambos os programas utilizam funções auxiliares que estão no arquivo ``MatrixIO.c`` e seu cabecalho ``MatrixIO.h``.

O arquivo ``makefile`` contém as instruções para compilar e gerar os programas. Para compilar o programa basta executar o comando ``make`` (sem aspas). Depois de compilado, execute o programa ``./generateRandomMatrix`` ou ``./generateRandomMatrixDouble`` (sem aspas) para ver os parâmetros que os programas aceitam.
