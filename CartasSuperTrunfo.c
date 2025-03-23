#include <stdio.h>

int main() {
    char estado, estado2;
    char codigoCarta[4],codigoCarta2[4];
    char cidade[30],cidade2[30];
    int populacao,populacao2;
    float areaKm,areaKm2; 
    float pib,pib2;
    float densidade,densidade2;
    float pibPerCapita,pibPerCapita2;
    int pontosTuristicos,pontosTuristicos2;
    float superPoder, superPoder2;
    int resultPopulacao, resultArea, resultPib, resultPibPerCapita, resultPontosTuristicos, resultDensidade, resultSuperpoder;
    int vencedorPopulacao, vencedorArea, vencedorPib,vencedorPontosTuristicos, vencedorPibPerCapita, vencedorDensidade, vencedorSuperPoder;
    int vencedorCarta1 = 0;
    int vencedorCarta2 = 0;
    int cartaVencedora;


    // Solicita ao usuário digitar dados para a primeira carta e armazena estes dados nas variáveis
    printf("Digite uma Letra de A a H para cadastrar o Estado: \n");
    scanf(" %c", &estado); 

    printf("Digite um número de 01 até 04 para cadastrar o código da Carta:\n");
    scanf("%s", codigoCarta);
    getchar(); 

    printf("Digite o nome da Cidade: \n");
    fgets(cidade, 30, stdin);

    printf("Digite a Area da Cidade em km²: \n");
    scanf("%f", &areaKm);

    printf("Digite o numero de Habitantes : \n");
    scanf("%d", &populacao);

    printf("Digite o PIB da Cidade: \n");
    scanf("%f", &pib);

    printf("Digite a quantidade de pontos turísticos: \n");
    scanf("%d", &pontosTuristicos);
    

    // Solicita ao usuário digitar dados para a segunda carta e armazena estes dados nas variáveis
    printf("\n");
    printf("Digite uma Letra de A a H para cadastrar o Estado: \n");
    scanf(" %c", &estado2); 
    
    printf("Digite um número de 01 a 04 para cadastrar o código da Carta:\n");
    scanf("%s", codigoCarta2);
    getchar(); 
    
    printf("Digite o nome da Cidade: \n");
    fgets(cidade2, 30, stdin);
    
    printf("Digite a Area da Cidade em km²: \n");
    scanf("%f", &areaKm2);
    
    printf("Digite o numero de Habitantes: \n");
    scanf("%d", &populacao2);
    
    printf("Digite o PIB da Cidade: \n");
    scanf("%f", &pib2);
    
    printf("Digite a quantidade de pontos turísticos: \n");
    scanf("%d", &pontosTuristicos2);


    // CALCULA A DENSIDADE POPULACIONAL, PIBPERCAPITA E O ATRIBUTO SUPERPODER DAS CARTAS
    densidade = (float)populacao / areaKm; 
    densidade2 = (float)populacao2 / areaKm2;
    pibPerCapita = pib / (float)populacao; 
    pibPerCapita2 = pib2 / (float)populacao2;
    superPoder = ((float)populacao + areaKm + pib + densidade + (pibPerCapita * -1) + (float)pontosTuristicos);
    superPoder2 = ((float)populacao2 + areaKm2 + pib2 + densidade2 + (pibPerCapita2 * -1) + (float)pontosTuristicos2);

    //verifica se senteça é verdadeira ou falsa e armazena nas variaveis "result"
    resultPopulacao = populacao > populacao2;
    resultArea = areaKm > areaKm2; 
    resultPib = pib > pib2;
    resultPibPerCapita = pibPerCapita < pibPerCapita2;
    resultPontosTuristicos = pontosTuristicos > pontosTuristicos2;
    resultDensidade = densidade > densidade2;
    resultSuperpoder = superPoder > superPoder2;
    
    //Soma +1 na carta para cada atributo que ela vencer na comparação
    vencedorCarta1 += populacao > populacao2;
    vencedorCarta1 += areaKm > areaKm2;
    vencedorCarta1 += pib > pib2;
    vencedorCarta1 += pibPerCapita < pibPerCapita2;
    vencedorCarta1 += pontosTuristicos > pontosTuristicos2;
    vencedorCarta1 += densidade > densidade2;
    vencedorCarta1 += superPoder > superPoder2;
    vencedorCarta2 += populacao2 > populacao;
    vencedorCarta2 += areaKm2 > areaKm;
    vencedorCarta2 += pib2 > pib;
    vencedorCarta2 += pibPerCapita2 < pibPerCapita;
    vencedorCarta2 += pontosTuristicos2 > pontosTuristicos;
    vencedorCarta2 += densidade2 > densidade;
    vencedorCarta2 += superPoder2 > superPoder;
    

    //verifica se Carta 1 ou carta 2 venceu e armazena na variavel vencedor o valor 1 ou 2 
    vencedorPopulacao = (populacao > populacao2) * 1 + (populacao < populacao2) * 2;
    vencedorArea = (areaKm > areaKm2) * 1 + (areaKm < areaKm2) * 2;
    vencedorPib = (pib > pib2) * 1 + (pib < pib2) * 2;
    vencedorPontosTuristicos = (pontosTuristicos > pontosTuristicos2) * 1 + (pontosTuristicos < pontosTuristicos2) * 2;
    vencedorDensidade = (densidade > densidade2) * 1 + (densidade < densidade2) * 2;
    vencedorPibPerCapita = (pibPerCapita < pibPerCapita2) * 1 + (pibPerCapita > pibPerCapita2) * 2;
    vencedorSuperPoder = (superPoder > superPoder2) * 1 + (superPoder < superPoder2) * 2;
    cartaVencedora = (vencedorCarta1 > vencedorCarta2) * 1 + (vencedorCarta1 < vencedorCarta2) * 2;


    //imprimi na tela dados da carta 1
    printf("\n");
    printf("Carta 1: \n");
    printf("Estado: %c \n", estado);
    printf("Código: %c%s \n", estado, codigoCarta);
    printf("Cidade: %s", cidade);
    printf("Area: %.2f km² \n",areaKm);
    printf("Populacao: %d \n", populacao);
    printf("PIB: %.2f Bilhões de Reais \n", pib);
    printf("Pontos Turísticos: %d \n", pontosTuristicos);
    printf("Densidade Populacional: %.2f Hab/Km²\n", densidade);
    printf("PIB per Capita: %.2f Reais\n",pibPerCapita);

    //imprimi na tela dados da carta 2
    printf("\n");
    printf("Carta 2: \n");
    printf("Estado: %c \n", estado2);
    printf("Código: %c%s \n", estado2, codigoCarta2);
    printf("Cidade: %s", cidade2);
    printf("Area: %.2f km² \n",areaKm2);
    printf("populacao: %d \n", populacao2);
    printf("PIB: %.2f Bilhões de Reais \n", pib2);
    printf("Pontos Turísticos: %d \n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f Hab/Km² \n", densidade2);
    printf("PIB per Capita: %.2f Reais \n",pibPerCapita2);

    //Mostra na tela o reusltado da comparação de qual carta venceu
    printf("\n");
    printf("Comparação de Cartas: \n");
    printf("População: Carta %d Venceu (%d)\n", vencedorPopulacao, resultPopulacao);
    printf("Area: Carta %d Venceu (%d)\n", vencedorArea, resultArea);
    printf("PIB: Carta %d Venceu (%d)\n", vencedorPib, resultPib);
    printf("Pontos Turisticos: Carta %d Venceu (%d)\n", vencedorPontosTuristicos, resultPontosTuristicos);
    printf("Densidade Polulacional: Carta %d Venceu (%d)\n", vencedorDensidade, resultDensidade);
    printf("PIB per Capita: Carta %d Venceu (%d)\n", vencedorPibPerCapita, resultPibPerCapita);
    printf("Super Poder: Carta %d Venceu (%d)\n", vencedorSuperPoder, resultSuperpoder);
    printf("\n");
    printf("Carta %d Venceu", cartaVencedora);
    
  
    


    return 0;

}
