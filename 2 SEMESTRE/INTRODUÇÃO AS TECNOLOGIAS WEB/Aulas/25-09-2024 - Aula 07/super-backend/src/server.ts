import express from 'express'; //IMPORTA O EXPRESS, UTILIZADO PARA CRIAR SERVIDORES WEB E GERIR ROTAS.
import { Router, Request, Response } from 'express';
/*
IMPORTA ROUTER PARA CRIAR E LIDAR COM ROTAS,
REQUEST PARA LIDAR COM REQUISIÇÕES HTTP,
RESPONSE PARA LIDAR COM RESPOSTAS HTTP.
*/

const app = express(); //('app') SERÁ USADO PARA CONFIGURAR O SERVIDOR E GERIR COMO REAGE A DIFERENTES REQUISIÇÕES.
const route = Router(); //A PARTIR DO ('Router') CRIA O ('route') QUE É USADO PARA LIDAR COM AS ROTAS DO SERVIDOR.
const port = 6000; //DEFINE A PORTA ('port') EM QUE O SERVIDOR VAI RODAR. NESTE CASO, A PORTA 6000.

app.use(express.json()); //PARA PROCESSAR REQUISIÇÕES COM DADOS JSON (PERMITINDO A LIDAR COM CONTEÚDO DO BODY DA REQUISIÇÃO).

type Conta = { //ESTRUTURA DO TIPO PERSONALIZADO ('Conta')
    nome: string;
    email: string;
    cpf: string;
    senha: string;
}

let contas: Conta[] = []; //ARRAY ('contas') QUE GUARDARÁ AS INFORMAÇÕES DO TIPO ('Conta')

function cadastarConta(conta: Conta): number { //FUNÇÃO QUE INSERE A CONTA DO USUÁRIO NA ARRAY ('contas')
    contas.push(conta); //INSERE A CONTA NO ARRAY (CADASTRANDO...)
    return contas.length; //RETORNA O TAMANHO DA ARRAY PARA SER USADA COMO CONTADOR DE CONTAS CADASTRADAS ('codConta')
}

route.put('/signUp', (req: Request, res: Response) => {
    //OBTÉM OS VALORES DO HEADER ('nome', 'cpf', 'email', 'senha') ENVIADOS NA REQUISIÇÃO HTTP
    const Pnome = req.get('nome');
    const Pcpf = req.get('cpf');
    const Pemail = req.get('email');
    const Psenha = req.get('senha');
    //VERIFICAÇÃO SE TODOS OS PARÂMETROS FORAM INSERIDOS
    if (Pnome && Pcpf && Pemail && Psenha) {
        //CRIA O OBJETO ('novaConta') PARA GUARDAR OS VALORES RECEBIDOS
        const novaConta: Conta = {
            nome: Pnome,
            cpf: Pcpf,
            email: Pemail,
            senha: Psenha,
        };
        //CHAMA A FUNÇÃO PARA CADASTRAR A CONTA ('novaConta') E RETORNAR O ('codConta') PARA USAR COMO CÓDIGO OU QUANTIDADE DE CADASTROS
        const codConta = cadastarConta(novaConta);
        //ENVIA UMA RESPOSTA AO USUÁRIO CONFIRMANDO O CADASTRO E INFORMANDO O CÓDIGO DA CONTA
        res.send(`Nova conta adicionada ${codConta}`);
    }
    //SE ALGUM DOS PARÂMETROS ESTIVER FALTANDO ('nome', 'cpf', 'email', 'senha')
    else {
        res.send('Faltam parâmetros na requisição');
    }
});

app.use(route); //DEFINE QUE ('app') USARÁ AS ROTAS CONFIGURADAS EM ('route')
app.listen(port, () => console.log(`Servidor rodando na porta: ${port}`)); //INICIA O SERVIDOR NA PORTA DEFINIDA EM ('port')
