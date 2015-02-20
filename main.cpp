 #include <iostream>
 #include "MagicLamp.h"
 
  namespace arabiannights {
    class Genie;
    class RecyclableDemon;
  }
 
  int main() {
    // 1. Criar uma lâmpada mágica com capacidade para 4 génios.
    // Magic lamp is created in the stack.
    arabiannights::MagicLamp ml(4);
 
    // Items 2. through 7. are simply executed in a cycle.
    int wishes[] = { 2, 3, 4, 5, 1 };  // number of wishes per genie
    arabiannights::Genie *genies[5];                  // vector for genies
 
    // 2. Esfregar 5 vezes a lâmpada, indicando os números de desejos 2, 3, 4, 5, 1.
    for (size_t gx = 0; gx < 5; gx++) genies[gx] = ml.rub(wishes[gx]);
 
    // 3. Imprimir em std::cout (utilizando o operador <<) cada um dos génios.
    for (size_t gx = 0; gx < 5; gx++) std::cout << *genies[gx] << std::endl;
 
    // 4. Pedir um desejo a cada um dos génios.
    for (size_t gx = 0; gx < 5; gx++) genies[gx]->grantWish();
 
    // 5. Imprimir em std::cout (utilizando o operador <<) cada um dos génios.
    for (size_t gx = 0; gx < 5; gx++) std::cout << *genies[gx] << std::endl;
 
    // 6. Pedir um desejo a cada um dos génios.
    for (size_t gx = 0; gx < 5; gx++) genies[gx]->grantWish();
 
    // 7. Imprimir em std::cout (utilizando o operador <<) cada um dos génios.
    for (size_t gx = 0; gx < 5; gx++) std::cout << *genies[gx] << std::endl;
 
    // 8. Colocar o demónio reciclável na lâmpada.
    // tricky (how can we be certain the demon is in the 5th position?)
    ml.feedDemon((arabiannights::RecyclableDemon*)genies[4]);
 
    // 9. Esfregar a lâmpada, indicando 7 como número de desejos.
    arabiannights::Genie *g = ml.rub(7);
 
    // 10. Imprimir em std::cout (utilizando o operador <<) o génio obtido.
    std::cout << *g << std::endl;
 
    return 0;
  }
