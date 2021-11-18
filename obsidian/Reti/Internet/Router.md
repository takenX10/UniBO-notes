#reti 
# Router
> Dispositivi creati per smistare e distribuire pacchetti nel modo corretto.

**ROUTING** => Decidere DOVE deve andare il pacchetto, e mandarlo
**FORWARDING** => Inoltrare il pacchetto appena arrivato.

Il router compie sia azioni di routing sia quelle di forwarding.

- Gestiscono il routing tramite le [[Tabella di instradamento]] e gli [[Algoritmi di routing]]
-  Uno dei compiti del router è quello di capire se il pacchetto è destinato alla rete locale o a internet

> In pratica il router OGNI TANTO contribuisce al routing, ovvero a calcolare e migliorare la strada da percorrere del pacchetto, mentre le altre volte inoltra semplicemente il pacchetto al prossimo nodo. Questo avviene perchè non tutti i router hanno tabelle di instradamento identiche, quindi può succedere che router diversi calcolino percorsi diversi.

- Identifica il nome della propria rete locale tramite il suo [[Protocollo IP]]
- 