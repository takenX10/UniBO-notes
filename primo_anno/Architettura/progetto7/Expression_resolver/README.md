# Expression Resolver
___
> Author: Alessandro Frau

>TL;DR: Un programma che risolve espressioni intere
### Descrizione:
___
Il programma ti permette di risolvere espressioni intere, riconosce i seguenti simboli:

- \+
- \-
- \*
- /
- %
- (
- )
- =
- 0-9

>Il resto dei simboli vengono ignorati e non generano errori.

>Vengono riconosciuti solo i numeri interi positivi, quelli negativi possono essere espressi come sottrazioni ma non possono essere scritti direttamente nell'espressione

>La divisione restituisce la parte intera del quoziente della divisione tra i due operandi

>Tutti i simboli hanno associativita' a sinistra, quindi per esempio scrivere `1/1*2` e' la stessa cosa di scrivere `(1/1)*2`

>Le divisioni per 0 generano un errore e necessitano il riavvio del programma

>Nessun operando ha priorita' su un altro, vengono calcolati in ordine di come vengono scritti.

**esempio per chiarimento:**
`(6*5) + 5 * (3+3)` 
- In matematica ordinaria e' `=60` perche' corrisponde a scrivere: `(6 * 5) + (5 * (3 + 3))`

- In Expression Resolver e' `=210` perche' corrisponde a scrivere: `((6 * 5) + 5) * (3 + 3)`

### Utilizzo:
___

Sono presenti due versioni, il programma in c e il codice vm, una volta eseguiti il funzionamento e' identico, i codici non sono esattamente uguali ma si somigliano molto.
Per eseguire correttamente il programma si devono seguire i seguenti passaggi:
- attendere la scritta `ESPRESSIONE: `
- scrivere l'espressione desiderata
- inserire un uguale
- il programma restituira' la soluzione
- premere invio per continuare, chiudere il programma altrimenti
