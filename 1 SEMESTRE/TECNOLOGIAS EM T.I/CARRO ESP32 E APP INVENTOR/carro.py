import network
from machine import Pin, PWM
from micropyserver import MicroPyServer
# Configuração dos pinos do motor direito
motor_direito_pino1 = Pin(2, Pin.OUT)
motor_direito_pino2 = Pin(15, Pin.OUT)
motor_direito_pwm = PWM(Pin(16), freq=1000)
# Configuração dos pinos do motor esquerdo
motor_esquerdo_pino1 = Pin(0, Pin.OUT)
motor_esquerdo_pino2 = Pin(4, Pin.OUT)
motor_esquerdo_pwm = PWM(Pin(17), freq=1000)
# Configuração da rede Wi-Fi
ssid = 'PUC-ACD'
password = ''

station = network.WLAN(network.STA_IF)
station.active(True)
station.connect(ssid, password)

while not station.isconnected():
    pass

print('Conectado à rede', ssid)
print('Configuração de rede:', station.ifconfig())

# Funções para controlar os motores
def motor_direito(sentido, velocidade):
    if sentido == 'horario':
        motor_direito_pino1.on()
        motor_direito_pino2.off()
    elif sentido == 'anti-horario':
        motor_direito_pino1.off()
        motor_direito_pino2.on()
    else:
        motor_direito_pino1.off()
        motor_direito_pino2.off()
    motor_direito_pwm.duty(velocidade)
def motor_esquerdo(sentido, velocidade):
    if sentido == 'horario':
        motor_esquerdo_pino1.off()
        motor_esquerdo_pino2.on()
    elif sentido == 'anti-horario':
        motor_esquerdo_pino1.on()
        motor_esquerdo_pino2.off()
    else:
        motor_esquerdo_pino1.off()
        motor_esquerdo_pino2.off()
    motor_esquerdo_pwm.duty(velocidade)

# Página HTML para controle
html = """<!DOCTYPE html><html><head>
<title>Controle do Carrinho</title></head>
<body><h1>Controle do Carrinho</h1></body></html>
"""

def index(request):
    app.send(html)

def direita(request):
    print('direita')
    motor_direito('horario', 950)
    motor_esquerdo('parar', 950)
    resp = """<html><head><title>Controle do Carrinho</title></head><body>
                  <h1>Direita</h1></body></html>"""
    app.send(resp)
    
def esquerda(request):
    print('esquerda')
    motor_esquerdo('horario', 950)
    motor_direito('parar', 0)
    resp = """<html><head><title>Controle do Carrinho</title></head><body>
                  <h1>Esquerda</h1></body></html>"""
    app.send(resp)

def parar(request):
    print('parar')
    motor_direito('parar', 0)
    motor_esquerdo('parar', 0)
    resp = """<html><head><title>Controle do Carrinho</title></head><body>
                  <h1>Parar</h1></body></html>"""
    app.send(resp)
    
def frente(request):
    print('frente')
    motor_direito('horario', 950)
    motor_esquerdo('horario', 950)
    resp = """<html><head><title>Controle do Carrinho</title></head><body>
                  <h1>Frente</h1></body></html>"""
    app.send(resp)
    
def re(request):
    print('ré')
    motor_direito('anti-horario', 950)
    motor_esquerdo('anti-horario', 950)
    resp = """<html><head><title>Controle do Carrinho</title></head><body>
                  <h1>Ré</h1></body></html>"""
    app.send(resp)

app = MicroPyServer()
app.add_route("/", index)
app.add_route("/dir", direita)
app.add_route("/parar", parar)
app.add_route("/esq", esquerda)
app.add_route("/frente", frente)
app.add_route("/re", re)

app.start()
