# Método de entrada ASCII para Arduino com potenciômetro

*Escrevi esse pequeno trecho de código em 2014 para um pequeno projeto como hobby, e nunca tinha publicado por aqui. Foi publicado na iMasters uma reprodução de um artigo meu pelo Vinícius Vieira (você pode encontrar o artigo na iMasters aqui: https://imasters.com.br/iot-makers/metodo-de-entrada-ascii-com-um-potenciometro-arduino). Vou reproduzir, portanto, o mesmo artigo na sequência aqui no README.*

Esse é um projeto de método de entrada de caracteres ASCII para o Arduino utilizando um potenciômetro para escolher o caractere. Esse projeto pode ser ainda mais simples, utilizando apenas um botão e um potenciômetro para inserir qualquer caractere da [tabela ASCII](https://pt.wikipedia.org/wiki/ASCII). Nesse aqui, no entanto, eu adicionei um botão para automaticamente inserir o caractere ESPAÇO, dividi a tabela ASCII em categorias (tipos) de caracteres e adicionei um botão para alternar entre essas/esses categorias/tipos, e ainda um terceiro botão que serve para apagar um caractere (ou, se pressionado por mais de meio segundo, toda a linha).

Esse método de entrada pode ser usado em substituição a um teclado para inserir pequenos grupos de caracteres, como para colocar senhas, por exemplo, em algum sistema de controle de acesso.

![Diagrama gerado no Fritzing](https://static.imasters.com.br/wp-content/uploads/2014/09/ascii_input_pot_bb1.jpg)

O diagrama do esquema que gerei com o [Fritzing](https://fritzing.org/home/). Os botões do tipo “pushbutton” estão na ordem: `sel_tipo`, `inserir`, `espaco`, `apagar` (ver comentários do código). O display LCD está com um brilho fixo através do resistor de 1k no terceiro pino, caso queira colocar um potenciômetro para ajuste, sem problemas! Consulte a [página do Arduino sobre isso](https://www.arduino.cc/en/Tutorial/HelloWorld?from=Tutorial.LiquidCrystal), caso tenha dúvida.

O vídeo de demonstração pode ser encontrado [aqui](https://www.youtube.com/watch?v=FWakYQKqKxY&feature=emb_logo). Nele aparecem alguns componentes (resistor e LM7805 – tinha mais um LED, mas tirei pra fazer o vídeo) que adicionei para fazer o projeto funcionar fora da porta USB – que está servindo para alimentar o circuito com 5V -, alimentando com uma bateria de 7.4 V sucateada de um tablet.




