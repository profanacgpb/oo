#atividade POO - Escolha: Carro

class Carro:
    def __init__(self, marca, cor, ano):
        self.marca = marca
        self.cor = cor
        self.ano = ano

    def exibir_informacoes(self):
        print(f"Marca: {self.marca}")
        print(f"Cor: {self.cor}")
        print(f"Ano: {self.ano}")

    def atualizar_marca(self, nova_marca):
        self.marca = nova_marca
        print(f"Marca Atualizada no sistema: {self.marca}")

    def calcular_idade_carro(self, ano_atual):
        self.ano_atual = ano_atual
        print(f"A idade do carro é: {ano_atual - self.ano}")

carro1 = Carro("Mercedes", "Cinza", 2005)
carro2 = Carro("Chevrolet", "Azul", 2008)

carro1.exibir_informacoes()
carro2.exibir_informacoes()

carro1.atualizar_marca("BMW")
carro2.atualizar_marca("Ford")

carro1.calcular_idade_carro(2026)
carro2.calcular_idade_carro(2026)