#ottimizzazione_combinatoria #argomento_chiave 
# Maximum Flow
- Funzione obiettivo: Massimizzare i flussi
- Il problema può essere formalizzato come un problema di programmazione lineare
- Il grafo viene modificato in modo da seguire le caratteristiche del [[Rilassamento del problema del flusso]]
- Può essere ==risolto== tramite i [[Tagli nei flussi]]

### Vincoli
// TODO: aggiungi i vincoli

### Comparazione tra MF e MCF
Il problema MF può essere visto come un caso di [[Minimum Cost Flow (MCF)]]:
- I costi sono nulli
- gli sbilanciamenti sono nulli
- si aggiunge però un arco fittizio da t a s con costo -1 e capacità infinita.
