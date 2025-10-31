# Listas_e_Ordena-o.c

DESAFIO NÍVEL AVENTUREIRO - LISTAS E ORDENAÇÃO
By Speedydev77

O que você vai fazer?
Sua responsabilidade neste nível é comparar duas formas diferentes de organizar e acessar os dados da mochila: o uso de vetores (listas sequenciais) e listas encadeadas (estruturas dinâmicas). O objetivo é demonstrar como a escolha da estrutura de dados pode influenciar na performance do jogo, em especial, em situações de pressão, como a zona de perigo. 
 
Sua missão é desenvolver duas versões do sistema de mochila: uma usando vetor e outra com lista encadeada. Você deverá implementar as mesmas operações básicas (inserção, remoção, listagem e busca) nas duas versões, e, ao final, comparar o desempenho das estruturas. Após ordenar os dados no vetor, você deverá aplicar uma busca binária para localizar com rapidez um item crítico.
Requisitos funcionais
Confira as principais funcionalidades do sistema a serem implementadas:
 
1. Criação de structs:
 
Item: com os campos char nome[30], char tipo[20], int quantidade.
 
No: com os campos Item dados e struct No* proximo para a lista encadeada.
 
2. Implementações paralelas:
 
Mochila com vetor (lista sequencial).
 
Mochila com lista encadeada.
 
3. Operações obrigatórias nas duas estruturas:
 
Inserir novo item.
 
Remover item por nome.
 
Listar todos os itens da mochila.
 
Buscar item por nome (busca sequencial).
 
4. Ordenação no vetor: 
 
Ordenar os itens por nome (Bubble Sort ou Selection Sort).
 
5. Busca binária (apenas no vetor):
 
Após a ordenação, permitir busca binária por nome.
 
6. Contador de operações:
 
Exibir o número de comparações realizadas em cada tipo de busca (sequencial e binária).
Requisitos não funcionais
Considere também os seguintes critérios relevantes durante o desenvolvimento:
 
1. Usabilidade: o menu deve permitir ao jogador escolher entre vetor ou lista e mostrar os resultados com clareza.
 
2. Eficiência: o sistema deve apresentar tempo de resposta inferior a 2 segundos em cada operação.
 
3. Documentação: comentar o código explicando cada função e destacando as diferenças entre as estruturas.
 
4. Clareza na nomenclatura: usar nomes de variáveis e funções representativos do comportamento esperado.
Instruções detalhadas
A seguir, veja os elementos básicos que devem compor a estrutura do programa:
 
1. Bibliotecas necessárias: stdio.h, stdlib.h, string.h, time.h (opcional para medir tempo).
 
2. Modularização:
 
Crie arquivos ou funções separadas para o vetor e a lista encadeada.
 
Crie funções: inserirItemVetor, removerItemVetor, ordenarVetor, buscarSequencialVetor, buscarBinariaVetor, e equivalentes para a lista encadeada.
 
3. Contadores: 
 
Inclua variáveis globais ou ponteiros para contar o número de comparações feitas em cada tipo de busca.
Comentários adicionais
O foco deste desafio é o desenvolvimento da habilidade de comparar estruturas de dados na prática. Você compreenderá que vetores e listas encadeadas têm comportamentos diferentes em operações básicas e que a ordenação é fundamental para habilitar algoritmos de busca mais rápidos, como a busca binária. O desafio ainda introduz o conceito de análise empírica, aproximando a experiência da realidade enfrentada por desenvolvedores ao lidar com decisões de desempenho em jogos e aplicações críticas.
<img width="1119" height="1807" alt="image" src="https://github.com/user-attachments/assets/3a467cb3-a196-4b00-9848-88c77fb2a642" />
