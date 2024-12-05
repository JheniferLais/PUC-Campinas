//Constantes sempre que declaradas devem ser inicializadas imediatamente.
const nome: string = "Jhenifer Laís Barbosa";
console.log("Bom dia: " + nome);

//Programa para calcular comprimento da circunferencia.
const PI: number = 3.1415;
const R: number = 10;
//Calculo
(2 * PI * R) //Nesse caso a expressão não é utilizada.
console.log(2 * PI * R); //Nesse caso a expressão é utilizada no print.
const comp: number = (2 * PI * R); //Nesse caso a expressão é atribuida a constante 'comp'.

// Programa para calcular a área do círculo.
function calcularAreaCirculo(R: number): number {
    const PI: number = 3.1415;
    const AREA: number = (PI * R * R);
    return AREA;
}
const A: number = calcularAreaCirculo(10); //Nesse caso a função é atribuida a constante 'A'.
console.log(A);  // Saída: 314.15
