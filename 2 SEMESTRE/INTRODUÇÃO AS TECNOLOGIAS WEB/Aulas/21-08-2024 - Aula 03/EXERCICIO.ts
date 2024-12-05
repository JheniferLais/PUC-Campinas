//----------------------------------------------------------------------------------------------------------------------

/*
EXERCÍCIO LOGIN

Crie dois arrays chamados `credenciaisValidas` e `credenciaisBloqueadas`.

1. Adicione um total de 10 credenciais válidas no array `credenciaisValidas`.
2. Adicione um total de 10 credenciais bloqueadas no array `credenciaisBloqueadas`.

Crie uma função chamada `autenticar` que receba uma credencial qualquer como parâmetro.
Esta função deve comparar a credencial recebida com as credenciais presentes nos dois arrays.

- Se a credencial não estiver em nenhum dos arrays, deve retornar a mensagem "Credencial inválida".
- Se a credencial estiver no array de bloqueadas, deve retornar a mensagem "Credencial bloqueada".
- Caso contrário, se a credencial estiver no array de válidas, deve retornar a mensagem "Login feito com sucesso".
*/

//----------------------------------------------------------------------------------------------------------------------

//CRIANDO O TIPO CREDENCIAL

type Credencial = {
    email: string;
    senha: string;
}

//----------------------------------------------------------------------------------------------------------------------

//CRIANDO AS ARRAYS

var credenciaisValidas: Credencial[] = [];
var credenciaisBloqueadas: Credencial[] = [];

//----------------------------------------------------------------------------------------------------------------------

//CRIANDO 20 CREDENCIAS

const credI: Credencial = {
    email: "joao.silva@puc.com",
    senha: "a1B2c3D4"
};
const credII: Credencial = {
    email: "maria.santos@puc.com",
    senha: "x9Z8y7T6"
};
const cred3: Credencial = {
    email: "carlos.lima@puc.com",
    senha: "QwErTy123"
};
const cred4: Credencial = {
    email: "ana.souza@puc.com",
    senha: "P4s5w0rD"
};
const cred5: Credencial = {
    email: "pedro.almeida@puc.com",
    senha: "M1nH4s3nh4"
};
const cred6: Credencial = {
    email: "lucas.pereira@puc.com",
    senha: "R8f7g6B5"
};
const cred7: Credencial = {
    email: "fernanda.costa@puc.com",
    senha: "JkLmNo456"
};
const cred8: Credencial = {
    email: "bruno.oliveira@puc.com",
    senha: "W2r3Ty5z"
};
const cred9: Credencial = {
    email: "juliana.rodrigues@puc.com",
    senha: "AzErTy678"
};
const cred10: Credencial = {
    email: "rafael.gomes@puc.com",
    senha: "S1t2r3p4"
};
const cred11: Credencial = {
    email: "gabriel.martins@puc.com",
    senha: "ZxCvB123"
};
const cred12: Credencial = {
    email: "laura.fernandes@puc.com",
    senha: "M2y4Qw7L"
};
const cred13: Credencial = {
    email: "rodrigo.cardoso@puc.com",
    senha: "K6l3Xp9T"
};
const cred14: Credencial = {
    email: "carla.ribeiro@puc.com",
    senha: "H4u7Bv3Q"
};
const cred15: Credencial = {
    email: "vinicius.moura@puc.com",
    senha: "F5j9Kr1S"
};
const cred16: Credencial = {
    email: "paula.araujo@puc.com",
    senha: "C8o6Pq4W"
};
const cred17: Credencial = {
    email: "andre.melo@puc.com",
    senha: "L9u3Mn6B"
};
const cred18: Credencial = {
    email: "renata.dias@puc.com",
    senha: "X1r5Vu8Y"
};
const cred19: Credencial = {
    email: "diego.sousa@puc.com",
    senha: "V7r4Zb2A"
};
const cred20: Credencial = {
    email: "isabela.barbosa@puc.com",
    senha: "J3y9Tp5N"
};

//----------------------------------------------------------------------------------------------------------------------

//ADICIONANDO 10 CREDENCIAIS AS VALIDAS E 10 AS BLOQUEADAS

credenciaisValidas.push(credI,credII,cred3,cred4,cred5,cred6,cred7,cred8,cred9,cred10);
credenciaisBloqueadas.push(cred11,cred12,cred13,cred14,cred15,cred16,cred17,cred18,cred19,cred20);

//----------------------------------------------------------------------------------------------------------------------

//FUNÇÃO PARA AUTENTICACAO

function autenticar(c: Credencial): string {

    for (let i = 0; i < credenciaisValidas.length; i++) {
        if (credenciaisValidas[i].email === c.email && credenciaisValidas[i].senha === c.senha) {
            return "LOGIN FEITO COM SUCESSO!!!";
        }
    }
    for (let i = 0; i < credenciaisBloqueadas.length; i++) {
        if (credenciaisBloqueadas[i].email === c.email && credenciaisBloqueadas[i].senha === c.senha) {
            return "CREDENCIAL BLOQUEADA!!!";
        }
    }
    return "CREDENCIAL INVÁLIDA!!!";
}

//----------------------------------------------------------------------------------------------------------------------

//TESTE

const credencialTeste: Credencial = {
    email: "joao.silva@puc.com",
    senha: "a1B2c3D4"
};
console.log(autenticar(credencialTeste));

//----------------------------------------------------------------------------------------------------------------------