/*
Todo backend precisa de um servidor para disponibilizar seus serviços.
O backend é um conjunto de serviços funcionais que rodam dentro de um servidor web.

Protocolo é um conjunto de regras e ferramentas para a comunicação entre computadores.
Para a internet funcionar, existem dois protocolos cruciais:
    1. TCP/IP: Transporta os dados de um ponto a outro, garantindo que os pacotes de dados sejam entregues corretamente.
    2. HTTP: Facilita a comunicação entre computadores com o objetivo de transportar dados na web.

Imagine dois computadores conectados diretamente por um único cabo de rede azul.
O computador A tem o endereço IP 192.168.0.1 e o computador B tem o endereço IP 192.168.0.2.

Se você transforma o computador A (ou o B) em um servidor HTTP, isso significa que:
    1. O computador A irá anunciar na rede que tem uma porta de conexão aberta, geralmente a porta 3000 para o backend.
    2. Outros computadores na rede, como o B, poderão fazer requisições ao servidor (computador A).
       Essas requisições correspondem a serviços, que são as rotas do backend.
    3. A comunicação entre o cliente (neste caso, B) e o servidor (neste caso, A) segue um princípio simples:
       B faz uma solicitação para A, A realiza a ação solicitada e devolve a resposta para B.
    4. Quem faz a solicitação é o cliente (B), quem realiza a ação é o servidor (A) e quem recebe a resposta (se houver) é o cliente (B).
*/

import http from "http";

const server = http.createServer((req,res)=>{
    res.writeHead(200,{'Content-Type':'text/plain'});
    res.end('OI SERVIDOR DA JHEJHE!!!');
});

server.listen(3000, ()=>{
    console.log("servidor rodando na porta 3000.")
});