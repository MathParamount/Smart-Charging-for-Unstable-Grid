CORE:
Inicialmente em safety supervisor eu acabei colocando verificações muito aprofundadas na fsm para a tensão dando valores imaginários da minha cabeça para tensão, nível da bateria e tempo e acabou complicando muito. Só que nessa parte é simplesmente para implementar os sinais de crítico, instável ou rede disponível. Também criei uma variável a mais para guardar a condição da rede com: parameter int grid_status;

Eu tinha dificultado muito o arquivo safety no core, pois coloquei mais entradas e saídas do que deveria. Frisando o zero cross, grid voltage, grid current neste arquivo de forma desnecessária. Aprendi que o safety não liga ou desliga relé, mas autoriza ou bloqueia.
Eu tive que criar uma nova pasta para classificação da rede com os sinais de corrente e tensão da rede fazendo uma média móvel.

Eu tentei criar um arquivo para cálculo de adc com systemverilog, mas eu percebi que isso levava dependência circular e tentei sem perceber trocar o papel do machine learning para detectar a tensão e corrente da rede e prever isso. Eu acabei gerando um histórico da corrente para cálculo de máximo e mínimo. O que também não faz sentido. Logo, eu precisei deletar o arquivo.

Eu criei uma interface para conectar a fsm ao sistema. A lógica de conexão que eu pensei foi assim: fsm -> safety -> classify.

No debug eu tive erros em diferença de nome de arquivo e módulo. Afinal, o módulo dizia algo, mas o arquivo dizia outra coisa. Também o Verilator ele usa o nome do arquivo para debug, rastreamento e geração de C++.
Assim, aprendi que o nome do arquivo deve ter o mesmo nome do módulo para debug e geração de wave com verilator.

Eu tive erro na definição de sinais com current_state e fault_flag dentro do parâmetro do testbench wrapper.

Eu declarei next_state como logic [N:0] next_state. O que não faz sentido porque 
o next_state tem que ser declarado do mesmo tipo que current_state que é do tipo state_t.

Eu preferi seguir a modularidade e simplificação chamando a interface no parâmetro do sc_safety e no sc_fsm, assim, reduzindo 4 sinais em apenas 1.

Eu aprendi que devo evitar usar assign em sinais de interface, pois fica muito mais difícil de debugar e cria diversos drivers contínuos.
Também eu entendi que o package deve ser importado dentro do module ou interface e nunca no topo do arquivo.

Eu tive que separar o charge_enable vindo da FSM da saída do safety para evitar erros.

Eu tive que trocar o tipo do grid_state no sc_dut, porque o arquivo dut ou TOP não aceita enum, typedef, interface. Isso só aceita logic, wire,bit, array.
Assim, eu tive que alterar input logic grid_state -> input logic [1:0] grid_state;

Foi decidido em o safety não gerar o sinal de charge_enable ou ativação de relé. O responsável por isso foi dado apenas a FSM. Isso ajuda em debug.

Os sinais não estão sendo estimulados. Assim, urge a estimulação dos sinais para teste criando as covariáveis no sc_top para depois usar no sim_run_tb.cpp. Essa lógica funciona porque a fsm gera os sinais e define o estado e o safety só observa e leva 2 sinais. 
Eu percebi que isso que estou tentando fazer vai poluir o RTL e gerar vários warnings. Logo eu vou retirar tudo isso e estimular os sinais manualmente mesmo para teste.

Eu tive warning acerca de: %Warning-UNUSEDSIGNAL: rtl/interface/sc_interface_if.sv:10:11: Signal is not used: 'fault_flag' : ... note: In instance 'sc_dut.u_safety' 10 | logic fault_flag.
Eu entendi que a causa raiz era devido aos 2 always_comb em série que causa esse problema de sinal.

Eu aprendi que todos os assertions devem estar dentro de um módulo ou interface e nunca solto no arquivo.

Eu percebi um erro que tinha feito dentro do arquivo wrapper, em que eu declarei a mesma interface 2 vezes. como: /*sc_interface_if sc_fsm_bus(); e sc_interface_if s#include "Vsc_dut.h"
c_safety_bus(); */
Isso estar errado porque ambos os modports estar no mesmo arquivo de interface. Logo só basta 1 declaração e dentro da instância do dut faz um .modport_name.

GRID_MONITOR:

É válido o  parameter logic signed [15:0] MAX_CURRENT_ADC  = 2048. Afinal, eu estou fazendo 1 LSB = 1 mA. Logo, é 2.048 A.

O cálculo do valor do ADC foi obtido com: Valor_ADC = (Tensão_mV / 3300) * 65535.

Eu estive tendo um erro persistente durante o código de filtragem no grid_monitor que foi o seguinte:
filter_volt <= (
            grid_bus.grid_voltage_adc +
            voltage_history[0] +
            voltage_history[1] +
            voltage_history[2]
        ) >> 2;
	
	// shift register
        voltage_history[3] <= voltage_history[2];
        voltage_history[2] <= voltage_history[1];
        voltage_history[1] <= voltage_history[0];
        voltage_history[0] <= grid_bus.grid_voltage_adc;
        
