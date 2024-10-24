# Plano-Inclinado-Arduino-
Projeto de releitura do Plano Inclinado de Galileu utilizando Arduino

Este projeto consiste numa releitura do clássico experimento de plano inclinado feito pelo astrônomo, físico e engenheiro italiano, Galileu Galilei.

O projeto tem como intuito automatizar a forma como o experimento feito por Galileu estudava o Movimento Retilíneo. Para isso, fez uso da platafomra Arduino juntamente com diversos sensores para cronometrar os instantes de tempo, juntamento com um software de planilhas, como o Excel, para tratamento dos dados e geração de gráficos.

Este algorítimo por sua vez possui uma estrutura de código bem simples porém bastante funcional, usando o básico já oferecido pela plataforma Arduino em sua IDE. Claro, necessita de um certo conhecimento de Linguagem de Programação, sobreutudo em C/C++, para melhor entendimento do código.

Materiais Necessários Obrigatórios:

  - Arduino Leonardo ou Compatível
  - Módulo Eletroímã
  - Sensor Infravermelho Reflexivo de Obstáculo HW-201
  - Protoboard
  - Led de Alto Brilho
  - Interruptor
  - Transistor Mosfet Canal N ou Transistor Bipolar NPN BC337 ou BC547
  - Fios
  - Fonte de 12V com no mínimo 1A de corrente
  - Bola de aço

Conhecimentos necessários:
  - Conhecimento Básico em Programação
  - Conhecimento some Montagem de Circuitos
  - Conhecimento sobre Gráficos no EXCEL

Conhecimentos Opcionais:
  - Conhecimento em Eletrônica: A fim de realizar uma montagem, utilizando componentes como diodos, capacitores etc, mais efetiva dos circuitos, como um circuito de proteção a inversão de polaridade ou corrente reversa no setor do eletroímã.
  - Conhecimento em C/C++: A fim de ser capaz de alterar, adaptar e melhorar o algorítmo para determinadas cenários.

Arduino Leonardo:
  - Semelhante ao Arduino UNO, esse modelo em específico possui a capacidade de emular teclado ou mouse, o que nos é muito útil para passarmos os dados obtidos no experimento direto para algum software de planilhas, como o Excel.

Eletroímã:
  - Altamente necessário pois ele é responsável por manter o móvel, no caso, a bola de aço, fixa enquanto o sistema não está em funcionamento e liberar a mesma quando o sistema for acionado. Pode ser facilmente construído em casa, utilizando prego ou qualquer outro material que pode ser usando como núcleo necessariamente ferromagnético, e fio de cobre esmaltado. Por ser um imã elétrico, é possível controlar quando ligar e desligá-lo.

Sensor Infravermelho Reflexivo de Obstáculo HW-201:
  - Como o prórpio nome diz, ele é o responsável por detectar se a bola de aço passo pela posição estipulada no trilho e, em conjunto com o Arduino, cronometrar o tempo no instante correto.

Protoboard:
  - A base de qualquer projeto eletrônico, ela é a responsável por comportar todo o circuito do projeto.

Led de Alto Brilho:
  - Indicador de que o sistema está ligado ou não.

Interruptor:
  - Responsável por ligar e desligar o sistema.

Transistor Mosfet Canal N ou Transistor Bipolar NPN:
  - Componenente eletrônico que pode ser utilizado como interruptor, ele será o responsável pelo chaveamento do eletroímã.

Fios:
  - Componente genérico para fazer as ligações eletrônicas.

Bola de Aço:
  - Corpo móvel do sistema.

Fonte de Energia:
  - Utilizada para alimentar todo o circuito, visto que a alimentação USB do computador não é o suficiente para um bom funcionamento do projeto. É recomendado uma fonte elétrica de 12V com no mínimo 1A de corrente. Pode ser usado fonte chaveada, fontes de computador etc, desde que obedeça às recomendações ditas anteriormente.
