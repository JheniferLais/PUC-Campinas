//----------------------------------------------------------------------------------------------------------------------

//O QUE É UM TIPO? (tipo por isso Typescript)

var numero = 10; //Nesse caso não especifica o tipo
var contador: number = 0; //Nesse caso especificando o tipo(number)

//----------------------------------------------------------------------------------------------------------------------

//COMO CRIAR TIPO PERSONALIZADO?

type pessoa = {
    //Propriedades do tipo
    nome: string;
    idade: number;
}

//Como usar o tipo criado(Ordem não importa pois estão nomeadas)
var P1: pessoa = {
    nome: "Jhenifer",
    idade: 20
}
var P2: pessoa = {
    nome: "Lorenna",
    idade: 18
}

//Testando se as pessoas são as mesmas
if(P1 === P2){
    console.log("SIM");
}
else{
    console.log("NÃO");
}

//----------------------------------------------------------------------------------------------------------------------

//COMO CRIAR TIPO ONDE A PROPRIEDADE É OPCIONAL?

type professor = {
    nome: string;
    titulo: string;
    tipo_sanguineo?: string; //Nesse caso 'tipo_sanguineo' é opcional
}
var professor: professor = {
    nome: "Matheus",
    titulo: "Mestre"
}

//----------------------------------------------------------------------------------------------------------------------

//COMPARAÇÃO

//if(A === B){ Compara o tipo e o valor e retorna true se ambas forem iguais
//if(A == B){ Ccmpara apenas os valores e retorna true se forem iguais

var n: number = 100;
var n1: number = 10;
if(n == n1){
    console.log("SÃO IGUAIS");
}
else{
    console.log("NÃO SÃO IGUAIS");
}

//----------------------------------------------------------------------------------------------------------------------

//CONCEITO DE UNDEFINED

var teste;
console.log("A VARIAVEL TEM NELA: " + teste);

//Definindo outro tipo para testar o undefined
type resultado = {
    a?: string | undefined;
    b?: boolean | undefined;
}

var teste2: resultado = {
    a: "dado de propriedade a",
    b: true
}
console.log(teste2);
teste2.b = undefined;
console.log(teste2);

//----------------------------------------------------------------------------------------------------------------------

//AUTENTICAÇÃO

//Possivel loading
type Credencial = {
    email: string;
    senha: string;
}

const cred1: Credencial = {
    email: "jhejhe@puccampinas.com",
    senha: "jhejhe123"
}
const cred2: Credencial = {
    email: "lolo@puccampinas.com",
    senha: "lolo123"
}
const admin: Credencial = {
    email: "admin@puccampinas",
    senha: "admin123"
}

function autenticarAdmin(c: Credencial):boolean {
    if((c.email === "admin@puccampinas") && (c.senha === "admin123")) {
        return true;
    } else {
        return false;
    }
}

var res1: boolean = autenticarAdmin(cred1);
console.log("LOGIN CREDENCIAL 1: " + res1);
var res2: boolean = autenticarAdmin(cred2);
console.log("LOGIN CREDENCIAL 2: " + res2);
var res3: boolean = autenticarAdmin(admin);
console.log("LOGIN CREDENCIAL admin: " + res3);

var credenciais: Credencial[] = [];
credenciais.push(cred1);
credenciais.push(cred2);
credenciais.push(admin);
console.log("SEGUNDA CREDENCIAL: "+ credenciais[1].email);

//----------------------------------------------------------------------------------------------------------------------
