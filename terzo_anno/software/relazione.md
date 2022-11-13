# Relazione TDD

## Dati

- Nome e cognome: `Alessandro Frau`
- Matricola: `0000971546`
- Persona con cui ho fatto PP: `Gianmaria Rovelli`

## Pair programming

Non e' la prima volta che faccio pair programming, mi e' capitato di lavorare ad altri progetti universitari con alcuni colleghi nella stessa modalita'. Penso che sia un attivita' abbastanza utile, soprattutto quando si deve lavorare sullo stessa parte del codice; personalmente non lo abbinerei al TDD dato che gli `unit test` si possono separare bene, dunque si puo velocizzare il processo facendo programmare unita diverse ai programmatori invece di farli lavorare sulla stessa. Intendo sicuramente continuare ad utilizzarlo durante il progetto, soprattutto nelle fasi di refactoring.

## Unit test automatici

Trovo che gli unit test siano estremamente utili allo sviluppo del codice, delineano molto bene cosa effettivamente si deve implementare e fanno risparmiare al programmatore tanto codice che alla fine risulta inutile. Continueremo ad utilizzarli nel codice del progetto.

## Test driven development

Per quanto la collaborazione tra me e Gianmaria sia stata estremamente positiva, penso che la dimostrazione non mi abbia convinto particolarmente, probabilmente perche' il codice di sviluppo era effettivamente estremamente breve; non metto in dubbio l'utilita di questo processo di sviluppo in progetti effettivamente piu lunghi e complessi, ma in questo caso mi e' sembrato superfluo. Sicuramente ha la potenzialita di permettere di delineare meglio le specifiche di un progetto per il programmatore e di vedere in anticipo le varie problematiche che puo incontrare durante lo sviluppo, infatti per queste motivazioni non escludo di utilizzarlo in futuro.

## File di testing

Abbiamo implementato il file di test in java, creando un file `Calculator.java` dove abbiamo implementato il metodo `calculate`, e un file `CalculatorTest.java` dove abbiamo implementato il test:

```java
// CalculatorTest.java
import static org.junit.Assert.assertEquals;
import org.junit.Test;
import Calculator;

public class calculatorTest {

    @Test
    public void testCalculator(){
        assertEquals(2, Calculator.calculate("1,1"));
        assertEquals(11, Calculator.calculate("11"));
        assertEquals(2, Calculator.calculate(" 1,1"));
        assertEquals(2, Calculator.calculate("1,1 "));
        assertEquals(0, Calculator.calculate(",1,1"));
        assertEquals(2, Calculator.calculate("1,1,"));
        assertEquals(3, Calculator.calculate("1,1,1"));
        assertEquals(0, Calculator.calculate(","));
        assertEquals(0, Calculator.calculate(""));
        assertEquals(0, Calculator.calculate("11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111,1"));
        assertEquals(2, Calculator.calculate("001,1"));
        assertEquals(10, Calculator.calculate("9,1"));
        assertEquals(0, Calculator.calculate("1, 1,1"));
        assertEquals(0, Calculator.calculate(" 1, ,1"));
        assertEquals(0, Calculator.calculate("a"));
        assertEquals(0, Calculator.calculate("1,a"));
        assertEquals(0, Calculator.calculate("a,1"));
        assertEquals(0, Calculator.calculate("1,a,1"));
        assertEquals(0, Calculator.calculate("a1a,1"));
        assertEquals(0, Calculator.calculate("a,a"));
    }    
}
```