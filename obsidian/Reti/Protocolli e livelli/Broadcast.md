#reti 
# Broadcast
Segnale generato che ha l'obbiettivo di arrivare a tutte le reti

Non rimanda l' acknowledgement, quindi non può essere un metodo totalmente affidabile.
Per avere un Broadcast/multicast affidabile l'unico modo è iterare un unicast per ogni Mac della rete, quindi si ha un ritardo dato dal ricevere l'acknowledgement per ogni richiesta

- Nei [[MAC Address]] è rappresentato da FF:FF:FF:FF:FF:FF
- Negli [[IPv4]] è rappresentato da 255.255.255.0 