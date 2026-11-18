
# Criando a classe Carro
class Carro:

    # Construtor que recebe os atributos
    def __init__(self, marca, modelo, ano, velocidade):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.velocidade = velocidade

    # Método para aumentar a velocidade
    def acelerar(self):
        self.velocidade += 10

    # Método para diminuir a velocidade
    def frear(self):
        self.velocidade = max(0, self.velocidade - 10)

    # Método para mostrar o estado do carro
    def mostrar_estado(self):
        print("Marca:", self.marca)
        print("Modelo:", self.modelo)
        print("Ano:", self.ano)
        print("Velocidade:", self.velocidade, "km/h")
        print("------------------------")


# Criando três objetos diferentes
carro1 = Carro("Toyota", "Corolla", 2022, 60)
carro2 = Carro("Honda", "Civic", 2023, 80)
carro3 = Carro("Fiat", "Argo", 2021, 40)

# Testando os métodos
carro1.acelerar() 
carro2.frear()     

# Imprimindo o estado dos três carros
carro1.mostrar_estado()
carro2.mostrar_estado()
carro3.mostrar_estado()