não houve uma explicação clara do por que estar dando erro se a lógica parece certa.


CPP:
Eu estava tentando fazer um waveform dinâmico, em que obedecesse todos os comandos especificados no arquivo cpp. Contudo, não estava respondendo os comandos. Assim, eu vi que a função tick(VerilatedVcdC* pointer, Vsc_dut* top) estava incompleta. Em que eu estimulava o clock e usava o top->eval(), mas não alterava no waveform deixando isso estático. Assim, eu aprendi a fazer um dump (exibir no waveform): pointer -> dump(main_t*10); antes de mudar o clock duas vezes e usar o eval(). Assim, o dump foi usado no início e fim do tick().

Eu inicializei os sinais internos do sistema antes do loop de teste com as ativações artificiais. Também, eu fiz todos os testes dentro do intervalo de 50 termos do main_t. Antes eu incrementava o main_t na main, mas isso é ineficiente, assim, eu troquei para um dentro do tick e deixando os testes forçados para o main.

Eu tive erro de dump antecipando o clock usando o primeiro dump após o clock ir a zero, dando o erro:
%Warning: previous dump at t=505, requesting t=500, dump call ignored.

C-Script integration:
Eu necessito de traduzir o sim_main.cpp para um código c-script que roda dentro do Plecs para fazer uma simulação analógico-digital. Contudo, o c-script não aceita includes nem comandos vindo de headers para verilated. Assim, urge fazer co-integração via DLL entre o sim_main.cpp e o c-script.

Primeiramente, eu criei um novo arquivo similar ao sim_main para rodar o DLL para o Plecs.
Eu aprendi que em C-script não existe argc, argv reais. Logo pode tirar ou comentar onde tem isso. Além disso, o fluxo de desenvolvimento que estou tentando criar e compilar é chamado: co simulação FMI/AMS.

Eu entendi que o Plecs não entende loop de clock manual e que o Cout não é visível no Plecs. Assim, eu tive que ajustar quase todo o código em C++ para C-script.

Eu adicionei um arquivo de bash para a compilação do DLL no projeto para compatibilidade com o Plecs. Invés de usar o bloco c-script basta chamar o bloco DLL.
Para isso eu adicionei:   --lib-create new_dut \ abaixo do --assert \ no bash. Também no final eu inseri o tb_wrapper/sc_dut.sv \ .
Isso gera um diretório chamado obj_dir que há os arquivos .so para o dll.

ML:

Eu fiz um modelo simples de regressão linear com machine learning com dados públicos tirados do kaggle para análise de voltage da rede. Os dados foram capturados e filtrados com box-cox que é uma técnica de filtro para transformar dados não-normais em dados mais próximo da normal(gaussiana) e estabilizar variância.
O resultado inicial foi um lambda de -0.419, que revela maior assimetria dos dados para o lado direito da calda da distribuição.

No meu modelo inicial há um overfitting evidente com score r² de treino e teste de 1. Isso na prática significa uma previsão 100% perfeita. O que não faz sentido. Então um simples train_test_split não resolve, pois isso tem normalmente o shuffle ativo, que é a junção de dados futuros com atual. Andei pesquisando e um split temporal tende a amenizar esse problema. Afinal, a rede elétrica é um modelo estocástico(aleatório).

Eu percebi que o modelo tinha erro de visualização do target antes mesmo de definir fazer a previsão. O problema foi concertado e foi alcançado uma acurácia de 97.7% com um resíduo médio de -0.0588. Assim, o modelo tem viés sistemático muito baixo prevendo valores ligeiramente acima de forma não significativa ou preocupante, nem problema de vazamento de dados, considerando os dados de input no sistema.

Eu percebi que estava misturando muita coisa no arquivo principal chamado regression. Afinal, boa parte do código ficou em criação de algoritmo para a regressão do modelo e outra parte ficou como verificação dos dados para correção de bugs e ajustes do modelo.
Assim, eu decidi criar um arquivo novo que herda do arquivo anterior(regression) todos os dados para somente verificação.
Eu fiz uma plotagem da tensão x tempo e previsão x tempo, mas a plotagem ficou muito difícil a análise, pois o timestamp que peguei era praticamente todo o intervalo. O que dificultou a análise do tempo no eixo.
Assim, invés de fazer: ax1.plot(v_f.df_new["Timestamp"][:len(reg_f.prediction)],reg_f.prediction); eu tentei criar um step para pegar 1/5 da amostragem do tempo.

No modelo de regressão eu fiz uma análise de todos os valores do array comparando com o menor e maior valor crítico e instável do adc que foi definido usando: .values[:,None]. Assim, verificando se qualquer valor corresponder a condição dada isso levanta sinais e gera a condição. A razão de adição de nova dimensão foi para criação de broadcasting em operação vetorizada.

# Overview
  


# Architecture

# Observations

# Conclusion
